/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    game.hpp

Abstract:

    Declares the Game class and the global Game instance.

Author:

    MobSlicer152 23-Dec-2022

Revision History:

    23-Dec-2022    MobSlicer152

        Created game.hpp.

--*/

#ifndef _GAME_
#define _GAME_

#include "falseking.hpp"

#include "core/window.hpp"

namespace Fk
{

    //
    // Big class that contains all the other classes
    //

    class Game
    {
    private:

        std::shared_ptr<Log::logger> m_logger;
        std::shared_ptr<Core::Window> m_window;
        BOOLEAN m_running;

    public:

        //
        // Constructor
        //

        Game(
            IN const std::string& title,
            IN INT width,
            IN INT height
            );

        //
        // Destructor
        //

        ~Game() = default;

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

    extern std::unique_ptr<Game> GameInstance;

}

#endif // _GAME_
