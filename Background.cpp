#include "Background.h"

#include <iostream>

Background::Background(SDL_Renderer* renderer) : renderer(renderer), texture(nullptr) {
    // Default background color (white)
    color = { 255, 255, 255, 255 };
}

Background::~Background() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Background::SetColor(SDL_Color color) {
    this->color = color;
}

bool Background::LoadImage(const std::string& imagePath) {
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        // Failed to create texture
        return false;
    }

    return true;
}

void Background::Render() {
    // Render solid color background
    if (!texture) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer);
    }
    // Render image background
    else {
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    }
}
