# Design Patterns Report

Team: COS214 - The Tormentos

This report documents every design pattern identified and used in the Plant Nursery Simulator. For each pattern we explain the intent and rationale (why we chose it), identify the concrete implementation in this codebase (where it is), list the participants, outline key interactions, and map the pattern to the functional requirements (FRs) in `plant-nursery-simulator/docs/Functional_and_non-functional_requirements.md`.

See also: `plant-nursery-simulator/docs/GUI Requirements.md` for UI-focused items that the Facade and Iterator patterns help enable.

Note: File paths point to headers in `include/` and implementations in `src/` within `plant-nursery-simulator/`.

---

## Iterator - Inventory

- Intent and rationale
  - Provide a uniform way to traverse inventory items without exposing the underlying container. Supports browsing and sales workflows cleanly and testably.
- Where implemented
  - `include/InventoryCollection.h` (Aggregate interface)
  - `include/InventoryIterator.h` (Iterator interface)
  - `include/ConcreteInventoryIterator.h`, `src/ConcreteInventoryIterator.cpp` (ConcreteIterator)
  - `include/Inventory.h`, `src/Inventory.cpp` (ConcreteAggregate creating iterators)
- Participants
  - Iterator: `InventoryIterator`
  - ConcreteIterator: `ConcreteInventoryIterator`
  - Aggregate: `InventoryCollection`
  - ConcreteAggregate: `Inventory`
- Key interactions
  - Client code obtains an iterator via `Inventory::createIterator()` and traverses items with `hasNext()/next()`.
- Functional requirements
  - FR15: Aggregate interface to create iterators
  - FR16: Iterate over inventory items for browsing and sales

- Why this pattern over alternatives
  - Over nested loops or exposing containers: The inventory manages multiple concerns (greenhouse-linked items, readiness, ID mapping). Exposing `items` would leak representation and allow incorrect traversal order. The iterator encapsulates a purpose-built ordering that prioritizes sale-ready plant-backed stock while hiding internal storage, as seen in `ConcreteInventoryIterator::rebuildTraversal()`.
  - Over Visitor: We do not need double dispatch or per-element operations; we only need a traversal order and simple item access. Iterator keeps responsibilities minimal and testable.
  - Over returning vectors: The iterator recalculates traversal lazily and can stay consistent as the inventory changes without materializing transient copies in client code.

- Implementation evidence
  - `Inventory` is the ConcreteAggregate that returns `InventoryIterator*` from `createIterator()` (`include/Inventory.h`).
  - `ConcreteInventoryIterator` builds a stable traversal by first walking the greenhouse via `GreenhouseIterator` and selecting plant-backed, market-ready `StockItem`s, then appending remaining eligible stock (`src/ConcreteInventoryIterator.cpp`).
  - Market readiness is checked through the associated `PlantInstance::isAvailableForSale()`, ensuring business rules drive traversal order.

- FR details
  - FR15 (Aggregate interface): `InventoryCollection::createIterator()` defines the contract to obtain iterators; `Inventory` implements it, allowing clients to traverse without knowledge of internals.
  - FR16 (Iterate for workflows): Sales/customer browsing uses the iterator to produce a customer-friendly order (market-ready first). Tests under `tests/iterator_test.cpp` exercise this semantics; the iterator avoids exposing the combination of greenhouse and stock containers.

---

## Iterator - Greenhouse

- Intent and rationale
  - Traverse all plants within a hierarchical greenhouse (Composite) without coupling traversal logic to the structure. Enables controller-driven growth ticks and batch care.
- Where implemented
  - `include/GreenhouseIterator.h` (Iterator interface)
  - `include/ConcreteGreenhouseIterator.h`, `src/ConcreteGreenhouseIterator.cpp` (ConcreteIterator; DFS across beds/leaves)
  - `include/GreenhouseComponent.h` (Aggregate component)
  - `include/GreenhouseBed.h`, `src/GreenhouseBed.cpp` (ConcreteAggregate root/branch)
  - `include/GreenhouseController.h`, `src/GreenhouseController.cpp` (uses iterator to run ticks)
- Participants
  - Iterator: `GreenhouseIterator`
  - ConcreteIterator: `ConcreteGreenhouseIterator`
  - Aggregate/Component: `GreenhouseComponent`
  - ConcreteAggregate: `GreenhouseBed`
- Key interactions
  - `GreenhouseController::runGrowthTick()` requests a fresh iterator from the current bed root and iterates plants to apply per-tick updates.
- Functional requirements
  - FR12: Iterator over greenhouse hierarchy
  - FR26: Controller executes growth tick by iterating plants

