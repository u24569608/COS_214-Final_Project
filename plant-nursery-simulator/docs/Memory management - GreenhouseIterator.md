# Memory Management – Greenhouse Iterator

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
