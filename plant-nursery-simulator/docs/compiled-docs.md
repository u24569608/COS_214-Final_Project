# Plant Nursery Simulator Documentation Compilation

## Source: design-patterns-report.md


# Design Patterns Report

This report documents every design pattern identified and used in the Plant Nursery Simulator. For each pattern we explain the intent and rationale (why we chose it), identify the concrete implementation in this codebase (where it is), list the participants, outline key interactions, and map the pattern to the functional requirements (FRs) in `plant-nursery-simulator/docs/Functional_and_non-functional_requirements.md`.

See also: `plant-nursery-simulator/docs/GUI Requirements.md` for UI-focused items that the Facade and Iterator patterns help enable.

Note: File paths point to headers in `include/` and implementations in `src/` within `plant-nursery-simulator/`.

---

## Research Brief: Nursery Domain Findings

The research phase examined how commercial nurseries operate across plant cultivation, staff coordination, and customer experience. Nurseries behave like living ecosystems where biological growth, human scheduling, and sales interactions constantly influence each other. Understanding those loops guided the simulator so that it mirrors the adaptability of a real operation while staying maintainable.

### Plant care and growth management
- Nurseries manage diverse plant families (annuals, perennials, succulents, shrubs, trees) with distinct water, soil, nutrient, and sunlight profiles (Department of Agriculture, 2023; Royal Horticultural Society, 2022).
- Climate and irrigation systems must adjust on schedule to avoid stress across batches.
- Insight applied: Each `PlantInstance` owns pluggable watering and fertilising strategies (Strategy pattern) so care algorithms can reflect cultivar differences. Lifecycle state transitions (Seed, Growing, Mature, Withering, Dead) capture that a plant responds differently to care depending on maturity (State pattern). Health vitals and thresholds encode the simplified horticultural rules that drive those transitions.

### Staff coordination and task flow
- Nursery teams span growers, floor staff, cashiers, and logistics who need shared context (shift notes, stock changes, care alerts).
- Command batching and delegation help manage repetitive jobs (watering runs, pruning, order prep).
- Insight applied: Care requests become `Command` objects that staff can queue, undo, or audit; specialised handlers (Chain of Responsibility) route tasks to the right role. A `NurseryMediator` centralises communication so staff, inventory, and customer service modules interact without tight coupling, matching the broadcast-style coordination observed in practice.

### Customer experience and sales workflow
- Differentiated service (bespoke potting, gift preparation, delivery) is a competitive lever (Garden Centre Magazine, 2024).
- Checkout systems shield customers from internal stock/database complexity.
- Insight applied: The `SalesFacade` offers a single entry point for the GUI and demo scripts, hiding payment, stock reservation, and notification details. The `OrderDirector` with a `CustomOrderBuilder` composes customised orders (pot finish, wrapping, delivery slot) so optional features stay modular.

### System scalability and data management
- Nurseries expand by adding greenhouse sections, experimenting with cultivars, and switching record formats as partners demand (CSV exports, plain text manifests).
- Insight applied: A composite greenhouse structure lets controllers treat beds and individual plants uniformly and extend the hierarchy as the site grows. Plant prototypes are stored in a registry so new cultivars can be cloned without revisiting construction code (Prototype pattern). CSV and TXT file formats are supported through adapters, insulating inventory logic from I/O changes (Adapter pattern). Observer links keep UI widgets and stock records in sync when a plant changes availability.

### Assumptions and definitions
- Plants are modelled with core vitals (health, water, nutrients, sunlight preference) rather than biological precision; simulation ticks abstract real-time growth.
- Customer preferences focus on order customisation features exposed through the builder (pot, wrapping, delivery); financials remain high level.
- The nursery operates in a controlled climate so environmental factors enter via strategies and state thresholds instead of free-form physics.

### References
- Department of Agriculture. (2023). *Greenhouse Management and Plant Propagation Guide.* Pretoria.
- Royal Horticultural Society. (2022). *Plant Care Best Practices.* London.
- Garden Centre Magazine. (2024). *Trends in Customer Personalisation and Retail Nurseries.*

---

## Functional Requirement Traceability

Functional Requirement (FR) identifiers used throughout this report refer to the definitions captured in `docs/Functional_and_non-functional_requirements.md`. The table below highlights the primary mapping between each design pattern focus area and the FRs it fulfils; detailed rationale and evidence appear in the dedicated pattern sections that follow.

| Pattern focus | FR IDs | Requirement source |
| --- | --- | --- |
| Prototype (Plant registry) | FR1, FR2 | `docs/Functional_and_non-functional_requirements.md` |
| State (Lifecycle transitions) | FR3, FR4 | `docs/Functional_and_non-functional_requirements.md` |
| Strategy (Water/Fertiliser) | FR5, FR6, FR7 | `docs/Functional_and_non-functional_requirements.md` |
| Adapter (Inventory I/O) | FR8, FR9 | `docs/Functional_and_non-functional_requirements.md` |
| Composite (Greenhouse structure) | FR10, FR11, FR26 | `docs/Functional_and_non-functional_requirements.md` |
| Iterator (Greenhouse traversal) | FR12, FR26 | `docs/Functional_and_non-functional_requirements.md` |
| Observer (Plant notifications) | FR13, FR14, FR27 | `docs/Functional_and_non-functional_requirements.md` |
| Iterator (Inventory traversal) | FR15, FR16 | `docs/Functional_and_non-functional_requirements.md` |
| Command (Care tasks) | FR18, FR19 | `docs/Functional_and_non-functional_requirements.md` |
| Chain of Responsibility (Care routing) | FR20, FR21 | `docs/Functional_and_non-functional_requirements.md` |
| Mediator (Nursery coordination) | FR22, FR23 | `docs/Functional_and_non-functional_requirements.md` |
| Builder (Order customisation) | FR24 | `docs/Functional_and_non-functional_requirements.md` |
| Facade (Sales workflow) | FR25 | `docs/Functional_and_non-functional_requirements.md` |

---

## System Overview

The Plant Nursery Simulator models a nursery business end‑to‑end:
- Greenhouse: Plants are organised in a Composite of beds and leaves. A Greenhouse Iterator traverses all plants in depth‑first order to apply periodic growth ticks and care.
- Plants and lifecycle: Each plant instance holds vitals (health, water, nutrients) and a lifecycle State (Seed → Growing → Mature → Withering → Dead). States encapsulate per‑stage behaviour; Strategy objects (watering, fertilising) update vitals.
- Observation: Plants are Subjects and notify Observers (Staff, StockItem) about care needs and availability changes. This decouples lifecycle from UI/operations.
- Inventory and sales: Inventory maintains StockItems (some linked to PlantInstances). An Inventory Iterator exposes a stable traversal prioritising market‑ready plant stock. SalesFacade orchestrates sales, orders, inventory updates, and uses the Builder to assemble orders.
- Persistence: File Adapters (CSV/TXT) abstract I/O so Inventory remains independent of file formats; Adapters adapt Reader/Writers to the `FileAdapter` target.
- Operations: Care actions are Commands queued and executed by Staff; care requests route through a Chain of Responsibility; Customer/Staff communication goes via a Mediator.

---

## Iterator - Inventory

![Iterator - Inventory](diagrams/ClassDiagram/DPClassDiagrams/IteratorInventory.png)

### Intent and rationale
 - Provide a uniform way to traverse inventory items without exposing the underlying container. Supports browsing and sales workflows cleanly and testably while enforcing domain order.
### Where implemented
  - `include/InventoryCollection.h` (Aggregate interface)
  - `include/InventoryIterator.h` (Iterator interface)
  - `include/ConcreteInventoryIterator.h`, `src/ConcreteInventoryIterator.cpp` (ConcreteIterator)
  - `include/Inventory.h`, `src/Inventory.cpp` (ConcreteAggregate creating iterators)
### Participants
  - Iterator: `InventoryIterator`
  - ConcreteIterator: `ConcreteInventoryIterator`
  - Aggregate: `InventoryCollection`
  - ConcreteAggregate: `Inventory`
