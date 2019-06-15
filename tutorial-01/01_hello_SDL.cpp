/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

#include "ltexture.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_TOTAL
};



/* Forward declarations */
static void error(char* _fuck);
static void close();
static void close(SDL_Window* _window);
static void init_surface(SDL_Surface** _surface, SDL_Window* _window);
static void init_window(SDL_Window** _window);
static void update(SDL_Window* _window);
static SDL_Surface* optimize_image(SDL_Surface* _surface);
static SDL_Surface* load(SDL_Surface* _surface, char* _img);
static void load(SDL_Surface* _surfaces[], size_t _nSurfaces);
static void free(SDL_Surface* _surface);
static void free(SDL_Surface* _surfaces[], size_t _nSurfaces);
static SDL_Surface* img_load(SDL_Surface* _surface, char* _img);
static SDL_Texture* load_texture(std::string path);
static SDL_Texture* load_texture(SDL_Renderer* _renderer, std::string path);

/* Global variables */
char* images[] = {"img01.bmp", "img02.bmp", "img03.bmp", "img04.bmp", "img05.bmp"}; // bmp images
char* jpg_img = "img01.jpg";

SDL_Window* gWindow = nullptr;
extern SDL_Renderer* gRenderer = nullptr;
SDL_Texture* gTexture = nullptr;

LTexture gBackgroundTexture;
LTexture gItemTexture;



/************** main *************/
/******************************* */
/******************************* */
/******************************* */


int main(int argc, char* args[])
{
	init_window(&gWindow);
/*
	SDL_Surface* screenSurface = nullptr;

	init_surface(&screenSurface, gWindow);
*/
	// Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!gRenderer)
	{
		error("SDL_CreateRenderer");
	}
/*
	// Initialize renderer colors
*/	SDL_SetRenderDrawColor(gRenderer, 169, 6, 75, 121);
/*
	// Load media (texture)
	gTexture = load_texture(images[0]);
*//*
	// load multiple bmp surfaces
	SDL_Surface** keySurfaces = new SDL_Surface*[KEY_PRESS_SURFACE_TOTAL];
	load(keySurfaces, KEY_PRESS_SURFACE_TOTAL);

	// load single jpg image
	int imgFlags = IMG_INIT_JPG;
	if (! (IMG_Init(imgFlags) & imgFlags))
	{
		error("IMG_Init");
	}
	SDL_Surface* jpg_img_surface = img_load(jpg_img_surface, jpg_img);


	SDL_Surface* currentSurface = jpg_img_surface;
*/

	// Create a top-left viewport
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.h = SCREEN_HEIGHT / 4;
	topLeftViewport.w = SCREEN_WIDTH / 4;

	bool quit = false;
	SDL_Event event;

	gBackgroundTexture.loadFromFile("foo.png");
	gItemTexture.loadFromFile("background.png");

/* Game loop */

	while (! quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (SDL_QUIT == event.type)
			{
				quit = true;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(gRenderer);

				gBackgroundTexture.render(0, 0);

				gItemTexture.render(240, 190);

				SDL_RenderPresent(gRenderer);
			}
			
			// Drawing shapes onto screen
/*
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				// Render red filled quad
				SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
				SDL_RenderFillRect(gRenderer, &fillRect);
				// Render yellow outline quad
				SDL_Rect outlineRect = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4 };
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
				SDL_RenderDrawRect(gRenderer, &outlineRect);
				
				gTexture = load_texture(gRenderer, images[0]);
				// Render blue diagonal
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
				SDL_RenderDrawLine(gRenderer, 0, 0, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4);

				SDL_RenderPresent(gRenderer);
			}
*/		}	
			// Handeling of key-press events	
/*			else if (SDL_KEYDOWN == event.type)
			{
				switch (event.key.keysym.sym)
				{
					case (SDLK_ESCAPE):
						quit = true;
						break;
					case (SDLK_UP):
						currentSurface = keySurfaces[KEY_PRESS_SURFACE_UP];
						break;
					case (SDLK_DOWN):
						currentSurface = keySurfaces[KEY_PRESS_SURFACE_DOWN];
						break;
					case (SDLK_RIGHT):
						currentSurface = keySurfaces[KEY_PRESS_SURFACE_RIGHT];
						break;
					case (SDLK_LEFT):
						currentSurface = keySurfaces[KEY_PRESS_SURFACE_LEFT];
						break;
					default:
						SDL_RenderClear(gRenderer);
						SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
						SDL_RenderPresent(gRenderer);
						break;
				}
			}
		}
*//*
		{
			SDL_Rect strechRect;
			strechRect.x = 0;
			strechRect.y = 0;
			strechRect.w = SCREEN_WIDTH;
			strechRect.h = SCREEN_HEIGHT;
			SDL_BlitScaled(currentSurface, NULL, screenSurface, &strechRect);
		}
*/
		// SDL_BlitSurface(currentSurface, NULL, screenSurface, NULL);
//		update(gWindow);

	}

