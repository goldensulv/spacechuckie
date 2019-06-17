// Game.h
#include <SDL2/SDL.h>

#include "Texture.h"

class Game
{
    public:
        Game();
        ~Game();

        void init(int _x, int _y);
        void render(Texture const & _texture, int _x, int _y, int _width, int _height);

        bool isRunning() const;

        void stop();

        SDL_Renderer* getRenderer() const;

        int getWidth() const;
        int getHeight() const;
    private:
        bool            m_isRunning;
        SDL_Window*     m_window;
        SDL_Renderer*   m_renderer;

static const int s_WIDTH;
static const int s_HEIGHT;

};