### Key interactions
  - Client code obtains an iterator via `Inventory::createIterator()` and traverses items with `hasNext()/next()`.
### Functional requirements (with code references and tests)
  - FR15: Aggregate interface to create iterators
    - Code: src/Inventory.cpp:33
    - Test: tests/iterator_test.cpp:23 (testEmptyInventory)
  - FR16: Iterate over inventory items for browsing and sales
    - Code: src/ConcreteInventoryIterator.cpp:20,29,42,47,60-129
    - Tests: tests/iterator_test.cpp:46 (prioritisation), 82 (reset reflects state changes)

### Why this pattern
  - Over nested loops or exposing containers: The inventory manages multiple concerns (greenhouse-linked items, readiness, ID mapping). Exposing `items` would leak representation and allow incorrect traversal order. The iterator encapsulates a purpose-built ordering that prioritizes sale-ready plant-backed stock while hiding internal storage, as seen in `ConcreteInventoryIterator::rebuildTraversal()`.
  - Over Visitor: We do not need double dispatch or per-element operations; we only need a traversal order and simple item access. Iterator keeps responsibilities minimal and testable.
  - Over returning vectors: The iterator recalculates traversal lazily and can stay consistent as the inventory changes without materializing transient copies in client code.

### Implementation evidence
  - `Inventory` is the ConcreteAggregate that returns `InventoryIterator*` from `createIterator()` (`include/Inventory.h`).
  - `ConcreteInventoryIterator` builds a stable traversal by first walking the greenhouse via `GreenhouseIterator` and selecting plant-backed, market-ready `StockItem`s, then appending remaining eligible stock (`src/ConcreteInventoryIterator.cpp`).
  - Market readiness is checked through the associated `PlantInstance::isAvailableForSale()`, ensuring business rules drive traversal order.

### Why efficient
  - O(n) rebuild on demand; reuses greenhouse iterator for plant order; avoids repeated vector materialisation in clients.

---

## Iterator - Greenhouse

![Iterator - Greenhouse](diagrams/ClassDiagram/DPClassDiagrams/IteratorGreenhouse.png)

### Intent and rationale
  - Traverse all plants within a hierarchical greenhouse (Composite) without coupling traversal logic to the structure. Enables controller-driven growth ticks and batch care.
### Where implemented
  - `include/GreenhouseIterator.h` (Iterator interface)
  - `include/ConcreteGreenhouseIterator.h`, `src/ConcreteGreenhouseIterator.cpp` (ConcreteIterator; DFS across beds/leaves)
  - `include/GreenhouseComponent.h` (Aggregate component)
  - `include/GreenhouseBed.h`, `src/GreenhouseBed.cpp` (ConcreteAggregate root/branch)
  - `include/GreenhouseController.h`, `src/GreenhouseController.cpp` (uses iterator to run ticks)
### Participants
  - Iterator: `GreenhouseIterator`
  - ConcreteIterator: `ConcreteGreenhouseIterator`
  - Aggregate/Component: `GreenhouseComponent`
  - ConcreteAggregate: `GreenhouseBed`
### Key interactions
  - `GreenhouseController::runGrowthTick()` requests a fresh iterator from the current bed root and iterates plants to apply per-tick updates.
### Functional requirements (with code references and tests)
  - FR12: Iterator over greenhouse hierarchy
    - Code: src/GreenhouseBed.cpp:62; src/ConcreteGreenhouseIterator.cpp:15,26,38,42,49-64
    - Tests: tests/greenhouse_iterator_test.cpp:20 (empty), 32 (flat), 57 (nested), 92 (refresh)
  - FR26: Controller executes growth tick by iterating plants
    - Code: include/GreenhouseController.h:30
    - Tests: exercised via iterator + state in tests/plant_state_test.cpp:121

### Why this pattern
  - Over manual recursive traversal: Encapsulating traversal into an iterator decouples the controller and any client code from the composite’s depth and shape (beds within beds). This prevents repeated reimplementation of DFS/BFS and reduces recursion risks.
  - Over Visitor: The controller mostly needs enumeration; per-node double-dispatch is unnecessary and would overcomplicate the design.

### Implementation evidence
  - `ConcreteGreenhouseIterator::collectPlants()` performs a DFS over `GreenhouseBed::children`, collecting `PlantInstance` leaves in a flat order (`src/ConcreteGreenhouseIterator.cpp`).
  - `GreenhouseBed::createIterator()` is the factory for a bed-scoped iterator, keeping creation close to the composite (`include/GreenhouseBed.h`).

### Why efficient
  - Single DFS collection and O(n) iteration per tick; no repeated visits; flat traversal array improves locality.

---

## Composite - Greenhouse Structure

![Composite - Greenhouse Structure](diagrams/ClassDiagram/DPClassDiagrams/CompositeGreenhouse.png)

### Intent and rationale
  - Represent part–whole hierarchies (beds composed of beds and plants) and enable uniform treatment of leaves and composites. Simplifies applying operations (care, tick, display) to entire structures.
### Where implemented
  - `include/GreenhouseComponent.h` (Component abstraction)
  - `include/GreenhouseBed.h`, `src/GreenhouseBed.cpp` (Composite with child management and delegation)
  - `include/PlantInstance.h`, `src/PlantInstance.cpp` (Leaf)
### Participants
  - Component: `GreenhouseComponent`
  - Composite: `GreenhouseBed`
  - Leaf: `PlantInstance`
### Key interactions
  - Composite delegates `performCare()` and other operations to children; leaves implement concrete behaviour.
### Functional requirements (with code references and tests)
  - FR10: Composite greenhouse hierarchy
    - Code: src/GreenhouseBed.cpp:21,28,66-81,83-117,58-64
    - Tests: tests/greenhouse_iterator_test.cpp:70; tests/greenhouse_composite_test.cpp:43
  - FR11: Cascade care operations to all plants
    - Code: src/GreenhouseBed.cpp:32-38; src/PlantInstance.cpp:168-175
    - Tests: tests/greenhouse_composite_test.cpp:59
  - FR26: Works with Iterator for growth ticks
    - Code: src/GreenhouseBed.cpp:62
    - Tests: iterator tests above

### Why this pattern
  - Over flat collections: The nursery requires grouping plants into beds and potentially nested beds. Composite allows treating beds and plants uniformly (`performCare()`, `createIterator()`), simplifying client code.
  - Over inheritance-only hierarchies without composition: Without Composite, propagating actions (care, traversal) across variable-depth structures would require conditionals and special cases in multiple places.

### Implementation evidence
  - `GreenhouseComponent` declares uniform operations; `GreenhouseBed` owns `children` and delegates `performCare()` to them.
  - `PlantInstance` is the leaf implementing actual care logic, compatible with Composite and Iterator contracts.

### Why efficient
  - Care cascades in a single pass; ownership via `unique_ptr` keeps memory safe and local.

---

## Facade - Sales

![Facade - Sales](diagrams/ClassDiagram/DPClassDiagrams/FacadeSales.png)

### Intent and rationale
  - Provide a single entry point for sales operations, decoupling UI/client code from inventory, payments, and order-building complexity.
### Where implemented
  - `include/SalesFacade.h`, `src/SalesFacade.cpp`
  - Subsystems: `include/Inventory.h` (+ `src/Inventory.cpp`), `include/PaymentProcessor.h` (+ `src/PaymentProcessor.cpp`), `include/OrderBuilder.h` (+ builders and `Order`)
### Participants
  - Facade: `SalesFacade`
  - Subsystems: `Inventory`, `PaymentProcessor`, `OrderBuilder`/`CustomOrderBuilder`, `Order`
### Key interactions
  - `SalesFacade` orchestrates purchase, stock checks, returns, and order creation without leaking subsystem details to clients.
### Functional requirements (with code references and tests)
  - FR25: Unified façade for sales flows
    - Check stock: src/SalesFacade.cpp:165 — tests/facade_test.cpp:63
    - Add to inventory: src/SalesFacade.cpp:172-186 — tests/facade_test.cpp:67
    - Purchase item: src/SalesFacade.cpp:192-235 — tests/facade_test.cpp:79,95
    - Build+finalise order: src/SalesFacade.cpp:257-307 — tests/facade_test.cpp:111
    - Process return: src/SalesFacade.cpp:320-357 — tests/facade_test.cpp:134
    - Cart sync notify: src/SalesFacade.cpp:362-371 — tests/facade_test.cpp:164