- Why this pattern over alternatives
  - Over manual recursive traversal: Encapsulating traversal into an iterator decouples the controller and any client code from the composite’s depth and shape (beds within beds). This prevents repeated reimplementation of DFS/BFS and reduces recursion risks.
  - Over Visitor: The controller mostly needs enumeration; per-node double-dispatch is unnecessary and would overcomplicate the design.

- Implementation evidence
  - `ConcreteGreenhouseIterator::collectPlants()` performs a DFS over `GreenhouseBed::children`, collecting `PlantInstance` leaves in a flat order (`src/ConcreteGreenhouseIterator.cpp`).
  - `GreenhouseBed::createIterator()` is the factory for a bed-scoped iterator, keeping creation close to the composite (`include/GreenhouseBed.h`).

- FR details
  - FR12 (Traverse bed hierarchy): The iterator guarantees that all `PlantInstance`s nested at any depth are visited exactly once. This supports downstream operations such as care or availability checks.
  - FR26 (Controller growth tick): `GreenhouseController::runGrowthTick()` creates a fresh iterator from the configured `GreenhouseBed` and applies `applyGrowthTick()` for each plant, ensuring a single O(n) pass over plants per tick.

---

## Composite - Greenhouse Structure

- Intent and rationale
  - Represent part–whole hierarchies (beds composed of beds and plants) and enable uniform treatment of leaves and composites. Simplifies applying operations (care, tick, display) to entire structures.
- Where implemented
  - `include/GreenhouseComponent.h` (Component abstraction)
  - `include/GreenhouseBed.h`, `src/GreenhouseBed.cpp` (Composite with child management and delegation)
  - `include/PlantInstance.h`, `src/PlantInstance.cpp` (Leaf)
- Participants
  - Component: `GreenhouseComponent`
  - Composite: `GreenhouseBed`
  - Leaf: `PlantInstance`
- Key interactions
  - Composite delegates `performCare()` and other operations to children; leaves implement concrete behaviour.
- Functional requirements
  - FR10: Composite greenhouse hierarchy
  - FR11: Cascade care operations to all plants
  - FR26: Works with Iterator for growth ticks

- Why this pattern over alternatives
  - Over flat collections: The nursery requires grouping plants into beds and potentially nested beds. Composite allows treating beds and plants uniformly (`performCare()`, `createIterator()`), simplifying client code.
  - Over inheritance-only hierarchies without composition: Without Composite, propagating actions (care, traversal) across variable-depth structures would require conditionals and special cases in multiple places.

- Implementation evidence
  - `GreenhouseComponent` declares uniform operations; `GreenhouseBed` owns `children` and delegates `performCare()` to them.
  - `PlantInstance` is the leaf implementing actual care logic, compatible with Composite and Iterator contracts.

- FR details
  - FR10 (Organize hierarchy): Beds hold either other beds or plants via owned `unique_ptr<GreenhouseComponent>`, enabling dynamic, memory-safe structures.
  - FR11 (Cascade care): `GreenhouseBed::performCare()` iterates children and calls `performCare()` recursively, ensuring consistent propagation.
  - FR26 (Iterator over Composite): The Composite provides the structural backbone that the iterator walks each tick.

---

## Facade - Sales

- Intent and rationale
  - Provide a single entry point for sales operations, decoupling UI/client code from inventory, payments, and order-building complexity.
- Where implemented
  - `include/SalesFacade.h`, `src/SalesFacade.cpp`
  - Subsystems: `include/Inventory.h` (+ `src/Inventory.cpp`), `include/PaymentProcessor.h` (+ `src/PaymentProcessor.cpp`), `include/OrderBuilder.h` (+ builders and `Order`)
- Participants
  - Facade: `SalesFacade`
  - Subsystems: `Inventory`, `PaymentProcessor`, `OrderBuilder`/`CustomOrderBuilder`, `Order`
- Key interactions
  - `SalesFacade` orchestrates purchase, stock checks, returns, and order creation without leaking subsystem details to clients.
- Functional requirements
  - FR25: Unified façade for sales flows

- Why this pattern over alternatives
  - Over Service Locator or direct subsystem calls: Facade narrows and stabilizes the API the GUI/tests use, while dependencies (`Inventory`, `PaymentProcessor`, builders) remain swappable and independently testable.
  - Over turning `SalesFacade` into a God object: Facade keeps orchestration only; business rules live in subsystems, preventing bloat and maintaining separation of concerns.

