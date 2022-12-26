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

    std::unique_ptr<Game> GameInstance;

    Game::Game(
        const std::string& title,
        INT width,
        INT height
        )
    /*++

    Routine Description:

        Initializes the game.

    Arguments:

        title - The title for the game window.

        width - The width for the game window.

        height - The height for the game window.

    Return Value:

        N/A.

    --*/
    {
        m_logger = Fk::Log::create<Fk::Log::sinks::stderr_color_sink_mt>("FalseKing");
        m_logger->sinks().push_back(Fk::Log::sink_ptr(new Fk::Log::sinks::daily_file_sink_mt(
            "FalseKing",
            0,
            0
            )));
#ifdef _WIN32
        m_logger->sinks().push_back(Fk::Log::sink_ptr(new Fk::Log::sinks::msvc_sink_mt(true)));
#endif
        Fk::Log::set_default_logger(m_logger);

        FK_LOG_INFO("Initializing SDL");
        FK_ASSERT(SDL_Init(SDL_INIT_VIDEO) == 0);

        FK_LOG_INFO("Creating {}x{} window titled {}", width, height, title);
        m_window = std::unique_ptr<Core::Window>(new Core::Window(
            title,
            width,
            height
            ));
    }

    VOID
    Game::Run()
    /*++

    Routine Description:

        Runs the game loop.

    Arguments:

        None.

    Return Value:

        None.

    --*/
    {
        FK_LOG_INFO("Entering game loop");

        m_running = true;
        while ( m_running )
        {
            m_running = m_window->Update();
        }

        FK_LOG_INFO("Game loop ended");
    }

}
