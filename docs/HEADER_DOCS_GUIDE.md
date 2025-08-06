# GoF++ Header Documentation Guide

All headers in GoF++ must begin with a **Doxygen-style documentation block**.  
This ensures consistency, ease of navigation, and auto-generated docs.

---

## Template

@verbatim

```
/**
 * @file filename.hpp
 * @author Your Name (@github-handle)
 * @brief Short summary of the pattern
 * @details
 * Longer description, purpose of this pattern, and what makes it special in GoF++.
 *
 * @section features Key Features
 * - Bullet points of key features
 * - Integration notes (threading, RAII, ECS usage)
 *
 * @section usage Example Usage
 * ```cpp
 * // Example code using the pattern
 * ```
 *
 * @section threading Threading
 * Notes about thread safety and policies.
 *
 * @version 0.x
 * @date YYYY-MM-DD
 * @copyright
 * GPLv3 License - Copyright (c) YYYY Your Name
 */
```

@endverbatim

## Guidelines

- Always include **usage example** (copy-pasteable).
- Mention **threading policy** if applicable.
- Use **`@section features Key Features`** to highlight implementation advantages.
- Keep brief descriptions in `@brief`, longer in `@details`.
- Update **version/date** on significant changes.

## Example

See `creational/singleton.hpp` for a complete example.