- Implementation evidence
  - `SalesFacade` accepts subsystem pointers and coordinates operations like `purchaseItem`, `addItemToCart`, `buildAndFinalizeOrder`, `checkStock`, and `addItemToInventory`.
  - It also propagates contextual configuration (greenhouse root, prototype registry) via `setGreenhouseRoot()`/`setPlantRegistry()` for consistent environment setup.

- FR details
  - FR25 (Unified sales): The facade exposes one cohesive entry point used in tests (e.g., `tests/facade_test.cpp`) to assemble orders, sell items, and sync inventory without clients needing to understand iterators, prototypes, or adapters.

---

## Builder - Orders

- Intent and rationale
  - Construct complex `Order` objects step-by-step and support different compositions/presets via a director. Keeps `Order` immutable in shape while flexible in content.
- Where implemented
  - `include/Order.h`, `src/Order.cpp` (Product)
  - `include/OrderBuilder.h` (Builder)
  - `include/CustomOrderBuilder.h`, `src/CustomOrderBuilder.cpp` (ConcreteBuilder)
  - `include/OrderDirector.h`, `src/OrderDirector.cpp` (Director)
- Participants
  - Product: `Order` (contains `StockItem` parts)
  - Builder: `OrderBuilder`
  - ConcreteBuilder: `CustomOrderBuilder`
  - Director: `OrderDirector`
- Key interactions
  - `SalesFacade` can use `OrderBuilder` directly or via `OrderDirector` to assemble orders.
- Functional requirements
  - FR24: Build orders with optional director presets

- Why this pattern over alternatives
  - Over telescoping constructors: Orders vary in composition; using a builder avoids brittle large constructors and allows step-wise construction and validation.
  - Over simple factory: Builder supports variable numbers and combinations of `StockItem`s and evolving assembly policies; a factory would not capture sequences and optional steps cleanly.

- Implementation evidence
  - `Order` contains a vector of `StockItem` parts and exposes `addItem()`/`calculateTotal()` used by builders and facade.
  - `OrderBuilder` defines the steps; `CustomOrderBuilder` implements them for general orders; `OrderDirector` encapsulates common presets when needed.

- FR details
  - FR24 (Build orders): The builder composes `Order` instances from selected `StockItem`s. The facade can either drive the builder directly for ad-hoc orders or reuse `OrderDirector` to standardize bundles.

---

## Observer - Plants, Staff, and Stock Items

- Intent and rationale
  - Decouple plant lifecycle events from dependent behaviours such as staff reminders and store display availability. Supports many observers without tight coupling.
- Where implemented
  - `include/Observer.h` (Observer interface)
  - `include/Subject.h`, `src/Subject.cpp` (Subject base and lifecycle)
  - Observers: `include/Staff.h`, `src/Staff.cpp`; `include/StockItem.h`, `src/StockItem.cpp`
  - Subject: `include/PlantInstance.h`, `src/PlantInstance.cpp` (publishes events on tick/state change)
- Participants
  - Subject: `PlantInstance`
  - Observer: `Observer`
  - ConcreteObserver: `Staff`, `StockItem`
- Key interactions
  - `PlantInstance` notifies observers after growth ticks/state transitions; `Staff::update()` schedules work; `StockItem::update()` syncs sale availability/display state.
- Functional requirements
  - FR13: Plant subjects notify observers
  - FR14: Staff and stock observers react to events
  - FR27: Stock item availability mirrors plant readiness

- Why this pattern over alternatives
  - Over polling: Observers receive timely updates on state changes (care required, availability toggled) without periodic scans over all plants.
  - Over event buses: A lightweight Subject/Observer pair provides direct, typed notifications suitable for this domain; a generic bus would add complexity without benefit here.

- Implementation evidence
  - `PlantInstance` inherits `Subject` and calls `notify()` on growth ticks or when `setState()` triggers availability changes.
  - `StockItem::update()` toggles availability and display status based on `ObserverEvent`.
  - `Staff::update()` accumulates care reminders when receiving `CareRequired` events.

- FR details
  - FR13 (Subjects notify): `Subject::~Subject()` also sends `SubjectDestroyed` to enable safe detachment, avoiding dangling pointers during shutdown.
  - FR14 (Observers react): `Staff` adds reminders and can later schedule commands; `StockItem` updates `isAvailable` and user-facing status strings for storefront consistency.
  - FR27 (Sync sale readiness): When a plant transitions to a market-ready state, `StockItem` immediately reflects that in `getDisplayStatus()` for the UI.

---

## Adapter - Inventory File I/O

- Intent and rationale
  - Isolate inventory logic from specific storage formats. Enable pluggable readers/writers (CSV, TXT) without changing inventory code.