### Why this pattern
  - Over Service Locator or direct subsystem calls: Facade narrows and stabilizes the API the GUI/tests use, while dependencies (`Inventory`, `PaymentProcessor`, builders) remain swappable and independently testable.
  - Over turning `SalesFacade` into a "master" object: Facade keeps orchestration only; business rules live in subsystems, preventing bloat and maintaining separation of concerns.

### Implementation evidence
  - `SalesFacade` accepts subsystem pointers and coordinates operations like `purchaseItem`, `addItemToCart`, `buildAndFinalizeOrder`, `checkStock`, and `addItemToInventory`.
  - It also propagates contextual configuration (greenhouse root, prototype registry) via `setGreenhouseRoot()`/`setPlantRegistry()` for consistent environment setup.

### Why efficient
  - Orchestration is O(1) per item; leverages inventory IDs to avoid repeated lookups.

---

## Builder - Orders

![Builder - Orders](diagrams/ClassDiagram/DPClassDiagrams/BuilderOrder.png)

### Intent and rationale
  - Construct complex `Order` objects step-by-step and support different compositions/presets via a director. Keeps `Order` immutable in shape while flexible in content.
### Where implemented
  - `include/Order.h`, `src/Order.cpp` (Product)
  - `include/OrderBuilder.h` (Builder)
  - `include/CustomOrderBuilder.h`, `src/CustomOrderBuilder.cpp` (ConcreteBuilder)
  - `include/OrderDirector.h`, `src/OrderDirector.cpp` (Director)
### Participants
  - Product: `Order` (contains `StockItem` parts)
  - Builder: `OrderBuilder`
  - ConcreteBuilder: `CustomOrderBuilder`
  - Director: `OrderDirector`
  - Part: `StockItem`
### Key interactions
  - `SalesFacade` can use `OrderBuilder` directly or via `OrderDirector` to assemble orders.
### Functional requirements (with code references and tests)
  - FR24: Build orders with optional director presets
    - Builder API: src/OrderBuilder.cpp:13,22; src/CustomOrderBuilder.cpp:17-24
    - Facade usage: src/SalesFacade.cpp:257-307
    - Test: tests/facade_test.cpp:111

### Why this pattern
  - Over telescoping constructors: Orders vary in composition; using a builder avoids brittle large constructors and allows step-wise construction and validation.
  - Over simple factory: Builder supports variable numbers and combinations of `StockItem`s and evolving assembly policies; a factory would not capture sequences and optional steps cleanly.

### Implementation evidence
  - `Order` contains a vector of `StockItem` parts and exposes `addItem()`/`calculateTotal()` used by builders and facade.
  - `OrderBuilder` defines the steps; `CustomOrderBuilder` implements them for general orders; `OrderDirector` encapsulates common presets when needed.

### Why efficient
  - Linear in item count; uses simple copies of `StockItem` parts; no reflection or dynamic registration needed.

---

## Observer - Plants, Staff, and Stock Items

![Observer - Plants, Staff, and Stock Items](diagrams/ClassDiagram/DPClassDiagrams/ObserverPlant.png)

### Intent and rationale
  - Decouple plant lifecycle events from dependent behaviours such as staff reminders and store display availability. Supports many observers without tight coupling.
### Where implemented
  - `include/Observer.h` (Observer interface)
  - `include/Subject.h`, `src/Subject.cpp` (Subject base and lifecycle)
  - Observers: `include/Staff.h`, `src/Staff.cpp`; `include/StockItem.h`, `src/StockItem.cpp`
  - Subject: `include/PlantInstance.h`, `src/PlantInstance.cpp` (publishes events on tick/state change)
### Participants
  - Subject: `Subject`
  - ConcreteSubject: `PlantInstance`
  - Observer: `Observer`
  - ConcreteObserver: `Staff`, `StockItem`
### Key interactions
  - `PlantInstance` notifies observers after growth ticks/state transitions; `Staff::update()` schedules work; `StockItem::update()` syncs sale availability/display state.
### Functional requirements (with code references and tests)
  - FR13: Plant subjects notify observers
    - Code: src/PlantInstance.cpp:116-135,142-153,245-260; src/Subject.cpp:6-16
    - Tests: cart sync after sale (mediated by facade notification), tests/facade_test.cpp:164
  - FR14: Staff and stock observers react to events
    - Code: src/Staff.cpp:66-83; src/StockItem.cpp:102-130,149-155
    - Tests: adapter/state flows confirm availability and reminders; tests/adapter_test.cpp:119-137
  - FR27: Stock item availability mirrors plant readiness
    - Code: src/PlantInstance.cpp:163-165; src/StockItem.cpp:149-155
    - Tests: prioritised iterator order implies readiness, tests/iterator_test.cpp:62,104

### Model used: Push Model
  - `PlantInstance::setState()` and `PlantInstance::applyGrowthTick()` build an `ObserverEvent` that already contains the message copy and optional availability flag before calling `Subject::notify()` (`src/PlantInstance.cpp:121-153,267-276`; `src/Subject.cpp:38-45`). Observers such as `StockItem::update()` and `Staff::update()` consume that payload directly, so they do not need to call back into the subject for additional context (`src/StockItem.cpp:110-136`; `src/Staff.cpp:48-88`). This keeps coupling low while ensuring each notification delivers exactly the state the UI and reminder queues require.

### Why this pattern
  - Over polling: Observers receive timely updates on state changes (care required, availability toggled) without periodic scans over all plants.
  - Over event buses: A lightweight Subject/Observer pair provides direct, typed notifications suitable for this domain; a generic bus would add complexity without benefit here.

### Implementation evidence
  - `PlantInstance` inherits `Subject` and calls `notify()` on growth ticks or when `setState()` triggers availability changes.
  - `StockItem::update()` toggles availability and display status based on `ObserverEvent`.
  - `Staff::update()` accumulates care reminders when receiving `CareRequired` events.

### Why efficient
  - O(k) notify where k is subscriber count; simple data payload; snapshot iteration avoids re-entrancy issues.

---

## Adapter - Inventory File I/O

![Adapter - Inventory File I/O](diagrams/ClassDiagram/DPClassDiagrams/AdapterIO.png)

### Intent and rationale
  - Isolate inventory logic from specific storage formats. Enable pluggable readers/writers (CSV, TXT) without changing inventory code.

### Where implemented
  - Target: `include/FileAdapter.h`
  - Adaptees: `include/CSVReaderWriter.h`, `src/CSVReaderWriter.cpp`; `include/TXTReaderWriter.h`, `src/TXTReaderWriter.cpp`
  - Adapters: `include/CSVAdapter.h`, `src/CSVAdapter.cpp`; `include/TXTAdapter.h`, `src/TXTAdapter.cpp`
  - Client: `include/Inventory.h`, `src/Inventory.cpp` (uses `FileAdapter`)

### Participants
  - Target: `FileAdapter`
  - Adaptee: `CSVReaderWriter`, `TXTReaderWriter`
  - Adapter: `CSVAdapter`, `TXTAdapter`
  - Client: `Inventory`

### Key interactions
  - `Inventory::loadFromFile()/saveToFile()` depend on the `FileAdapter` interface. Concrete adapters delegate to the corresponding reader/writer.

### Functional requirements (with code references and tests)
  - FR8: File I/O abstraction for inventory
    - Code: src/Inventory.cpp:137-165
    - Tests: tests/adapter_test.cpp:33 (CSV round‑trip), 112 (TXT round‑trip)
  - FR9: Load/save via pluggable adapters (CSV, TXT)
    - Code: src/CSVAdapter.cpp:58-117,122-140; src/TXTAdapter.cpp:58-130,136-153
    - Tests: tests/adapter_test.cpp:180-238 (invalid/bad input handling)

