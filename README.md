# GoF++

GoF++ is a header-only library that turns the classic 23 design patterns from *Design Patterns: Elements of Reusable Object-Oriented Software* into modern, RAII-safe, thread-aware templates. It’s built to remove boilerplate, enforce good architecture, and speed up prototyping for tools, games, and apps.
![GoF++ Tests](https://github.com/NoahGWood/gofpp/actions/workflows/tests.yml/badge.svg)

---

## Features

- 23 GoF patterns implemented with modern C++ idioms (templates, concepts).
- RAII enforced: no raw `new/delete`, automatic cleanup.
- Optional threading policies (single or multi-thread safe).
- Header-only: drop into any project.
- Compositional: patterns work together (Observer + Command, Factory + Prototype).
- Editor-friendly: ideal for ImGui/SDL2 tools, game engines, and real-time apps.

## Why GoF++?

- Stop rewriting boilerplate (factories, singletons, undo stacks).
- Learn patterns by *using* them (explicit, type-safe implementations).
- Rapidly scaffold new features: add components, panels, tools without spaghetti.
- Consistent architecture: every system follows the same design flow.

## Installation

Clone and install headers:

```bash
git clone https::github.com/NoahGWood/gofpp.git
cd gofpp
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local ..
make install
```

Now include anywhere:

```c++
#include <gofpp.hpp>
```

## Testing
Testing can be done with ctest
```bash
cmake -DGOFPP_TEST=true -B build
cmake --build build 
cd build
ctest
cd ..
```

## Example

```c++
#include <gofpp.hpp>

class Logger : public gofpp::Singleton<Logger> {
public:
    void log(const std::string& msg) { std::cout << msg << "\n"; }
};

int main() {
    Logger::Instance().log("Hello GoF++!");
}

```

## Patterns Overview

### Creational

- Singleton
- Factory
- Abstract Factory
- Builder
- Prototype

### Structural

- Composite
- Bridge
- Mediator
- Adapter
- Decorator
- Facade
- Flyweight
- Proxy

### Behavioral

- Observer
- Command
- State
- Chain of Responsibility
- Strategy
- Template Method
- Iterator
- Memento
- Interpreter
- Visitor

## Doxygen

Generate Doxygen docs:

```bash
doxygen Doxyfile
```

Browse at `docs/doxygen/html/index.html`

## Contributing

1. Fork & branch (`feature/new-pattern`)
2. Follow existing file structure & test style
3. Add Doxygen comments and NTest tests
4. Submit PR

## License

GPLv3