- Where implemented
  - Target: `include/FileAdapter.h`
  - Adaptees: `include/CSVReaderWriter.h`, `src/CSVReaderWriter.cpp`; `include/TXTReaderWriter.h`, `src/TXTReaderWriter.cpp`
  - Adapters: `include/CSVAdapter.h`, `src/CSVAdapter.cpp`; `include/TXTAdapter.h`, `src/TXTAdapter.cpp`
  - Client: `include/Inventory.h`, `src/Inventory.cpp` uses `FileAdapter`
- Participants
  - Target: `FileAdapter`
  - Adaptee: `CSVReaderWriter`, `TXTReaderWriter`
  - Adapter: `CSVAdapter`, `TXTAdapter`
  - Client: `Inventory`
- Key interactions
  - `Inventory::loadFromFile()/saveToFile()` depend on the `FileAdapter` interface. Concrete adapters delegate to the corresponding reader/writer.
- Functional requirements
  - FR8: File I/O abstraction for inventory
  - FR9: Load/save via pluggable adapters (CSV, TXT)

---

## Prototype (Data‑Driven) - Plants and Registry

- Intent and rationale
  - Support data-driven creation of plant objects by cloning registered prototypes. Allows new plant types without changing creator code.
- Where implemented
  - `include/Plant.h`, `src/Plant.cpp` (`Plant::clone()`)
  - `include/PlantPrototypeRegistry.h`, `src/PlantPrototypeRegistry.cpp` (stores and clones prototypes)
- Participants
  - Prototype: `Plant`
  - Concrete Prototypes: specific `Plant` subtypes
  - Client/Registry: `PlantPrototypeRegistry`
- Key interactions
  - Prototypes are registered under names; the registry clones on demand to create new instances.
- Functional requirements
  - FR1: Register clonable plant prototypes
  - FR2: Create plants by cloning prototypes

---

## State - Plant Lifecycle

- Intent and rationale
  - Encapsulate lifecycle stages and transitions for plants. Keeps per-state behaviour and thresholds modular and extendable.
- Where implemented
  - `include/PlantState.h` (State interface)
  - Concrete states: `include/SeedState.h`, `include/GrowingState.h`, `include/MatureState.h`, `include/WitheringState.h`, `include/DeadState.h` (+ corresponding `src/*.cpp`)
  - Helpers/thresholds: `include/PlantStateUtils.h`, `include/PlantStateThresholds.h`
  - Context: `include/PlantInstance.h`, `src/PlantInstance.cpp` (delegates to state and triggers transitions)
- Participants
  - State: `PlantState`
  - ConcreteState: `SeedState`, `GrowingState`, `MatureState`, `WitheringState`, `DeadState`
  - Context: `PlantInstance`
- Key interactions
  - Each growth tick `PlantInstance` asks the current `PlantState` to update and possibly transition; `MatureState` communicates market readiness, but `PlantInstance` performs observer notifications.
- Functional requirements
  - FR3: Model lifecycle states and transitions
  - FR4: Identify market-ready plants for sale

---

## Command - Plant Care Tasks

- Intent and rationale
  - Encapsulate care actions (water, fertilize) as command objects queued by staff. Enables scheduling, undo/redo extensions, and testing.
- Where implemented
  - `include/PlantCommand.h` (Command interface)
  - `include/WaterPlant.h`, `src/WaterPlant.cpp` (ConcreteCommand)
  - `include/FertilizePlant.h`, `src/FertilizePlant.cpp` (ConcreteCommand)
  - Receiver: `include/PlantInstance.h`, `src/PlantInstance.cpp` (performs water/fertilize)
  - Invoker: `include/Staff.h`, `src/Staff.cpp` (queues and processes commands)
- Participants
  - Command: `PlantCommand`
  - ConcreteCommand: `WaterPlant`, `FertilizePlant`
  - Receiver: `PlantInstance`
  - Invoker: `Staff`
- Key interactions
  - `Staff` enqueues commands and later processes them; commands call receiver operations to carry out care.
- Functional requirements
  - FR18: Encapsulate plant care actions as commands
  - FR19: Staff queue and invoke care commands

---

## Mediator - Floor Coordination

- Intent and rationale
  - Centralize communication between colleagues (customers, staff) to avoid tight coupling and complex peer-to-peer links.
- Where implemented
  - `include/FloorMediator.h` (Mediator interface)
  - `include/NurseryMediator.h`, `src/NurseryMediator.cpp` (ConcreteMediator)
  - `include/Colleague.h` (base), `include/Customer.h` (+ `src/Customer.cpp`), `include/Staff.h` (+ `src/Staff.cpp`) (ConcreteColleagues)
