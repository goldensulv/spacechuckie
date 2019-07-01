// main.cpp

#include <iostream>

#include "Game.h"
#include "Texture.h"

static const int s_RESIZE = 5;

int main(int argc, char* argv[])
{
    Game game;
    game.init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    SDL_SetRenderDrawColor(game.getRenderer(), 0x00, 0x00, 0x00, 0);

    Texture texture;
    texture.loadFromFile("astronaut_walking_grey.png", game.getRenderer());

    int w_t = texture.getWidth();
    int h_t = texture.getHeight();

    int w_g = game.getWidth();
    int h_g = game.getHeight();

    SDL_Renderer* renderer = game.getRenderer();

    Texture background;
    texture.loadFromFile("background.png", renderer);

    game.render(background, 0, 0, w_g, h_g);

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
                std::cout << "width: " << w_t << std::endl << "height: " << h_t << std::endl;
                game.render(texture, w_g / 2 - w_t / s_RESIZE, h_g - h_t / s_RESIZE, w_t / s_RESIZE, h_t / s_RESIZE);
                SDL_RenderPresent(renderer);
            }
        }
    }

    return 0;
}