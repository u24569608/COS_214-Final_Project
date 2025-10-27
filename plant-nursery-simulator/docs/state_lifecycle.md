# Plant Lifecycle State Machine

This document describes the lifecycle state machine implemented for `PlantInstance`.

## Overview

Each `PlantInstance` owns a polymorphic `PlantState` responsible for reacting to watering, fertilising and tick events. The configured strategies are invoked through the state layer, allowing behaviour that adapts as the plant progresses through its lifecycle.

Key states:

- **Seed** - freshly planted specimen just after germination.
- **Growing** - healthy plant actively gaining vitality.
- **Mature** - fully grown plant ready for sale.
- **Withering** - stressed plant that requires immediate care.
- **Dead** - terminal state; the plant can no longer recover.

Transitions are driven by the plant's health, water and nutrient levels. Constants describing the thresholds live in `include/PlantStateThresholds.h` and are reused across states to keep behaviour consistent.

## Shared Concepts

- **Water Strategy & Fertilize Strategy** - state methods call `PlantInstance::applyWaterStrategy()` and `PlantInstance::applyFertilizeStrategy()` to execute the currently configured strategies. When a state transition occurs during a care action, the action is replayed on the new state exactly once; the `PlantInstance::isReplayingAction()` guard prevents duplicate strategy invocations.
- **Resource Stress** - water below `kWitheringWaterThreshold` or nutrients below `kWitheringNutrientThreshold` will push the plant towards the Withering track or reduce health during ticks.
- **Recovery** - water and nutrients at or above the seed-to-growing thresholds, together with adequate health, allow the plant to recover from Withering.
- **Observer Notifications** - `PlantInstance` inherits from `Subject` and issues observer events when availability changes (entering or leaving the Mature state) and when care is required (Withering transitions or resource depletion after ticks). Inventory items (`StockItem`) and staff subscribers react to these broadcasts to keep the UI and task queues in sync.

Helper utilities in `include/PlantStateUtils.h` centralise checks such as `isDead`, `meetsSeedToGrowingRequirements`, `meetsGrowingToMatureRequirements`, and `hasRecoveredResources`.

## State Behaviour

### Seed State

File: `src/SeedState.cpp`

- **Water / Fertilise** - increase water by 20, nutrients by 18 respectively, and boost health (+4 for water, +3 for nutrients). Strategies are triggered unless the action is a replay.
- **Tick** - applies `penaliseForLowResources`. Health increases slightly when resources are healthy, drops moderately if either resource is low, and drops heavily if both are low.
- **Transitions**
  - To **Growing**: water ≥ `kSeedToGrowingWater`, nutrients ≥ `kSeedToGrowingNutrients`, and health ≥ `kSeedToGrowingHealth`.
  - To **Dead**: health ≤ `kDeadHealthThreshold`.

### Growing State

File: `src/GrowingState.cpp`

- **Water / Fertilise** - apply configured strategies and adjust health (+3) alongside the specific resource (water or nutrient +18).
- **Tick** - if resources are stressed the plant loses 7 health; otherwise it gains 2.
- **Transitions**
  - To **Withering**: resource stress (water < `kWitheringWaterThreshold` or nutrients < `kWitheringNutrientThreshold`).
  - To **Mature**: meets growing-to-mature thresholds for water, nutrients and health.
  - To **Dead**: health ≤ `kDeadHealthThreshold`.

### Mature State

File: `src/MatureState.cpp`

- **Water / Fertilise** - apply strategy, add 12 to the relevant resource, increase health by 1.
- **Tick** - health declines slightly (−1) when resources are adequate, and sharply (−6) under stress.
- **Transitions**
  - To **Withering**: resource stress or health < `kMatureHealthFloor`.
  - To **Dead**: health ≤ `kDeadHealthThreshold`.

### Withering State

File: `src/WitheringState.cpp`

- **Water / Fertilise** - rehydrate/refuel with +22 resource adjustments and health boosts (+5 on water, +4 on fertilise).
- **Tick** - health degrades by 6 each cycle until rescued or dead.
- **Transitions**
  - To **Dead**: health ≤ `kWitheringCriticalHealth` or overall health ≤ `kDeadHealthThreshold`.
  - To **Mature**: meets growing-to-mature thresholds.
  - To **Growing**: water and nutrients have recovered (at least seed thresholds) and health ≥ `kWitheringRecoveryHealth`.

### Dead State

File: `src/DeadState.cpp`

- All actions are no-ops. Once dead, the plant remains dead.

## Promotion Replays

When an action causes a state transition (for example, fertilising a healthy seed that immediately satisfies the growing thresholds), `PlantInstance::performWater()` and `performFertilize()` detect the state change and replay the same event on the new state exactly once. This guarantees that the new state's behaviour runs without doubling the strategy effects.

## Health Adjustments

- Setter methods clamp water, nutrients and health between 0 and 100.
- Positive deltas are designed to stack with strategy effects; the tests in `tests/plant_state_test.cpp` validate that strategies run once per requested action even across promotions.

## Testing

`tests/plant_state_test.cpp` covers:

- Full lifecycle from Seed → Growing → Mature → Withering → Dead.
- Idempotent care in the Mature state.
- Promotion replay correctness (Seed fertilise promotion).
- Recovery from Withering back to Growing/Mature with water and fertiliser.

Running `make plant_state_unit_test` or the umbrella `make test` executes these checks.
