/*++

Copyright (c) 2022 MobSlicer152

Module Name:

    falseking.hpp

Abstract:

    Global header with basic shared definitions.

Author:

    MobSlicer152 23-Dec-2022

Revision History:

    23-Dec-2022    MobSlicer152

        Created falseking.hpp.

--*/

#ifndef _FALSEKING_
#define _FALSEKING_

#include <cerrno>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "box2d/box2d.h"

#include "entt/entt.hpp"

#include "rtm/macros.h"
#include "rtm/math.h"
#include "rtm/matrix3x3d.h"
#include "rtm/matrix4x4d.h"
#include "rtm/quatd.h"
#include "rtm/qvvd.h"
#include "rtm/scalard.h"
#include "rtm/type_traits.h"
#include "rtm/vector4d.h"

#include "SDL3/SDL.h"

#define SPDLOG_HEADER_ONLY
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/msvc_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#define FMT_HEADER_ONLY
#include "spdlog/fmt/bundled/format.h"

#include "aliases.hpp"
#include "types.hpp"

#endif // _FALSEKING_
