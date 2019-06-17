// main.cpp

#include <iostream>

#include "Game.h"
#include "Texture.h"

int main(int argc, char* argv[])
{
    Game game;
    game.init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    SDL_SetRenderDrawColor(game.getRenderer(), 0x00, 0xFF, 0xFF, 0);

    Texture texture;
    texture.loadFromFile("background.png");
    while (game.isRunning())
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        {
            if (SDL_QUIT == event.key.keysym.sym)
            {
                game.stop();
            }
            else
            {
                SDL_RenderClear(game.getRenderer());
                game.render(texture, 0, 0, game.getWidth() / 2, game.getHeight() / 2);
                SDL_RenderPresent(game.getRenderer());
            }
        }
    }

    return 0;
}