### Why this pattern
  - Over direct file I/O in `Inventory`: The adapter target allows `Inventory` to depend only on `FileAdapter`, enabling addition of new formats without edits to `Inventory`.
  - Over Strategy: While similar in pluggability, Adapter is the right choice since we adapt existing reader/writer interfaces (`CSVReaderWriter`, `TXTReaderWriter`) that do not match the expected `FileAdapter` API.

### Implementation evidence
  - `CSVAdapter` and `TXTAdapter` wrap their respective `*ReaderWriter` and translate to the `FileAdapter` interface.
  - `Inventory::loadFromFile()` and `saveToFile()` simply call through to the adapter, keeping persistence concerns out of collection logic.

### Why efficient
  - Single‑pass encode/decode; uses `InventoryIterator` to stream items without copying containers; O(n) in item count.

---

## Prototype (Data‑Driven) - Plants and Registry

![Prototype - Plants and Registry](diagrams/ClassDiagram/DPClassDiagrams/PrototypePlant.png)

### Intent and rationale
  - Support data-driven creation of plant objects by cloning registered prototypes. Allows new plant types without changing creator code.
### Where implemented
  - `include/Plant.h`, `src/Plant.cpp` (`Plant::clone()`)
  - `include/PlantPrototypeRegistry.h`, `src/PlantPrototypeRegistry.cpp` (stores and clones prototypes)
### Participants
  - Prototype: `Plant`
  - Concrete Prototypes: specific `Plant` subtypes
  - Client/Registry: `PlantPrototypeRegistry`
### Key interactions
  - Prototypes are registered under names; the registry clones on demand to create new instances.
### Functional requirements (with code references and tests)
  - FR1: Register clonable plant prototypes
    - Code: src/PlantPrototypeRegistry.cpp:10-16
    - Tests: prototype registration helpers e.g., tests/iterator_test.cpp:29; tests/adapter_test.cpp:54
  - FR2: Create plants by cloning prototypes
    - Code: src/PlantPrototypeRegistry.cpp:18-34; src/Inventory.cpp:219-252
    - Tests: used in adapter roundtrips and iterator tests

### Why this pattern
  - Over Abstract Factory/Factory Method: Plant types are data-driven and registered at runtime; Prototype allows cloning configured exemplars without centralizing construction logic for every type.
  - Over copy constructors alone: The registry maps string keys to polymorphic prototypes with virtual `clone()`, avoiding slicing and keeping creation decoupled from concrete classes.

### Implementation evidence
  - `PlantPrototypeRegistry::addPrototype()` stores owned prototypes by name; `createPlant()` clones on demand.
  - `Inventory::createPlantInstance()` requests a prototype and configures a `PlantInstance`, applying default strategies if present.

### Why efficient
  - Clone cost is O(1); avoids reflection/RTTI factories and keeps ownership explicit.

---

## State - Plant Lifecycle

![State - Plant Lifecycle](diagrams/ClassDiagram/DPClassDiagrams/StatePlant.png)

### Intent and rationale
  - Encapsulate lifecycle stages and transitions for plants. Keeps per-state behaviour and thresholds modular and extendable.
### Where implemented
  - `include/PlantState.h` (State interface)
  - Concrete states: `include/SeedState.h`, `include/GrowingState.h`, `include/MatureState.h`, `include/WitheringState.h`, `include/DeadState.h` (+ corresponding `src/*.cpp`)
  - Helpers/thresholds: `include/PlantStateUtils.h`, `include/PlantStateThresholds.h`
  - Context: `include/PlantInstance.h`, `src/PlantInstance.cpp` (delegates to state and triggers transitions)
### Participants
  - State: `PlantState`
  - ConcreteState: `SeedState`, `GrowingState`, `MatureState`, `WitheringState`, `DeadState`
  - Context: `PlantInstance`
### Key interactions
  - Each growth tick `PlantInstance` asks the current `PlantState` to update and possibly transition; `MatureState` communicates market readiness, but `PlantInstance` performs observer notifications.
### Functional requirements (with code references and tests)
  - FR3: Model lifecycle states and transitions
    - Code: src/PlantInstance.cpp:142-153 (tick), 100-136 (state replacement)
    - Tests: tests/plant_state_test.cpp:111,147,186,210,231
  - FR4: Identify market-ready plants for sale
    - Code: include/PlantState.h:34-40; src/PlantInstance.cpp:163-165
    - Tests: iterator prioritisation, tests/iterator_test.cpp:62,104

### Why this pattern
  - Over large conditional chains: Encapsulating per-state logic (`onTick`, `onWater`, `onFertilize`) reduces branching and isolates thresholds/transitions for maintainability.
  - Over Strategy alone: Strategies handle how to perform care; State determines when and how states change and whether a plant is market-ready.

### Implementation evidence
  - `PlantState` defines lifecycle hooks; concrete states implement behaviour and transitions. `PlantInstance::setState()` owns state lifetime and centralizes observer notifications when availability changes.
  - `isMarketReady()` is state-specific (true in `MatureState`) and drives sales availability checks.

### Why efficient
  - Constant-time per plant per tick; branching isolated within state objects; transitions only on threshold crossings.

---

## Command - Plant Care Tasks

![Command - Plant Care Tasks](diagrams/ClassDiagram/DPClassDiagrams/CommandPlantCare.png)

### Intent and rationale
  - Encapsulate care actions (water, fertilize) as command objects queued by staff. Enables scheduling, undo/redo extensions, and testing.
### Where implemented
  - `include/PlantCommand.h` (Command interface)
  - `include/WaterPlant.h`, `src/WaterPlant.cpp` (ConcreteCommand)
  - `include/FertilizePlant.h`, `src/FertilizePlant.cpp` (ConcreteCommand)
  - Receiver: `include/PlantInstance.h`, `src/PlantInstance.cpp` (performs water/fertilize)
  - Invoker: `include/Staff.h`, `src/Staff.cpp` (queues and processes commands)
### Participants
  - Command: `PlantCommand`
  - ConcreteCommand: `WaterPlant`, `FertilizePlant`
  - Receiver: `PlantInstance`
  - Invoker: `Staff`
### Key interactions
  - `Staff` enqueues commands and later processes them; commands call receiver operations to carry out care.
### Functional requirements (with code references and tests)
  - FR18: Encapsulate plant care actions as commands
    - Code: src/WaterPlant.cpp:9-16; src/FertilizePlant.cpp:9-16
    - Tests: strategy invocation counts in tests/plant_state_test.cpp:136,160
  - FR19: Staff queue and invoke care commands
    - Code: src/Staff.cpp:101-117,119-121
    - Tests: used by integration flows

### Why this pattern
  - Over direct method calls: Command objects let staff queue, schedule, and potentially undo/redo operations, decoupling request from execution time.
  - Over function pointers/lambdas: Dedicated command classes capture semantics, enable polymorphic queues, and remain serializable/traceable if needed.

### Implementation evidence
  - `WaterPlant` and `FertilizePlant` extend `PlantCommand` and call receiver methods on `PlantInstance`. `Staff` maintains a queue and processes tasks later.

### Why efficient
  - O(1) enqueue/dequeue; direct receiver invocation.

---

## Mediator - Floor Coordination

![Mediator - Floor Coordination](diagrams/ClassDiagram/DPClassDiagrams/MediatorFloor.png)

### Intent and rationale
  - Centralize communication between colleagues (customers, staff) to avoid tight coupling and complex peer-to-peer links.
### Where implemented
  - `include/FloorMediator.h` (Mediator interface)
  - `include/NurseryMediator.h`, `src/NurseryMediator.cpp` (ConcreteMediator)
  - `include/Colleague.h` (base), `include/Customer.h` (+ `src/Customer.cpp`), `include/Staff.h` (+ `src/Staff.cpp`) (ConcreteColleagues)
### Participants
  - Mediator: `FloorMediator`
  - ConcreteMediator: `NurseryMediator`
  - Colleague: `Colleague`
  - ConcreteColleagues: `Customer`, `Staff`
### Key interactions
  - Colleagues send messages to the mediator, which distributes to appropriate recipients, keeping colleagues decoupled.
