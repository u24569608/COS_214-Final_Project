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
