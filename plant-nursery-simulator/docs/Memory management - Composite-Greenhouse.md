# Memory Management - Composite Greenhouse

`GreenhouseBed` owns its children. Each call to `add` transfers ownership of a dynamically allocated component
into the composite, ensuring that destroying a bed destroys every nested `PlantInstance` automatically. When a caller
needs to reuse a plant or sub-bed, it must invoke `release`/`releasePlant` to regain a `std::unique_ptr` before
restructuring the greenhouse.

- Inventory manufactures plants via `createPlantInstance`, keeps prototypes alive separately, and uses `releasePlant`
  to reclaim instances when stock is removed.
- Iterators and controllers still work with borrowed raw pointers and therefore must not outlive the greenhouse tree.
- `PlantInstance` manages its internal state with `std::unique_ptr<PlantState>` while continuing to borrow strategy
  pointers from longer-lived prototypes.
