// main.cpp

#include <iostream>

#include "Game.h"
#include "Texture.h"

int main(int argc, char* argv[])
{
    Game game;
    game.init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    SDL_SetRenderDrawColor(game.getRenderer(), 0x00, 0x00, 0x00, 0);

    Texture texture;
    texture.loadFromFile("astronaut_walking_grey.png", game.getRenderer());
    while (game.isRunning())
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        {
            if (SDL_QUIT == event.type)
            {
                game.stop();
            }
            else
            {
                SDL_RenderClear(game.getRenderer());
                std::cout << "width: " << texture.getWidth() << std::endl << "height: " << texture.getHeight() << std::endl;
                game.render(texture, game.getWidth() / 2 - texture.getWidth() / 10, game.getHeight() - texture.getHeight() / 10, texture.getWidth() / 10, texture.getHeight() / 10);
                SDL_RenderPresent(game.getRenderer());
            }
        }
    }

    return 0;
}