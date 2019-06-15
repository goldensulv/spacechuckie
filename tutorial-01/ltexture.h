// ltexture.h
#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <SDL2/SDL.h>
#include <string>

class LTexture
{
    public:
        LTexture();
        ~LTexture();

        bool loadFromFile(std::string _path);

        void free();

        void render(int _x, int _y);

        // get image dimensions
        int getWidth();
        int getHeight();
    
    private:
        SDL_Texture*    m_texture;
        int             m_width;
        int             m_height;
};


#endif /* LTEXTURE_H */