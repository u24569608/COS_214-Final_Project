# Research Brief: Plant Nursery Management and Design Influence

## 1. Introduction
The research phase of our project explored how real-world plant nurseries operate, focusing on three domains: plant cultivation, staff coordination, and customer experience. A nursery functions as an ecosystem where biological processes, business operations, and customer interactions intertwine. Understanding this ecosystem guided the modelling of our simulator and informed both class structure and design-pattern selection.

## 2. Plant Care and Growth Management
Nurseries manage a wide diversity of plant species—annuals, perennials, succulents, shrubs, and trees—each with distinct water, soil, and sunlight requirements. According to horticultural sources (Department of Agriculture, 2023; Royal Horticultural Society, 2022), environmental control and scheduling are essential for sustainability. We mirrored these insights through a **Strategy Pattern**, allowing each `Plant` object to adopt a specific `CareStrategy` (“FrequentWatering”, “LowMaintenance”, etc.).  
Lifecycle differences between seedlings and mature plants inspired our **State Pattern**, letting plants transition through “Seedling → Growing → Mature → Sold → Deceased” states. These transitions can move forward or backward (e.g., wilting → revived) to reflect real conditions.

## 3. Staff Coordination and Roles
Research into nursery workforce organisation showed that tasks are distributed among horticulturists, cashiers, and logistics staff who must communicate effectively. This motivated the use of the **Mediator Pattern** to centralise communication through a `NurseryHub` object that coordinates between `Staff`, `Inventory`, and `CustomerService`.  
Different staff behaviours (watering, fertilising, advising) are implemented using the **Command Pattern**, allowing dynamic task scheduling while preserving decoupling between requesters and executors.

## 4. Customer Experience and Sales Workflow
Customer studies (Garden Centre Magazine, 2024) highlight personalisation—pot style, wrapping, delivery—as a key differentiator. To simulate this, the **Decorator Pattern** was adopted to wrap `Plant` objects with optional features like `GiftWrap` or `DecorativePot`.  
The sales floor interaction and browsing flow were mapped into a **Sequence Diagram** representing queries from `Customer` to `Staff` and inventory updates, ensuring alignment with real-world purchase behaviour.

## 5. System Scalability and Extensibility
Modern nurseries expand continuously, adding new plant categories and services. This motivated a modular, pattern-driven design. The **Factory Method Pattern** simplifies adding new `Plant` types, while the **Observer Pattern** keeps displays and stock reports consistent when inventory changes.  
Reliability and maintainability were prioritised—each subsystem (greenhouse, sales, staff) remains independently testable, supporting scalability and parallel development.

## 6. Assumptions and Definitions
- Plants are abstracted to key attributes (name, water need, sunlight level, state) rather than biological precision.  
- Customer preferences are limited to purchasable features (pot, wrapping, delivery).  
- The nursery operates in a steady climate with discrete time steps for simulation purposes.  
- Financial tracking is simplified to focus on interaction flow, not accounting accuracy.

## 7. Conclusion
Research into horticulture and business management directly shaped the simulator’s architecture. Each identified process—plant growth, staff cooperation, and customer interaction—maps cleanly to specific design patterns, ensuring the final system is flexible, maintainable, and realistic in simulating an evolving nursery environment.

## References
- Department of Agriculture. (2023). *Greenhouse Management and Plant Propagation Guide.* Pretoria.  
- Royal Horticultural Society. (2022). *Plant Care Best Practices.* London.  
- Garden Centre Magazine. (2024). *Trends in Customer Personalisation and Retail Nurseries.*  
- University of Pretoria COS214 Project Specification (2025).
