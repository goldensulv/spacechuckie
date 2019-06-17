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

void Game::init(int _x, int _y)
{
    m_window = SDL_CreateWindow("Space-Chukie", _x, _y, s_WIDTH, s_HEIGHT, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    m_isRunning = true;    
}

void Game::render(Texture const & _texture, int _x, int _y, int _width, int _height)
{
    SDL_Rect renderQuad = {_x, _y, _width, _height};
    SDL_RenderCopy(m_renderer, _texture.getTexture(), NULL, &renderQuad);
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