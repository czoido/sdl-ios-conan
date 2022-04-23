#pragma once

namespace platform
{
    enum class Platform
    {
        mac,
        ios,
        android,
        emscripten
    };

    Platform getCurrentPlatform();
} // namespace game
