// Game.cpp

#include "Game.h"

const int Game::s_HEIGHT = 480;
const int Game::s_WIDTH  = 640;

Game::Game()
:   m_window(nullptr)
   ,m_renderer(nullptr)
   ,m_isRunning(false)
{
}

Game::~Game()
{
    m_isRunning = false;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

void Game::init(int _width, int _height)
{
    if (0 == SDL_Init(SDL_INIT_EVERYTHING))
    {
        m_window = SDL_CreateWindow("Space-Chukie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, s_WIDTH, s_HEIGHT, 0);
        if (nullptr == m_window)
        {
            error("SDL_CreateWindow");
        }
        m_renderer = SDL_CreateRenderer(m_window, -1, 0);
        if (nullptr == m_renderer)
        {
            error("SDL_CreateRenderer");
        }
        m_isRunning = true;
    }
}


void Game::render(Texture const & _texture, int _x, int _y, int _width, int _height)
{
    SDL_Rect renderQuad = {_x, _y, _width, _height};
    SDL_RenderCopy(m_renderer, _texture.getTexture(), NULL, &renderQuad);
}

bool Game::isRunning() const
{
    return m_isRunning;
}


void Game::stop()
{
    m_isRunning = false;
}

SDL_Renderer* Game::getRenderer() const
{
    return m_renderer;
}

int Game::getWidth() const
{
    return s_WIDTH;
}

int Game::getHeight() const
{
    return s_HEIGHT;
}