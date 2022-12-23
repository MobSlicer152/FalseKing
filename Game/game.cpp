/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    game.cpp

Abstract:

    This module implements the Game class.

Author:

    MobSlicer152 23-Dec-2022

Revision History:

    23-Dec-2022    MobSlicer152

        Created game.cpp.

--*/

#include "game.hpp"

namespace Fk
{

    Game::Game(const std::string& Title, INT Width, INT Height)
    {
        m_window = std::unique_ptr<Window>(new Window(Title, Width, Height));
    }

}