### Functional requirements (with code references and tests)
  - FR22: Coordinate communication via mediator
    - Code: src/NurseryMediator.cpp:31-59
    - Tests: used implicitly via facade/customer interactions
  - FR23: Customers and staff act as colleagues
    - Code: src/Staff.cpp:90-99; src/Customer.cpp:103-111
    - Tests: cart sync via sale notify, tests/facade_test.cpp:164

### Why this pattern
  - Over direct references between colleagues: Mediator avoids N² coupling and simplifies adding/removing colleagues without rewriting routing logic.
  - Over Observer for chat-like messaging: We require directed messages (with optional recipient); Mediator’s `distribute()` with sender/recipient IDs matches this routing concern.

### Implementation evidence
  - `NurseryMediator` stores colleagues and routes messages via `distribute()`. `Staff` and `Customer` subclass `Colleague` and use `send()/receive()` to interact.

### Why efficient
  - O(m) for broadcast across m colleagues; O(1) targeted delivery after a short scan.

---

## Chain of Responsibility - Care Routing

![Chain of Responsibility - Care Routing](diagrams/ClassDiagram/DPClassDiagrams/CORHandlers.png)

### Intent and rationale
  - Route care requests through a chain of handlers so each handler either processes or delegates. Makes it easy to add new care types.
### Where implemented
  - `include/CareRequestHandler.h` (Handler)
  - `include/WateringHandler.h`, `src/WateringHandler.cpp` (ConcreteHandler)
  - `include/FertilizingHandler.h`, `src/FertilizingHandler.cpp` (ConcreteHandler)
  - Client wiring: `include/Staff.h`, `src/Staff.cpp`
### Participants
  - Handler: `CareRequestHandler`
  - ConcreteHandler: `WateringHandler`, `FertilizingHandler`
### Key interactions
  - `Staff` composes the chain and submits requests; each handler checks `canHandle()` and either processes or delegates to `next`.
### Functional requirements (with code references and tests)
  - FR20: Route care requests through chain
    - Code: include/CareRequestHandler.h:18-30; src/WateringHandler.cpp:24-42; src/FertilizingHandler.cpp:24-41
    - Tests: exercised by staff request flows
  - FR21: Handlers process or delegate
    - Code: src/WateringHandler.cpp:18-22,35-41; src/FertilizingHandler.cpp:18-22,34-41
    - Tests: manual verification via Staff::makeCareRequest

### Why this pattern
  - Over switch/case branching: The chain allows adding new care types without modifying a central dispatcher, respecting Open/Closed Principle.
  - Over Strategy: We need routing plus delegation to “next” when unsupported; CoR matches that responsibility better.

### Implementation evidence
  - `CareRequestHandler::handleRequest()` checks `canHandle()` and delegates to `nextHandler` when necessary. `WateringHandler`/`FertilizingHandler` implement the care-specific logic.
  - `Staff` composes the chain and invokes `makeCareRequest()` with a textual request type.

### Why efficient
  - Worst-case O(h) where h is handler count; constant work per handler.

---

## Strategy (+ Prototype) - Watering and Fertilizing

![Strategy - Watering and Fertilizing](diagrams/ClassDiagram/DPClassDiagrams/StrategyPrototypePlant.png)

### Intent and rationale
  - Vary watering and fertilizing algorithms independently of `PlantInstance` and swap them at runtime. We additionally prototype strategies to clone preconfigured policies when needed.
### Where implemented
  - Strategy interfaces: `include/WaterStrategy.h`, `include/FertilizeStrategy.h`
  - Concrete strategies: `include/FrequentWatering.h`, `include/SeasonalWatering.h`, `include/SparseWatering.h`; `include/LiquidFertilizer.h`, `include/SlowReleaseFertilizer.h`, `include/OrganicFertilizer.h` (+ `src/*.cpp`)
  - Used by: `include/PlantInstance.h`, `src/PlantInstance.cpp` (setters and execution)
### Participants
  - Strategy: `WaterStrategy`, `FertilizeStrategy`
  - ConcreteStrategy: frequent/seasonal/sparse watering; liquid/slow-release/organic fertilizing
  - Context: `PlantInstance`
  - Prototype (optional): strategies can be cloned when configured in presets
### Key interactions
  - `PlantInstance` calls the current strategies during care or ticks; strategies update plant vitals according to policy.
### Functional requirements (with code references and tests)
  - FR5: Interchangeable watering strategies
    - Code: include/WaterStrategy.h:15-20; src/FrequentWatering.cpp:7-15
    - Tests: tests/plant_state_test.cpp:136
  - FR6: Interchangeable fertilizing strategies
    - Code: include/FertilizeStrategy.h:15-20; src/SlowReleaseFertilizer.cpp:7-15
    - Tests: tests/plant_state_test.cpp:160
  - FR7: Change strategies at runtime per plant
    - Code: src/PlantInstance.cpp:41-47
    - Tests: tests/plant_state_test.cpp:120-125 (inject tracking strategies)

### Why this pattern
  - Over flags/if-else: Encapsulating varying algorithms keeps `PlantInstance` free of branching and enables runtime swaps.
  - Over Command: Strategies are algorithms applied by the plant, not queued actions; Command is used for staff tasking instead.
  - Prototype addition: Concrete strategies implement `clone()` to allow copying configured strategies if needed by presets/director flows.

### Implementation evidence
  - Strategy interfaces define `water()`/`fertilize()`; concrete strategies implement different adjustments to vitals (e.g., frequent vs sparse watering).
  - `PlantInstance::setWaterStrategy()` / `setFertilizeStrategy()` swap algorithms without reconstructing the plant.

### Why efficient
  - Direct virtual dispatch; O(1) swaps; minimal per‑call overhead.

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

## Pattern-to-Requirement Summary

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




---

## Source: Functional_and_non-functional_requirements.md


# Plant Nursery Simulator — Functional and Non-Functional Requirements (Project Version)

*_COS214 Team — The Tormentos_*  
_Updated: 2025 Project Version_

## Scope and source

This document captures the Project-version requirements described in the COS214 Final Project Specification (2025). The requirements are derived from and traceable to the implemented C++ code under `plant-nursery-simulator/include` and `plant-nursery-simulator/src`. Where applicable, each Functional Requirement (FR) references the design pattern(s) used. This satisfies the specification guidance to identify functional requirements per design pattern and to utilise at least ten design patterns.

## Functional requirements

The following FRs are organised by subsystem / pattern. IDs (FR1, FR2, ...) are unique across the system.

### Plants, prototypes and lifecycle

1. **FR1.** The system shall support registering clonable plant prototypes by name. [Pattern: Prototype]  
   Implementation: `PlantPrototypeRegistry::addPrototype` (`include/PlantPrototypeRegistry.h`).

2. **FR2.** The system shall create new plant objects by cloning a registered prototype, with optional type override. [Pattern: Prototype]  
   Implementation: `PlantPrototypeRegistry::createPlant` (`include/PlantPrototypeRegistry.h`); `Plant::clone()` (`include/Plant.h`).

3. **FR3.** The system shall model plant lifecycle states and transitions driven by vitals (health, water, nutrients) during growth ticks. [Pattern: State]  
   Implementation: `PlantState` and concrete states `SeedState`, `GrowingState`, `MatureState`, `WitheringState`, `DeadState` (`include/*.h`); thresholds and helpers in `PlantStateThresholds.h`, `PlantStateUtils.h`; `PlantInstance::applyGrowthTick()`.

4. **FR4.** The system shall mark a plant as available for sale when it is in a market-ready lifecycle state. [Pattern: State]  
   Implementation: `MatureState::isMarketReady()`, `PlantInstance::isAvailableForSale()`.

### Care strategies (watering / fertilising)

5. **FR5.** The system shall define interchangeable watering strategies and execute them per plant. [Pattern: Strategy]  
   Implementation: `WaterStrategy` and concretes `FrequentWatering`, `SeasonalWatering`, `SparseWatering`; `WaterStrategy::water()`.

