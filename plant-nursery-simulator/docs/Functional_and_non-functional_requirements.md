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
