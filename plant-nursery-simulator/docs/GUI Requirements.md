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
