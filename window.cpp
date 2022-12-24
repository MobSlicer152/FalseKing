/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    window.cpp

Abstract:

    This module implements the Window class.

Author:

    23-Dec-2022 MobSlicer152

Revision History:

    23-Dec-2022    MobSlicer152

        Created window.cpp.

--*/

#include "window.hpp"

namespace Fk
{

    Window::Window(
        IN const std::string& title,
        IN INT width,
        IN INT height
        )
    /*++

    Routine Description:

        Creates a window.

    Arguments:

        title - The title for the window.

        width - The width for the window.

        height - The height for the window.

    Return Value:

        N/A.

    --*/
    {
        m_handle = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_ALLOW_HIGHDPI |
            SDL_WINDOW_RESIZABLE
            );
        FK_ASSERT(m_handle != NULL);

        m_title = SDL_GetWindowTitle(m_handle);
        SDL_GetWindowSize(
            m_handle,
            &m_width,
            &m_height
            );
        m_id = SDL_GetWindowID(m_handle);
    }

    BOOLEAN
    Window::Update()
    /*++

    Routine Description:

        Processes events and updates members.

    Arguments:

        None.

    Return Value:

        true - Window is still open.

        false - Window has been asked to close.

    --*/
    {
        BOOLEAN continueRunning;
        SDL_Event event;

        continueRunning = true;
        while ( SDL_PollEvent(&event) )
        {
            if ( event.window.windowID == m_id )
            {
                switch ( event.type )
                {
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                    FK_LOG_INFO("Window {} resized from {}x{} to {}x{}",
                        m_title,
                        m_width,
                        m_height,
                        event.window.data1,
                        event.window.data2
                        );
                    m_width = event.window.data1;
                    m_height = event.window.data2;
                    break;
                case SDL_WINDOWEVENT_CLOSE:
                    FK_LOG_INFO("Window {} close requested", m_title);
                    continueRunning = false;
                    break;
                default:
                    FK_LOG_TRACE("Window {} ignoring event {}", m_title, event.type);
                    break;
                }
            }
            else
            {
                SDL_PushEvent(
                    &event
                    );
            }
        }

        return continueRunning;
    }

}
