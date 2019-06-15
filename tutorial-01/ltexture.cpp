// ltexture.cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ltexture.h"

extern SDL_Renderer* gRenderer;


static void error(char* _fuck)
{
	printf("%s failed: %s\n", _fuck, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

LTexture::LTexture()
:
    m_texture(nullptr),
    m_height(0),
    m_width(0)
{}

LTexture::~LTexture()
{
    free();
}

bool LTexture::loadFromFile(std::string _path)
{
    free();

	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(_path.c_str());
	if (!loadedSurface)
	{
		error("IMG_Load");
	}
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));

	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
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


void LTexture::free()
{
    if (m_texture)
    {
        SDL_DestroyTexture(m_texture);
        m_width = 0;
        m_height = 0;
    }
}

void LTexture::render(int _x, int _y)
{
    SDL_Rect renderQuad = {_x, _y, m_width, m_height};
    SDL_RenderCopy(gRenderer, m_texture, NULL, &renderQuad);
}

int LTexture::getHeight()
{
    return m_height;
}

int LTexture::getWidth()
{
    return m_width;
}