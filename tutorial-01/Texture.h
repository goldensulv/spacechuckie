// Texture.h
#ifndef Texture_H
#define Texture_H

#include <SDL2/SDL.h>
#include <string>

extern void error(char* _fuck);

class Texture
{
    public:
        Texture();
        ~Texture();

        bool loadFromFile(std::string _path);

        void free();
/*
        void render(int _x, int _y);
*/
        // get image dimensions
        SDL_Texture* getTexture() const;
        int getWidth() const;
        int getHeight() const;
    
    private:
        SDL_Texture*    m_texture;
        int             m_width;
        int             m_height;
};


#endif /* Texture_H */