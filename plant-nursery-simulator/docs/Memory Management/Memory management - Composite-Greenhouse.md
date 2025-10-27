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