/********* end of game loop **********/



	// CLEANUP

/*
	delete [] keySurfaces;

	free(jpg_img_surface);
*/
	close();

	return 0;
}


/************************** */
/************************** */
/************************** */
/************************** */








static void error(char* _fuck)
{
	printf("%s failed: %s\n", _fuck, SDL_GetError());
	SDL_Quit();
	exit(-1);
}

static void close()
{
	gItemTexture.free();
	gBackgroundTexture.free();

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	IMG_Quit();
	SDL_Quit();
}

static void close(SDL_Window* _window)
{
	SDL_DestroyWindow(_window);

	IMG_Quit();
	SDL_Quit();
}

static void init_surface(SDL_Surface** _surface, SDL_Window* _window)
{
	if (nullptr == (*_surface = SDL_GetWindowSurface(_window)))
	{
		error("SDL_GetWindowSurface");
	}
	SDL_FillRect(*_surface, NULL, SDL_MapRGB((*_surface)->format, 0x53, 0xf0, 0x12));
}

static void init_window(SDL_Window** _window)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		error("SDL_Init");
	}

	*_window = SDL_CreateWindow("Ozen's Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (nullptr == *_window)
	{
		error("SDL_CreateWindow");
	}
}


static void update(SDL_Window* _window)
{
	SDL_UpdateWindowSurface(_window);
}

static SDL_Surface* optimize_image(SDL_Surface* _surface)
{
	SDL_Surface* surface = SDL_ConvertSurface(_surface, _surface->format, 0);
	SDL_assert(surface);

	SDL_FreeSurface(_surface);

	return surface;
}

static SDL_Surface* load(SDL_Surface* _surface, char* _img)
{
	_surface = SDL_LoadBMP(_img);
	SDL_assert(_surface);
	// optimize image before blitting
	_surface = optimize_image(_surface);

	return _surface;
}

static void load(SDL_Surface* _surfaces[], size_t _nSurfaces)
{
	for (size_t i = 0; i < _nSurfaces; ++i)
	{
		_surfaces[i] = load(_surfaces[i], images[i]);
	}
}

static void free(SDL_Surface* _surface)
{
	SDL_FreeSurface(_surface);
}

static void free(SDL_Surface* _surfaces[], size_t _nSurfaces)
{
	for (size_t i = 0; i < _nSurfaces; ++i)
	{
		free(_surfaces[i]);
	}
}
// using SDL_image externtion lib
static SDL_Surface* img_load(SDL_Surface* _surface, char* _img)
{
	_surface = IMG_Load(_img);
	SDL_assert(_surface);

	_surface = optimize_image(_surface);

	return _surface;
}

static SDL_Texture* load_texture(std::string path)
{
	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface)
	{
		error("IMG_Load");
	}
	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	if (!newTexture)
	{
		error("SDL_CreateTextrueFromSurface");
	}
	free(loadedSurface);

	return newTexture;
}

static SDL_Texture* load_texture(SDL_Renderer* _renderer, std::string path)
{
	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface)
	{
		error("IMG_Load");
	}
	newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
	if (!newTexture)
	{
		error("SDL_CreateTextrueFromSurface");
	}
	free(loadedSurface);

	return newTexture;
}