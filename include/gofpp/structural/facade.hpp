/**
 * @file facade.hpp
 * @author Noah G. Wood (@NoahGWood)
 * @brief GoF++ Facade pattern implementation
 * @details
 * Simplifies usage of a complex subsystem by exposing a unified interface.
 *
 * @section features Key Features
 * - Wraps multiple subsystem components behind one API.
 * - Reduces coupling between client code and subsystem.
 *
 * @section usage Example Usage
 * ```cpp
 * struct AudioSystem { void playSound() {} };
 * struct GraphicsSystem { void drawFrame() {} };
 *
 * struct GameEngineFacade {
 *     AudioSystem audio;
 *     GraphicsSystem graphics;
 *     void runFrame() { audio.playSound(); graphics.drawFrame(); }
 * };
 * ```
 *
 * @version 0.1
 * @date 2025-08-05
 * @copyright
 * GPLv3 License - Copyright (c) 2025 Noah G. Wood
 */

#pragma once

namespace gofpp {

/**
 * @brief Marker interface for Facade patterns encapsulating subsystems.
 */
class IFacade {
public:
    virtual ~IFacade() = default;
    virtual void initialize() = 0;
    virtual void shutdown() = 0;
};

} // namespace gofpp
