# Research Brief: Plant Nursery Management and Design Influence

## 1. Introduction
The research phase of this project examined how real-world plant nurseries function, focusing on three core domains: plant cultivation, staff coordination, and customer interaction. A nursery operates as a dynamic ecosystem where biological growth, human management, and customer engagement coexist. Understanding these interdependent systems guided the conceptual modelling of the Plant Nursery Simulator, shaping both its class architecture and the selection of design patterns. The goal was to design a simulation that reflects the complexity and adaptability of a real nursery while maintaining software clarity and extensibility.

## 2. Plant Care and Growth Management
Nurseries manage a wide diversity of plant species—annuals, perennials, succulents, shrubs, and trees—each with distinct water, soil, and sunlight requirements. According to horticultural sources (Department of Agriculture, 2023; Royal Horticultural Society, 2022), environmental control and scheduling are essential for sustainability.

We mirrored these insights through two key patterns:

- **Strategy Pattern**: Allows each `Plant` object to adopt specific, swappable `CareStrategy` algorithms (“FrequentWatering”, “LiquidFertilizer”, etc.), decoupling the plant from the specific implementation of its care.
- **State Pattern**: Inspired by plant lifecycles, letting `Plant` objects transition through “SeedState → GrowingState → MatureState → WitheringState → DeadState”. This allows a plant's behavior (e.g., its response to being watered) to change based on its current condition.

## 3. Staff Coordination and Roles
Research into nursery workforce organisation showed that tasks are distributed among staff who must communicate effectively. This motivated the use of the **Mediator Pattern** to centralise communication through a `NurseryMediator` object that coordinates between `Staff`, `Inventory`, and `CustomerService`, reducing direct dependencies.

Staff tasks are implemented using several patterns:

- **Command Pattern**: Encapsulates a request (e.g., "water plant") as an object (`WaterPlant`, `FertilizePlant`). This allows for dynamic task queuing and logging while decoupling the task issuer from the executor.
- **Chain of Responsibility Pattern**: Used to process these commands. A request is passed along a chain of handlers (`WateringHandler`, `FertilizingHandler`), allowing different parts of the system to process only the tasks relevant to them.

## 4. Customer Experience and Sales Workflow
Customer studies (Garden Centre Magazine, 2024) highlight personalisation—pot style, wrapping, delivery—as a key differentiator.

To simulate this, the **Builder Pattern** was adopted. An `OrderDirector` uses a `CustomOrderBuilder` to construct a complex `Order` object step-by-step. This provides flexibility in creating orders with various optional features (pots, gift wrapping) without resorting to a complex constructor.

The entire sales subsystem, including the order builder and payment processing, is unified under a **Facade Pattern** (`SalesFacade`). This provides a single, simplified interface for external clients (like the GUI) to interact with, hiding the internal complexity of the sales workflow.

## 5. System Scalability and Extensibility
Modern nurseries expand continuously, adding new plant categories, greenhouse sections, and services. This motivated a modular, pattern-driven design.

- **Object Creation**: The **Prototype Pattern**, via a `PlantPrototypeRegistry`, is used to add new `Plant` types. New plant objects are created by cloning registered prototypes, which is more flexible than hard-coding class names in a factory.
- **System Structure**: The **Composite Pattern** (`GreenhouseComponent`) models the physical nursery layout as a tree structure. This allows clients to treat individual `GreenhouseBeds` and entire `Greenhouse` composites uniformly. The **Iterator Pattern** (`GreenhouseIterator`) is provided to traverse this structure without exposing its internal representation.
- **Data & Updates**: The **Observer Pattern** keeps displays and reports consistent. The `Inventory` (Subject) notifies all registered Observers (e.g., GUI frames) when its stock level changes. For data persistence, the **Adapter Pattern** (`CSVAdapter`, `TXTAdapter`) is used to allow the system to read and write inventory data from different file formats (like CSV or TXT) through a single, common interface.

## 6. Assumptions and Definitions
- Plants are abstracted to key attributes (name, water need, sunlight level, state) rather than biological precision.
- Customer preferences are limited to purchasable features (pot, wrapping, delivery) managed by the builder.
- The nursery operates in a steady climate with discrete time steps for simulation purposes.
- Financial tracking is simplified to focus on interaction flow, not accounting accuracy.

## 7. Conclusion
Research into horticulture and business management directly shaped the simulator’s architecture. Each identified process—plant growth, staff cooperation, data management, and customer interaction—maps cleanly to specific design patterns, ensuring the final system is flexible, maintainable, and realistic in simulating an evolving nursery environment.

## 8. References
- Department of Agriculture. (2023). *Greenhouse Management and Plant Propagation Guide.* Pretoria.
- Royal Horticultural Society. (2022). *Plant Care Best Practices.* London.
- Garden Centre Magazine. (2024). *Trends in Customer Personalisation and Retail Nurseries.*
