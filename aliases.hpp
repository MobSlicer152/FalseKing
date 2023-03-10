/*++

Copyright (c) 2023 MobSlicer142

Module Name:

    aliases.hpp

Abstract:

    This module defines alternate names for library namespaces and 

--*/

#pragma once

//
// Assert that a condition is true
//

#define FK_ASSERT(Condition) SDL_assert(Condition)

//
// Log a message
//

#define FK_LOG_TRACE(...) SPDLOG_TRACE(__VA_ARGS__)
#define FK_LOG_DEBUG(...) SPDLOG_DEBUG(__VA_ARGS__)
#define FK_LOG_INFO(...) SPDLOG_INFO(__VA_ARGS__)
#define FK_LOG_WARN(...) SPDLOG_WARN(__VA_ARGS__)
#define FK_LOG_ERROR(...) SPDLOG_ERROR(__VA_ARGS__)
#define FK_LOG_CRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__)

namespace Fk
{

    namespace Chrono
    {
        using namespace std::chrono;
        using namespace std::chrono_literals;
    }

    namespace Ecs
    {
        using namespace entt;
    }

    namespace Filesystem
    {
        using namespace std::filesystem;
    }

    namespace Format
    {
        using namespace fmt;
    }

    namespace Log
    {
        using namespace spdlog;
    }

    namespace Math
    {
        using namespace rtm;
    }

}
