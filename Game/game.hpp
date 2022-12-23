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

#include "window.hpp"

namespace Fk
{

    //
    // Big class that contains all the other classes
    //

    class Game
    {
    private:

        std::unique_ptr<Log::logger> m_logger;
        std::unique_ptr<Window> m_window;

    public:

        //
        // Constructor
        //

        Game(const std::string& Title, INT Width, INT Height);

        //
        // Main loop
        //

        void Run();

        //
        // Destructor
        //

        ~Game();
    };

    //
    // Global game instance
    //

    extern Game* GameInstance;

}

#endif // _GAME_
