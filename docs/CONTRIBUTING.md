# Contributing

### Welcome to GoF++

Thank you for considering contributing to GoF++! This project’s goal is to modernize the 23 Gang of Four design patterns using C++20, emphasizing RAII, threading safety, and clean, educational code.

## Core Guidelines

### 1. Philosophy

- Patterns must reduce boilerplate, not increase it.
- Use templates and concepts, avoid unnecessary macros.
- Favor RAII (`unique_ptr`, `shared_ptr`) over manual memory management.
- Keep code header-only for ease of integration.
- Ensure thread-safety is optional via policy classes (no hard-coded mutexes).

---

### 2. Pattern Implementation

- Implement one pattern per header (e.g., `singleton.hpp`, `observer.hpp`).
- Each header must:
  - Be self-contained (`#pragma once` + required includes).
  - Include usage examples in comments.
  - Provide unit tests in `tests/`.

------

### 3. Code Style

- Follow modern C++ guidelines:
  - Use `snake_case` for variables, `PascalCase` for types, `camelCase` for methods.
  - Use `explicit` constructors when needed.
  - Prefer `constexpr` and `noexcept` when applicable.
- Keep headers minimal: no heavy includes unless required.

---

### 4. Adding New Patterns

1. Check if the pattern already exists.
2. Discuss in issues (or document reasoning in PR).
3. Follow this structure:
   - Create header in `include/gofpp/`.
   - Add tests in `tests/`.
   - Update `README.md` and `PHILOSOPHY.md` if relevant.

---

### 5. Threading

- Use `ThreadPolicy` templates for optional locking (default `SingleThreaded`).
- Do not introduce global locks or hard-coded concurrency behavior.

---

### 6. Documentation

- Update README with new patterns/examples.
- Add usage comments at top of each pattern header.

---

### 7. Tests

- Write small, focused tests:
  - Verify correctness (e.g., singleton returns same instance).
  - Test RAII behavior (destructors trigger cleanup).
  - Test threading behavior (if applicable).

------

### 8. Example Contribution Flow

- Fork → branch (`feature/observer-pattern`) → implement → add tests → PR.