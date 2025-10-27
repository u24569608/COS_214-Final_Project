# Memory Management - Observer Pattern

The nursery uses the classic Observer pattern to decouple plant state changes from
UI and staff reactions. Ownership flows remain explicit so that detaching observers
never leaks memory or leaves dangling pointers:

- `Subject` stores observers as non-owning raw pointers. When a subject shuts down it
  broadcasts a `SubjectDestroyed` event with the message "Subject destroyed, observers
  detached." and clears its subscriber list. Observers must drop cached subject
  pointers when they receive this event.
- `PlantInstance` inherits `Subject` and therefore owns the lifecycle of the observer
  list. When greenhouse beds delete plants (via `std::unique_ptr`), the `Subject`
  destructor automatically informs staff and stock entries.
- `StockItem` observes plants but does not own them. It binds to a plant with
  `setPlant` and immediately detaches in its destructor or when it receives
  `SubjectDestroyed`, clearing its borrowed pointer and marking the item unavailable.
- `Staff` members track plants through `observePlant`. The class keeps a set of
  borrowed plant pointers and removes itself either when explicitly told via
  `stopObservingPlant` or when the subject emits a destruction event during plant
  teardown. Staff reminders include the shutdown message so operators know a plant
  left the nursery.
- Other observers (e.g., mediator colleagues) follow the same scheme: observe via the
  raw pointer interface, detach explicitly when done, and rely on the destruction
  broadcast as a final safety net.

**Best practices**

1. Prefer RAII helpers where possible. Stack-based observers (like `StockItem` in unit
   tests) automatically detach when they go out of scope because their destructors
   call `detach`.
2. Always listen for `SubjectDestroyed`. Any component caching a `PlantInstance*`
   should null the pointer inside its observer callback before the subject memory is
   reclaimed.
3. Avoid storing observers in containers by value; instead keep owning pointers or
   references and call `detach` in the owner destructor. This keeps the observer list
   free of dangling entries.

Following these rules allows the Observer subsystem to rely on lightweight raw
pointers without compromising correctness or leaking resources.
