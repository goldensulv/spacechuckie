// Game.h
#include <SDL2/SDL.h>

#include "Texture.h"

class Game
{
    public:
        Game();
        ~Game();

        void init(int _x, int _y, int _width, int _height);
        void render(Texture const & _texture);


    private:
        bool            m_isRunning;
        SDL_Window*     m_window;
        SDL_Renderer*   m_renderer;

static const int s_WIDTH;
static const int s_HEIGHT;

};