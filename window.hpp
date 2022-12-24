/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    window.hpp

Abstract:

    Declares the Window class, which abstracts an SDL_Window and SDL_Renderer.

Author:

    23-Dec-2022 MobSlicer152

Revision History:

    23-Dec-2022    MobSlicer152

        Created window.hpp.

--*/

#ifndef _WINDOW_
#define _WINDOW_

#include "falseking.hpp"

namespace Fk
{

    class Window
    {
    protected:

        SDL_Window* m_handle;
        SDL_Renderer* m_renderer;
        std::string m_title;
        INT m_width;
        INT m_height;
        INT m_id;

    public:

        //
        // Create the window and store information.
        //

        Window(
            const std::string& title,
            INT width,
            INT height
            );

        //
        // Destroy the window.
        //

        ~Window()
        {
            SDL_DestroyWindow(m_handle);
        }

        //
        // Process events and swap framebuffers.
        //

        BOOLEAN
        Update();

        //
        // Get the handle
        //

        SDL_Window*
        GetHandle()
        const
        noexcept
        {
            return m_handle;
        }

        //
        // Get the renderer
        //

        SDL_Renderer*
        GetRenderer()
        const
        noexcept
        {
            return m_renderer;
        }

        //
        // Get the title
        //

        const
        std::string&
        GetTitle()
        const
        noexcept
        {
            return m_title;
        }

        //
        // Get the width
        //

        INT
        GetWidth()
        const
        noexcept
        {
            return m_width;
        }

        //
        // Get the height
        //

        INT
        GetHeight()
        const
        noexcept
        {
            return m_height;
        }

        //
        // Get the width and height
        //

        VOID
        GetSize(
            INT& width,
            INT& height
            )
        const
        noexcept
        {
            width = m_width;
            height = m_height;
        }

        //
        // Get SDL window ID
        //

        INT
        GetId()
        const
        noexcept
        {
            return m_id;
        }

    };

}

#endif // _WINDOW_
