# Philosophy

## Core Principles

- **Simplicity**: Patterns should remove boilerplate, not add complexity.
- **Modern C++**: Use templates, concepts, RAII, `unique_ptr` over macros.
- **Composability**: Patterns integrate cleanly (Observer + Command, State + Mediator).
- **Flexibility**: Optional threading policy; single-thread by default.
- **Education**: Clear, self-documenting implementations double as learning tools.

### Intended Use Cases

- **Game engines and editors** (ECS, ImGui, SDL2, Vulkan/OpenGL).
- **Real-time tools** (level editors, CAD-like UIs).
- **Rapid prototyping** (clean architecture without giant frameworks).
- **Teaching design patterns** (concrete examples, modern best practices).

### Design Process

- Start high-level → map patterns via decision flow → refine into pseudocode → implement.
- Only add patterns when needed — avoid “pattern soup.”
- Patterns should integrate with lifecycle (Init → Active → Shutdown) and threading if applicable.

### Not a Framework

GoF++ is **not** an engine or ECS itself — it’s the *architectural glue* you apply to those systems.