6. **FR6.** The system shall define interchangeable fertilising strategies and execute them per plant. [Pattern: Strategy]  
   Implementation: `FertilizeStrategy` and concretes `LiquidFertilizer`, `SlowReleaseFertilizer`, `OrganicFertilizer`; `FertilizeStrategy::fertilize()`.

7. **FR7.** The system shall allow changing the watering and fertilising strategies at runtime per plant instance. [Pattern: Strategy]  
   Implementation: `PlantInstance::setWaterStrategy()`, `PlantInstance::setFertilizeStrategy()`.

### Greenhouse structure and traversal

8. **FR8.** The system shall provide a file I/O abstraction for inventory. [Pattern: Adapter Target]  
   Implementation: `FileAdapter` (`include/FileAdapter.h`).

9. **FR9.** The system shall load and save inventory using pluggable adapters for supported formats (CSV, TXT). [Pattern: Adapter]  
   Implementation: `CSVAdapter`, `TXTAdapter` wrapping `CSVReaderWriter`, `TXTReaderWriter`; used by `Inventory::loadFromFile()`, `Inventory::saveToFile()`.

10. **FR10.** The system shall organise plants in a composite greenhouse hierarchy of beds and leaves (plants). [Pattern: Composite]  
	Implementation: `GreenhouseComponent` (component), `GreenhouseBed` (composite), `PlantInstance` (leaf).

11. **FR11.** The system shall cascade care operations through the greenhouse hierarchy, reaching all plants. [Pattern: Composite]  
	Implementation: `GreenhouseBed::performCare()` delegates to children; `PlantInstance::performCare()`.

12. **FR12.** The system shall provide an iterator to traverse all plants inside a greenhouse bed hierarchy. [Pattern: Iterator]  
	Implementation: `GreenhouseIterator` interface and `ConcreteGreenhouseIterator` (DFS over `GreenhouseBed`).

### Observation and notifications

13. **FR13.** Plants shall act as subjects that notify observers of significant events, including care required, availability changes, and shutdown. [Pattern: Observer]  
	Implementation: `Subject` base; `PlantInstance` derives from `Subject`; events in `ObserverEvent`, types in `ObserverEventType`; notifications in `PlantInstance::applyGrowthTick()` and state changes.

14. **FR14.** Staff and stock items shall observe plants and update their own state or reminders upon notifications. [Pattern: Observer]  
	Implementation: `Staff::update()` (care reminders), `StockItem::update()` (availability/display status); subject lifetime handled in `Subject::~Subject()`.

### Inventory and aggregation

15. **FR15.** The system shall expose an aggregate interface for inventory collections to create iterators. [Pattern: Iterator Aggregate]  
	Implementation: `InventoryCollection` with `createIterator()`.

16. **FR16.** The system shall iterate over inventory items to support browsing and sales workflows. [Pattern: Iterator]  
	Implementation: `InventoryIterator`, `ConcreteInventoryIterator`; used by `Customer::browseInventory()` and tests.

17. **FR17.** The system shall maintain and query inventory, including adding, removing, counting by type, and lookup by name. [No specific pattern]  
	Implementation: `Inventory::additem()`, `Inventory::removeItem()`, `Inventory::getStockCount()`, `Inventory::findItem()`; `StockItem` accessors.

### Staff, commands and care workflow

18. **FR18.** The system shall encapsulate plant care actions as commands. [Pattern: Command]  
	Implementation: `PlantCommand` (command), `WaterPlant`, `FertilizePlant` (concrete commands); receiver methods in `PlantInstance::performWater()`, `PlantInstance::performFertilize()`.

19. **FR19.** Staff shall queue and invoke plant care commands for later execution. [Pattern: Command Invoker]  
	Implementation: `Staff::addCommandToQueue()`, `Staff::processNextTask()`, `Staff::getTaskQueueSize()`.

20. **FR20.** The system shall route care requests (e.g., watering, fertilising) through a chain of responsibility. [Pattern: Chain of Responsibility]  
	Implementation: `CareRequestHandler` (handler), `WateringHandler`, `FertilizingHandler` (concrete handlers); `CareRequestHandler::setNext()`, `canHandle()`, `handleRequest()`.

21. **FR21.** Each care handler shall either process the request it supports or delegate to the next handler. [Pattern: Chain of Responsibility]  
	Implementation: Concrete handler overrides of `canHandle()` and `handleRequest()` in `WateringHandler`, `FertilizingHandler`; client wiring via `Staff::setCareHandler()`, `Staff::makeCareRequest()`.

### Mediation and customer interaction

22. **FR22.** The system shall coordinate communication between colleagues (customers, staff) via a mediator. [Pattern: Mediator]  
	Implementation: `FloorMediator` interface and `NurseryMediator` concrete; `FloorMediator::distribute()`.

23. **FR23.** Customers and staff shall act as colleagues, sending and receiving messages through the mediator. [Pattern: Mediator]  
	Implementation: `Colleague` base; `Customer` and `Staff` implement `send()/receive()/getID()`.

### Sales, orders and façade

24. **FR24.** The system shall build orders from items using a builder and an optional director for presets. [Pattern: Builder]  
	Implementation: `Order` (product), `OrderBuilder` (builder), `CustomOrderBuilder` (concrete builder), `OrderDirector` (director); `Order::addItem()`, `Order::calculateTotal()`, `OrderDirector::build*()`.

25. **FR25.** The system shall provide a unified façade for sales operations including purchase, stock checks, custom orders, returns, and inventory updates. [Pattern: Facade]  
	Implementation: `SalesFacade` using `Inventory`, `PaymentProcessor`, and `OrderBuilder`; methods `purchaseItem()`, `buildAndFinalizeOrder()`, `processReturn()`, `checkStock()`, `addItemToInventory()`.

26. **FR26.** The system shall execute periodic greenhouse growth ticks and follow-up care across all plants in the current bed hierarchy. [Controller + Iterator over Composite]  
	Implementation: `GreenhouseController::runGrowthTick()` creating a fresh `GreenhouseIterator` from the current `GreenhouseBed` root.

27. **FR27.** The system shall keep stock item availability in sync with the observed plant’s sale readiness for customer display. [Pattern: Observer]  
	Implementation: `StockItem::update()`, `StockItem::getDisplayStatus()`, `StockItem::setIsAvailible()` observing `PlantInstance`.

## Non-functional requirements

Each NFR is stated with its addressed quality attribute in brackets.

1. **NFR1.** The system shall scale linearly with the number of plants during traversal and growth ticks. Traversal is performed by iterators over the Composite, resulting in O($n$) passes for $n$ plants. [Scalability, Performance]  
   Evidence: `ConcreteGreenhouseIterator` performs a depth-first collection; `GreenhouseController::runGrowthTick()` iterates plants once per tick.

2. **NFR2.** A greenhouse growth tick over typical deployments (up to thousands of plants) shall avoid quadratic behaviour and complete using bounded, per-plant constant-time updates. [Performance]  
   Evidence: `PlantInstance::applyGrowthTick()` performs fixed work then defers to the current `PlantState`.

3. **NFR3.** Observers shall not access destroyed subjects; subject shutdown must be communicated before observer detachment. [Reliability]  
   Evidence: `Subject::~Subject()` emits a `SubjectDestroyed` event and clears subscriptions; observers (e.g., `StockItem`) detach appropriately.

4. **NFR4.** The system shall be extensible: new strategies (watering/fertilising), states, handlers, iterators, adapters, and commands can be added without modifying existing client code. [Maintainability, Extensibility]  
   Evidence: Use of interfaces/abstract bases (e.g., `WaterStrategy`, `FertilizeStrategy`, `PlantState`, `CareRequestHandler`, `FileAdapter`, `InventoryIterator`, `PlantCommand`).

5. **NFR5.** Sales interactions shall be simplified through a single façade, reducing coupling between UI/clients and subsystems. [Usability, Maintainability]  
   Evidence: `SalesFacade` wraps `Inventory`, `PaymentProcessor`, and `OrderBuilder`.

6. **NFR6.** Persistence shall be adaptable to multiple file formats without changes to inventory logic. [Portability, Maintainability]  
   Evidence: `Inventory::loadFromFile()` and `saveToFile()` depend on the `FileAdapter` target; format specifics reside in `CSVAdapter`/`TXTAdapter`.

