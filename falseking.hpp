/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    falseking.hpp

Abstract:

    Global header with basic shared definitions.

Revision History:

    23-Dec-2022    MobSlicer152

        Created falseking.hpp.

--*/

#pragma once

#include <chrono>
#include <cstdio>
#include <filesystem>
#include <limits>
#include <string>
#include <vector>

#include "box2d/box2d.h"
#include "rtm/math.h"
#include "SDL3/SDL.h"
#include "spdlog/spdlog-inl.h"
#include "spdlog/fmt/bundled/format-inl.h"

#include "types.hpp"

namespace Fk
{

    namespace Chrono
    {
        using namespace std::chrono;
        using namespace std::chrono_literals;
    }

    namespace Fmt
    {
        using namespace fmt;
    }

    namespace Fs
    {
        using namespace std::filesystem;
    }

    namespace Log
    {
        using namespace spdlog;
    }

}