- Participants
  - Mediator: `FloorMediator`
  - ConcreteMediator: `NurseryMediator`
  - Colleague: `Colleague`
  - ConcreteColleagues: `Customer`, `Staff`
- Key interactions
  - Colleagues send messages to the mediator, which distributes to appropriate recipients, keeping colleagues decoupled.
- Functional requirements
  - FR22: Coordinate communication via mediator
  - FR23: Customers and staff act as colleagues

---

## Chain of Responsibility - Care Routing

- Intent and rationale
  - Route care requests through a chain of handlers so each handler either processes or delegates. Makes it easy to add new care types.
- Where implemented
  - `include/CareRequestHandler.h` (Handler)
  - `include/WateringHandler.h`, `src/WateringHandler.cpp` (ConcreteHandler)
  - `include/FertilizingHandler.h`, `src/FertilizingHandler.cpp` (ConcreteHandler)
  - Client wiring: `include/Staff.h`, `src/Staff.cpp`
- Participants
  - Handler: `CareRequestHandler`
  - ConcreteHandler: `WateringHandler`, `FertilizingHandler`
- Key interactions
  - `Staff` composes the chain and submits requests; each handler checks `canHandle()` and either processes or delegates to `next`.
- Functional requirements
  - FR20: Route care requests through chain
  - FR21: Handlers process or delegate

---

## Strategy (+ Prototype) - Watering and Fertilizing

- Intent and rationale
  - Vary watering and fertilizing algorithms independently of `PlantInstance` and swap them at runtime. We additionally prototype strategies to clone preconfigured policies when needed.
- Where implemented
  - Strategy interfaces: `include/WaterStrategy.h`, `include/FertilizeStrategy.h`
  - Concrete strategies: `include/FrequentWatering.h`, `include/SeasonalWatering.h`, `include/SparseWatering.h`; `include/LiquidFertilizer.h`, `include/SlowReleaseFertilizer.h`, `include/OrganicFertilizer.h` (+ `src/*.cpp`)
  - Used by: `include/PlantInstance.h`, `src/PlantInstance.cpp` (setters and execution)
- Participants
  - Strategy: `WaterStrategy`, `FertilizeStrategy`
  - ConcreteStrategy: frequent/seasonal/sparse watering; liquid/slow-release/organic fertilizing
  - Context: `PlantInstance`
  - Prototype (optional): strategies can be cloned when configured in presets
- Key interactions
  - `PlantInstance` calls the current strategies during care or ticks; strategies update plant vitals according to policy.
- Functional requirements
  - FR5: Interchangeable watering strategies
  - FR6: Interchangeable fertilizing strategies
  - FR7: Change strategies at runtime per plant

---

## Cross‑cutting: StockItem in Sales and Observation

- Role in patterns
  - As an Observer: `StockItem` subscribes to `PlantInstance` and mirrors sale readiness for storefront status.
  - As a Part in Builder/Facade flows: `Order` aggregates `StockItem`s; `SalesFacade` uses `StockItem` to fulfil purchases and build orders.
- Where implemented
  - `include/StockItem.h`, `src/StockItem.cpp`
- Functional requirements (via patterns above)
  - FR14, FR27 (Observer); FR24–FR25 (Builder/Facade usage in sales)

---

## Pattern-to-Requirement Traceability Summary

- Prototype (Plants): FR1, FR2
- State (Lifecycle): FR3, FR4
- Strategy (Water/Fertilize): FR5, FR6, FR7
- Adapter (I/O): FR8, FR9
- Composite (Greenhouse): FR10, FR11, FR26
- Iterator (Greenhouse): FR12, FR26
- Observer (Plants/Staff/Stock): FR13, FR14, FR27
- Iterator (Inventory): FR15, FR16
- Command (Care): FR18, FR19
- Chain of Responsibility: FR20, FR21
- Mediator (Floor): FR22, FR23
- Builder (Orders): FR24
- Facade (Sales): FR25

---

## Notes on Design Choices

- Separation of concerns: Patterns isolate responsibilities (e.g., state vs. strategy vs. observer) to keep each class focused and testable.
- Extensibility: New care policies, file formats, plant states, and greenhouse structures can be added with minimal changes, leveraging Strategy, Adapter, State, and Composite.
- Testability: Iterators, commands, and mediators make behaviour easy to drive from tests without deep setup.
- Performance: Iterating over Composite structures is linear in the number of plants, satisfying FR/NFR scalability goals.