7. **NFR7.** Core components shall be documented and organised for automated documentation generation. [Maintainability, Documentation]  
   Evidence: Doxygen-style headers across `include/*.h` and `src/*.cpp`; complies with project requirement to use Doxygen (Spec p. 7).

8. **NFR8.** The design shall support unit testing via interfaces and clear separation of concerns. [Testability, Maintainability]  
   Evidence: Abstractions with minimal side effects (e.g., iterators, strategies, mediator, command handlers) and existing test files under `tests/` (e.g., `iterator_test.cpp`, `observer_test.cpp`, `facade_test.cpp`).

## Traceability to specification

These requirements align to the Final Project Specification.

---

_Document generated from project sources in `plant-nursery-simulator`._




---

## Source: GUI Requirements.md


# GUI Requirements

This document outlines the features the nursery simulator must expose through a
user interface and proposes interaction patterns for each capability. The goal
is to ensure every subsystem (sales, inventory, greenhouse, staff, adapters,
prototype registry, and lifecycle management) is accessible to end users.

## 1. Home Dashboard
- **Functionality**:
  - Present a high-level summary of inventory levels, recent sales, care alerts,
    and greenhouse health.
  - Surface outstanding staff reminders (observer messages) and pending care
    requests from the chain-of-responsibility pipeline.
  - Highlight plants transitioning into critical states (Withering/Dead).
- **Suggested UI**:
  - Cards or widgets for "Available Stock", "Plants Requiring Care",
    "Recent Orders", and "Imports/Exports".
  - Notification panel fed by `SubjectDestroyed`, `CareRequired`, and
    `AvailabilityChanged` observer events.
  - Click-through links to detailed modules (inventory list, staff tasks, etc.).

## 2. Greenhouse Visualisation
- **Functionality**:
  - Browse the composite greenhouse hierarchy (`GreenhouseBed`, nested beds,
    `PlantInstance` leaves).
  - Inspect plant stats (state, health, water, nutrients, readiness for sale).
  - Trigger manual care actions (water/fertilise via command pattern).
  - Assign staff to beds and register observers.
- **Suggested UI**:
  - Tree or floor-plan view representing beds; selecting a node opens a detail
    panel.
  - Detail pane shows lifecycle state, thresholds, strategies in use, and
    observer subscribers; includes controls to water or fertilise (invokes
    strategies) and to detach/attach staff.
  - Badges or colour-coding indicating Seed/Growing/Mature/Withering/Dead states
    and market readiness.

## 3. Plant Lifecycle Monitor
- **Functionality**:
  - Visualise state transitions defined in `state_lifecycle.md` and
    `PlantState` implementations.
  - Display resource thresholds sourced from `PlantStateThresholds` and current
    plant metrics.
  - Allow simulation of growth ticks, showing projected transitions.
- **Suggested UI**:
  - State machine diagram with live highlighting of the active state.
  - Timeline/history chart of recent growth ticks, water/nutrient changes, and
    health adjustments.
  - Buttons for "Apply Growth Tick", "Manual Water", "Manual Fertilise" to
    drive the command pattern and replay logic.

## 4. Inventory Management
- **Functionality**:
  - View all `StockItem` entries with pricing, availability, and associated
    `PlantInstance` metadata.
  - Add/remove stock (`Inventory::additem`, `removeItem`, `removeItemById`).
  - Register plant types so new items spawn greenhouse instances.
  - Search and filter by name, type, availability, greenhouse location.
  - Inspect and edit pricing, availability status, and observer bindings.
- **Suggested UI**:
  - Tabular inventory view with inline search and filtering controls.
  - Drawer or modal to add/edit an item (name, price, is plant flag) and to
    select associated greenhouse bed when applicable.
  - Quick actions for "Remove", "View Plant Detail", "Register Plant Type".

## 5. File Import & Export (Adapters)
- **Functionality**:
  - Import inventory via TXT/CSV adapters, reconciling plant instances with
    greenhouse beds and prototypes.
  - Export the current inventory snapshot (including plant states) to TXT/CSV.
  - Validate files, surface parsing errors, and offer dry-run previews before
    committing changes.
- **Suggested UI**:
  - Dedicated modal/wizard with steps: choose format, pick file, preview parsed
    entries, resolve validation errors, confirm import.
  - Export button with format selector and download link to generated files.
  - Status log listing timestamped import/export operations with results.

## 6. Sales & Customer Operations (Facade)
- **Functionality**:
  - Register/unregister customers for cart updates.
  - Browse catalog, add items to customer carts, and execute purchases via the
    `SalesFacade::purchaseItem` flow.
  - Build custom orders using the builder pattern, finalise sales, and trigger
    `PaymentProcessor` interactions.
  - Process returns, restocking plant instances when appropriate.
  - Check stock counts quickly from the sales console.
- **Suggested UI**:
  - Customer selector showing active carts and notifications (observer updates).
  - Product catalog grid with "Add to Cart" actions and availability indicators.
  - Cart sidebar listing items, quantities, total price, and checkout controls
    (confirm sale, choose payment method, print receipt).
  - Custom order wizard leveraging the builder: select template, add/remove
    `StockItem`s, review & finalise.
  - Returns dialog allowing barcode/ID lookup with restock confirmation.

## 7. Prototype Registry & Plant Templates
- **Functionality**:
  - Manage `PlantPrototypeRegistry`: add, edit, and remove prototype entries.
  - Configure default water/fertiliser strategies for each prototype.
  - Trigger creation of new plant instances for testing or inventory stocking.
- **Suggested UI**:
  - Registry table with prototype name, type, default strategies, and usage
    counts.
  - Form to upload or define new prototypes (name, type, default strategies).
  - Button to "Spawn Plant Instance" for rapid greenhouse population.

## 8. Staff & Task Management
- **Functionality**:
  - List staff members, their assigned beds, observer subscriptions, and reminder
    queues.
  - Display care reminders and availability updates generated via the observer
    pattern.
  - Manage command queues (water/fertilise tasks) and execute next command.
  - Initiate care requests that traverse the chain-of-responsibility handlers.
  - Send internal messages through the mediator (`NurseryMediator`).
- **Suggested UI**:
  - Staff roster view with badges indicating outstanding reminders.
  - Reminder inbox per staff member with filtering by type (Care, Availability,
    Message).
  - Task queue list with controls to reorder or execute commands.
  - Buttons to submit care requests (choose plant, request type) and to send
    messages to individuals or broadcast.

## 9. Care Strategy Management
- **Functionality**:
  - Configure available watering and fertilising strategies (Frequent, Sparse,
    Seasonal, etc.) and assign them to plants or prototypes.
  - Preview the effect of strategies on water/nutrient levels.
- **Suggested UI**:
  - Strategy library screen describing each implementation and configurable
    parameters (if extended in future).
  - Assignment controls on plant and prototype detail pages (dropdown to choose
    strategy, with apply button).
  - Simulation widget showing expected resource deltas per strategy.

## 10. Order & Return History
- **Functionality**:
  - Maintain a log of all orders built through the builder pattern and the
    facade, including status transitions (Pending, Paid, Fulfilled, Returned).
  - Allow searching and filtering by customer, date, status, or total value.
  - Support return processing by selecting an order, inspecting contained
    `StockItem`s, and initiating restock flows.
- **Suggested UI**:
  - Paginated order history table with expandable rows revealing line items and
    statuses.
  - Quick filters (status chips, date range picker) and export to CSV.
  - Detail drawer for each order with actions: "Mark Paid", "Mark Shipped",
    "Process Return".

## 11. System Administration
- **Functionality**:
  - Configure adapters (file paths, default formats), greenhouse roots, and
    prototype registries used by the facade.
  - Manage user roles/permissions for different modules (optional extension).
  - Provide health checks for subsystems (inventory count vs greenhouse plants,
    orphaned observers, etc.).
