\mainpage Plant Nursery Simulator

\section intro Introduction

The Plant Nursery Simulator is the COS 214 final project for Team Plant Palace.
It models a smart greenhouse that coordinates plant care, customer orders, staff,
and stock-keeping by composing several behavioural and structural design patterns.

Key responsibilities:
- Track individual plants via prototype cloning and lifecycle state transitions.
- Coordinate plant care through commands, strategies, and a chain of responsibility.
- Synchronise greenhouse areas and retail operations with mediator, observer, and facade patterns.
- Persist and share stock information using adapter abstractions for CSV and TXT files.

\section patterns Design Patterns

The implementation deliberately demonstrates multiple patterns. The most prominent are:

- \b Composite for representing the greenhouse layout (`GreenhouseComponent`, `GreenhouseBed`, `PlantInstance`).
- \b Iterator for traversing plant beds and inventory items (`ConcreteGreenhouseIterator`, `ConcreteInventoryIterator`).
- \b Observer to notify staff members about plant care requirements (`Subject`, `Observer`, `Staff`).
- \b State to capture plant growth phases (`SeedState`, `GrowingState`, `MatureState`, `WitheringState`, `DeadState`).
- \b Strategy to vary watering and fertilising routines (`WaterStrategy`, `FertilizeStrategy` and their derivatives).
- \b Command for deferred care actions (`PlantCommand`, `WaterPlant`, `FertilizePlant`).
- \b Chain of Responsibility for automated care request handling (`CareRequestHandler` and specialisations).
- \b Mediator to coordinate floor staff communication (`NurseryMediator`, `Colleague`, `Customer`, `Staff`).
- \b Prototype for cloning plant templates (`Plant`, `PlantPrototypeRegistry`).
- \b Facade to expose high-level sales operations (`SalesFacade`).

\section modules Module Overview

\subsection plants Plant Domain

Primarily defined in `include/Plant.h`, `include/PlantInstance.h`, and the `src/Plant*.cpp`
files. These encapsulate how plants are instantiated, cared for, and transitioned between states.

\subsection inventory Inventory Management

Inventory and stock management live in `include/Inventory.h`, `include/StockItem.h`,
and related iterator classes. They coordinate with the sales facade and mediator to
reflect availability changes when plants mature or orders are fulfilled.

\subsection io Data Access Layer

Adapters in `include/CSVAdapter.h` and `include/TXTAdapter.h` abstract storage concerns,
allowing the simulator to read and write plant stock data in multiple formats.

\subsection ui_gui GUI Integration

The GUI layer (under `GUI/`) consumes the facade and iterator interfaces to populate views.

\section build Building and Documentation

To generate the documentation:

```bash
doxygen Doxyfile
```

The HTML output will be placed under `docs/doxygen/html`. Open `docs/doxygen/html/index.html`
in a browser to browse the API reference. Warning messages are enabled so that undocumented
members are reported during the generation step.
