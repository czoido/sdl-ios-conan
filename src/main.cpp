#include "core/sdl-wrapper.hpp"
#include <iostream>

#include "World.hpp"
#include "Frog.hpp"
#include "Game.hpp"

SDL_Window* window;
SDL_GLContext context;

bool runMainLoop()
{
    SDL_Event event;

    // Each loop we will process any events that are waiting for us.
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return false;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return true;
}

void runApplication()
{
    std::pair<uint32_t, uint32_t> displaySize{platform::sdl::getDisplaySize()};

    std::cout << "Display size is: " << displaySize.first << " x " << displaySize.second << std::endl;

    // Create a new SDL window based on OpenGL.
    window = platform::sdl::createWindow(SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    double elapsedTime = 1.0/60.0;
    World world;

    const b2Vec2 initFrogPos{Game::WORLD_WIDTH/2.0f, Game::WORLD_HEIGHT/2.0f};
    std::unique_ptr<Frog> frog{std::make_unique<Frog>(initFrogPos, world)};

    while (runMainLoop())
    {
        uint32_t startTime = SDL_GetTicks();
        SDL_SetRenderDrawColor( renderer, 120, 120, 230, 0 );
        SDL_RenderClear( renderer );
        
        frog->render(renderer);

        SDL_RenderPresent( renderer );
        uint32_t currTime = SDL_GetTicks();
        elapsedTime = (currTime - startTime) / 1000.0; // Convert to seconds.
        
        world.update(elapsedTime);
    }
    
    // Clean up after ourselves.
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

int main(int, char* [])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == 0)
    {
        std::cout << "Successfully initialised SDL!" << std::endl;

        runApplication();

        SDL_Quit();
    }
    else
    {
        std::cout << "Failed to initialise SDL!" << std::endl;
    }

    return 0;
}
