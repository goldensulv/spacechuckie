// Texture.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Texture.h"


extern void error(char* _fuck)
{
	printf("%s failed: %s\n", _fuck, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

Texture::Texture()
:
    m_texture(nullptr),
    m_height(0),
    m_width(0)
{}

Texture::~Texture()
{
    free();
}

bool Texture::loadFromFile(std::string _path, SDL_Renderer* _renderer)
{
    free();

	SDL_Texture* newTexture = nullptr;
	SDL_Surface* tempLoadedSurface = IMG_Load(_path.c_str());
	if (!tempLoadedSurface)
	{
		error("IMG_Load");
	}
    // Optimize image (is this needed?)
    SDL_Surface* loadedSurface = SDL_ConvertSurface(tempLoadedSurface, tempLoadedSurface->format, 0);
	SDL_assert(loadedSurface);
	SDL_FreeSurface(tempLoadedSurface);

    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));

	newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (!newTexture)
	{
		error("SDL_CreateTextrueFromSurface");
	}
    m_width = loadedSurface->w;
    m_height = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

    m_texture = newTexture;

	return m_texture != nullptr;
}


void Texture::free()
{
    if (m_texture)
    {
        SDL_DestroyTexture(m_texture);
        m_width = 0;
        m_height = 0;
    }
}
/*
void Texture::render(int _x, int _y)
{
    SDL_Rect renderQuad = {_x, _y, m_width, m_height};
    SDL_RenderCopy(gRenderer, m_texture, NULL, &renderQuad);
}
*/

SDL_Texture* Texture::getTexture() const
{
    return m_texture;
}

int Texture::getHeight() const
{
    return m_height;
}

int Texture::getWidth() const
{
    return m_width;
}