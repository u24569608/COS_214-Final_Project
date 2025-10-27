# Memory Management - State/Plant Lifecycle

`PlantInstance` owns its lifecycle state via `std::unique_ptr<PlantState>`. Each transition calls
`plant.setState(std::make_unique<NextState>())`, transferring ownership to the instance and automatically destroying the
previous state when the pointer is replaced or when the plant is destroyed.

Key relationships:

- `PlantInstance` **owns** the active `PlantState` and frees it automatically thanks to `std::unique_ptr`.
- `PlantState` implementations never attempt to delete themselves; they simply call `PlantInstance::setState(...)` with a
  freshly allocated state when a transition is required.
- Strategies (`WaterStrategy`, `FertilizeStrategy`) and the prototype pointer (`Plant* plantType`) remain raw,
  non-owning pointers. They reference shared objects managed elsewhere (e.g. registries or flyweights). The code assumes
  those objects outlive the `PlantInstance` that references them.

Guidelines to avoid leaks:

1. Always allocate new states with `std::make_unique<ConcreteState>()` before passing them to `setState`. This guarantees
   the previous state is released immediately.
2. Never store the address of a `PlantState` outside the owning `PlantInstance`. Use `PlantInstance::getState()` for
   inspection only.
3. When injecting strategies or prototype pointers, ensure the lifetime is managed outside the plant (typically by the
   registry or inventory). If ownership changes, replace the raw pointers with smart pointers at the owning boundary.

Following these rules keeps the lifecycle self-contained and prevents dangling pointers during state transitions.