- **Suggested UI**:
  - Settings area divided into sections: Inventory, Greenhouse, Sales, Staff,
    Integrations.
  - Diagnostic panel with status indicators and "Run Sync" buttons (e.g.,
    resync greenhouse with inventory, clear dangling observers).

## 12. Error Handling & Notifications
- **Functionality**:
  - Surface adapter parsing errors, payment failures, missing prototypes, and
    observer warnings.
  - Allow users to acknowledge and resolve issues (e.g., register missing
    prototype when import fails).
- **Suggested UI**:
  - Global toast/alert system for transient messages.
  - Persistent notification center listing unresolved issues with suggested
    actions ("Register Prototype", "Retry Payment", "Detach Observer").




---

## Source: Memory Management\Memory management - Composite-Greenhouse.md


# Memory Management - Composite Greenhouse

`GreenhouseBed` owns its children. Each call to `add` transfers ownership of a dynamically allocated component
into the composite, ensuring that destroying a bed destroys every nested `PlantInstance` automatically. When a caller
needs to reuse a plant or sub-bed, it must invoke `release`/`releasePlant` to regain a `std::unique_ptr` before
restructuring the greenhouse.

- Inventory manufactures plants via `createPlantInstance`, keeps prototypes alive separately, and uses `GreenhouseBed::add`
  to hand over plant ownership as soon as a greenhouse root is available. Removing stock calls `releasePlant` so the
  inventory can destroy the instance or transfer it elsewhere.
- The inventory maintains an internal *pending* list of `std::unique_ptr<PlantInstance>` when no greenhouse root is set.
  Once a root bed arrives via `setGreenhouseRoot`, the pending plants migrate into the composite automatically.
- Iterators (`ConcreteGreenhouseIterator`) and controllers still work with borrowed raw pointers and therefore must not
  outlive the greenhouse tree. They never delete plants.
- `PlantInstance` manages its internal state with `std::unique_ptr<PlantState>` while continuing to borrow strategy
  pointers from longer-lived prototypes managed by the registry.




---

## Source: Memory Management\Memory management - GreenhouseController.md


# Memory Management - Greenhouse Controller

`GreenhouseController` orchestrates periodic care over the greenhouse composite. It holds a single `GreenhouseBed*`
that is treated as a **non-owning** pointer:

- The controller never creates or deletes greenhouse beds; it simply remembers which bed should be managed. Ownership
  stays with the subsystem that constructed the composite (usually the `Inventory`).
- `setRootBed()` replaces the pointer and does not perform any clean-up. It is the caller's duty to ensure the previous
  bed remains alive as long as the controller may still reference it.
- During `runGrowthTick()` the controller requests a new iterator via `GreenhouseBed::createIterator()`. The controller
  stores this iterator in a `std::unique_ptr`, guaranteeing automatic destruction once the tick completes. Again, the
  iterator references plants owned by the greenhouse / inventory; it never frees them.

**Responsibility:** maintainers must ensure that the root bed outlives the controller. When disposing of the greenhouse
composite, call `setRootBed(nullptr)` before destroying the bed or destroy the controller first. This prevents the
controller from dereferencing dangling pointers during subsequent ticks.




---

## Source: Memory Management\Memory management - GreenhouseIterator.md


# Memory Management - Greenhouse Iterator

The greenhouse composite exposes traversal through the `GreenhouseIterator` interface. Iterators **never own** the
plants they return; instead they hand out raw `PlantInstance*` values that are guaranteed to remain valid only while
the owning greenhouse structure keeps the plants alive.

- `GreenhouseBed::createIterator()` allocates a concrete iterator (currently via `std::unique_ptr` in call sites) and
  populates it with pointers to plants that are stored elsewhere (e.g. `Inventory`).
- The iterator implementation (`ConcreteGreenhouseIterator`) keeps a local cache of those raw pointers. The cache is
  invalidated only when the iterator is rebuilt. Destroying the iterator does **not** delete the plants.

**Responsibility:** whoever created the plants (typically `Inventory`) remains responsible for their lifetime. As long
as the plants outlive the iterator, the traversal is safe. Callers must avoid storing the raw pointers after the owning
structure (the greenhouse bed) goes out of scope.

This design allows iterators to remain lightweight and avoids duplicating ownership. When additional ownership semantics
are needed (e.g. synchronising with `std::shared_ptr`), the caller should wrap the returned raw pointer immediately.




---

## Source: Memory Management\Memory management - Observer.md


# Memory Management - Observer Pattern

The nursery uses the classic Observer pattern to decouple plant state changes from
UI and staff reactions. Ownership flows remain explicit so that detaching observers
never leaks memory or leaves dangling pointers:

- `Subject` stores observers as non-owning raw pointers. When a subject shuts down it
  broadcasts a `SubjectDestroyed` event with the message "Subject destroyed, observers
  detached." and clears its subscriber list. Observers must drop cached subject
  pointers when they receive this event.
- `PlantInstance` inherits `Subject` and therefore owns the lifecycle of the observer
  list. When greenhouse beds delete plants (via `std::unique_ptr`), the `Subject`
  destructor automatically informs staff and stock entries.
- `StockItem` observes plants but does not own them. It binds to a plant with
  `setPlant` and immediately detaches in its destructor or when it receives
  `SubjectDestroyed`, clearing its borrowed pointer and marking the item unavailable.
- `Staff` members track plants through `observePlant`. The class keeps a set of
  borrowed plant pointers and removes itself either when explicitly told via
  `stopObservingPlant` or when the subject emits a destruction event during plant
  teardown. Staff reminders include the shutdown message so operators know a plant
  left the nursery.
- Other observers (e.g., mediator colleagues) follow the same scheme: observe via the
  raw pointer interface, detach explicitly when done, and rely on the destruction
  broadcast as a final safety net.

**Best practices**

1. Prefer RAII helpers where possible. Stack-based observers (like `StockItem` in unit
   tests) automatically detach when they go out of scope because their destructors
   call `detach`.
2. Always listen for `SubjectDestroyed`. Any component caching a `PlantInstance*`
   should null the pointer inside its observer callback before the subject memory is
   reclaimed.
3. Avoid storing observers in containers by value; instead keep owning pointers or
   references and call `detach` in the owner destructor. This keeps the observer list
   free of dangling entries.

Following these rules allows the Observer subsystem to rely on lightweight raw
pointers without compromising correctness or leaking resources.




---

## Source: Memory Management\Memory management - Plant-Prototype-and-Registry.md


# Memory Management - Plant Prototype Registry

`PlantPrototypeRegistry` stores each prototype in a `std::unique_ptr<Plant>`, meaning the registry owns the lifetime
of every prototype inserted through `addPrototype`. When the registry is destroyed (or a prototype is replaced), the
unique pointer automatically releases the underlying `Plant` instance.

Clone semantics:

- `createPlant()` returns a raw `Plant*` produced by calling `clone()` on the stored prototype. The registry transfers
  ownership of this clone to the caller, who becomes responsible for deleting it when finished.
- `hasPrototype()` simply checks whether a non-null prototype exists; it does not affect ownership.

Usage guidelines:

1. Always pass `std::unique_ptr<Plant>` into `addPrototype`. Handing over a raw pointer risks leaks if an exception is
   thrown before the registry takes ownership.
2. After calling `createPlant()`, wrap the returned raw pointer in a smart pointer (e.g., `std::unique_ptr<Plant>`) in
   the receiving subsystem to ensure proper cleanup.
3. Treat the registry pointer (`PlantPrototypeRegistry*`) as non-owning when passed around. In `facade_test.cpp`, for
   example, we now hold the registry in a `std::unique_ptr` to match this contract.

Following these rules keeps prototype ownership clear: the registry owns the templates, and callers own the clones.




---

## Source: Memory Management\Memory management - State-Plant-Lifecycle.md


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




---

## Source: state_lifecycle.md


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

- **Memory & Ownership** - each `PlantInstance` owns its active state via
  `std::unique_ptr<PlantState>`, guaranteeing the old state is destroyed whenever
  `setState` installs a replacement. Observers attached to the plant receive a
  `SubjectDestroyed` message during teardown so `StockItem` and `Staff` instances
  can null their borrowed pointers safely.
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



