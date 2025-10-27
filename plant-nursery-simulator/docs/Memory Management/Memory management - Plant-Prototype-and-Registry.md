# Memory Management - Plant Prototype Registry

`PlantPrototypeRegistry` stores each prototype in a `std::unique_ptr<Plant>`, meaning the registry owns the lifetime
of every prototype inserted through `addPrototype`. When the registry is destroyed (or a prototype is replaced), the
unique pointer automatically releases the underlying `Plant` instance.

Clone semantics:

- `createPlant()` returns a raw `Plant*` produced by calling `clone()` on the stored prototype. The registry transfers
  ownership of this clone to the caller, who becomes responsible for deleting it when finished.
- `hasPrototype()` simply checks whether a non-null prototype exists; it does not affect ownership.

Usage guidelines:

1. Always pass `std::unique_ptr<Plant>` into `addPrototype`. Handing over a raw pointer risks leaks if an exception is
   thrown before the registry takes ownership.
2. After calling `createPlant()`, wrap the returned raw pointer in a smart pointer (e.g., `std::unique_ptr<Plant>`) in
   the receiving subsystem to ensure proper cleanup.
3. Treat the registry pointer (`PlantPrototypeRegistry*`) as non-owning when passed around. In `facade_test.cpp`, for
   example, we now hold the registry in a `std::unique_ptr` to match this contract.

Following these rules keeps prototype ownership clear: the registry owns the templates, and callers own the clones.
