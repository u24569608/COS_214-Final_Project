# Memory Management - Composite Greenhouse

The greenhouse composite follows the classic Composite pattern: `GreenhouseBed` is the composite node and `PlantInstance`
acts as the leaf. Beds now **own** their child components via `std::unique_ptr`, which guarantees that every plant stored
inside a bed is destroyed automatically when the bed goes out of scope.

- `GreenhouseBed::add` transfers ownership from the caller into the bed. Prefer passing a `std::unique_ptr<GreenhouseComponent>`
  (derived types convert implicitly). The legacy raw-pointer overload also assumes ownership—only hand over dynamically
  allocated objects that are no longer owned elsewhere.
- `GreenhouseBed::remove` releases and destroys the child in-place. If the caller needs to repurpose a component, call
  `release` or `releasePlant` beforehand to regain a `std::unique_ptr`.
- `Inventory` creates greenhouse-backed plants with `createPlantInstance`. Until a root bed is supplied, these plants live
  in an internal pending list. Once a bed is available, ownership transfers to the composite, and inventory relies on
  `releasePlant` to reclaim and delete instances when stock is removed.
- `GreenhouseIterator` exposes non-owning raw pointers that reference bed-managed plants. The iterator must never outlive
  the greenhouse hierarchy that produced it.
- `GreenhouseController` keeps a non-owning pointer to the root bed and simply drives care cycles; the controller does not
  participate in lifetime management.
- `PlantInstance` continues to own its lifecycle state (`std::unique_ptr<PlantState>`) while borrowing references to
  strategies and prototypes, which must remain valid for as long as the plant does.

Implications:

1. **Beds clean up automatically.** Destroying a bed cascades through its children, ensuring no plants leak even in deeply
   nested composite structures.
2. **Explicit releases guard reallocations.** When an external subsystem (e.g., inventory, sales) needs to remove a plant
   without destroying it immediately, call `releasePlant` to obtain an owning pointer before any structural changes.
3. **Iterators remain snapshots.** Because iterators hand out raw pointers, callers must finish traversal before beds are
   dismantled or released.
4. **Prototype ownership stays with Inventory.** The inventory tracks cloned prototypes in `prototypeOwners` and erases
   them whenever the corresponding plant is reclaimed from a bed.

When introducing new composite operations, ensure they respect these ownership boundaries—either transfer a `std::unique_ptr`
into the bed or explicitly `release` it back before handing the plant to another subsystem.
