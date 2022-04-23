#include <iostream>

#include "platform.hpp"
#include "sdl-wrapper.hpp"
#include "Game.hpp"

namespace
{
    bool shouldDisplayFullScreen()
    {
        switch (platform::getCurrentPlatform())
        {
            case platform::Platform::ios:
            case platform::Platform::android:
                return true;

            default:
                return false;
        }
    }
} // namespace

std::pair<uint32_t, uint32_t> platform::sdl::getDisplaySize()
{
    uint32_t displayWidth{0};
    uint32_t displayHeight{0};


    switch (platform::getCurrentPlatform())
    {
        case platform::Platform::ios:
        case platform::Platform::android:
        {
            // For mobile games we will fetch the full screen size.
            SDL_DisplayMode displayMode;
            SDL_GetDesktopDisplayMode(0, &displayMode);
            displayWidth = static_cast<uint32_t>(displayMode.w);
            displayHeight = static_cast<uint32_t>(displayMode.h);
            Game::SCREEN_WIDTH = displayWidth;
            Game::SCREEN_HEIGHT = displayHeight;
            Game::WORLD_WIDTH = Game::SCREEN_WIDTH/100.0;
            Game::WORLD_HEIGHT = Game::SCREEN_HEIGHT/100.0;
            Game::SCALEX = Game::SCREEN_WIDTH/Game::WORLD_WIDTH;
            Game::SCALEY = Game::SCREEN_HEIGHT/Game::WORLD_HEIGHT;
            std::cout << Game::SCREEN_WIDTH << std::endl;
            std::cout << Game::SCREEN_HEIGHT << std::endl;
            std::cout << Game::WORLD_WIDTH << std::endl;
            std::cout << Game::WORLD_HEIGHT << std::endl;
            std::cout << Game::SCALEX << std::endl;
            std::cout << Game::SCALEY << std::endl;
            break;
        }

        default:
        {
            // For other games we'll just show a fixed size window.
            displayWidth = 640;
            displayHeight = 480;
            break;
        }
    }

    return std::make_pair(displayWidth, displayHeight);
}

SDL_Window* platform::sdl::createWindow(const uint32_t& windowFlags)
{
    std::pair<uint32_t, uint32_t> displaySize{platform::sdl::getDisplaySize()};

    SDL_Window* window{SDL_CreateWindow(
        "My Game",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        displaySize.first, displaySize.second,
        windowFlags)};

    if (::shouldDisplayFullScreen())
    {
        SDL_SetWindowFullscreen(window, SDL_TRUE);
    }

    return window;
}
