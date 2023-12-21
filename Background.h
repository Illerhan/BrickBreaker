#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Background {
public:
    Background(SDL_Renderer* renderer);
    ~Background();

    // Set background color
    void SetColor(SDL_Color color);

    // Load background image from file
    bool LoadImage(const std::string& imagePath);

    // Render the background
    void Render();

private:
    SDL_Renderer* renderer;
    SDL_Color color;
    SDL_Texture* texture;
};

#endif // BACKGROUND_H
