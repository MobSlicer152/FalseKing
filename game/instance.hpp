/*++

Copyright (c) 2023 MobSlicer152

Module Name:

    instance.hpp

Abstract:

    This module declares the game instance class.

--*/

#pragma once

#include "falseking.hpp"

#include "core/window.hpp"

#include "entity.hpp"

namespace Fk::Game
{

    //
    // Big class that contains all the other classes
    //

    class Instance
    {
    private:

        std::shared_ptr<Log::logger> m_logger;
        std::shared_ptr<Core::Window> m_window;
        Ecs::basic_registry<Entity> m_entityRegistry;
        BOOLEAN m_running;

    public:

        //
        // Constructor
        //

        Instance(
            IN const std::string& title,
            IN INT width,
            IN INT height
            );

        //
        // Destructor
        //

        ~Instance() = default;

        //
        // Main loop
        //

        VOID
        Run();

        //
        // Whether the game is running
        //

        BOOLEAN
        IsRunning()
        {
            return m_running;
        }

    };

    //
    // Global game instance
    //

    extern std::unique_ptr<Instance> GlobalInstance;

}
