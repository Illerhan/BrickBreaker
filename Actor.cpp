#include "Actor.h"


Actor::Actor(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int width, int height)
    : renderer(renderer), texture(nullptr) {
    LoadTextureFromImage(imagePath);
    destRect = { x, y, width, height };
}

Actor::Actor(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& srcRect, int x, int y, int width, int height)
    : renderer(renderer), texture(texture), srcRect(srcRect), destRect{ x, y, width, height }, transformComponent(x, y) {
}

Actor::~Actor() {
        if (texture) {
            SDL_DestroyTexture(texture);
            texture = nullptr;  // Set to nullptr to avoid double destruction
        }
    }


void Actor::Update() {
    // Add any necessary update logic here
}

void Actor::Render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}

void Actor::LoadTextureFromImage(const std::string& imagePath) {
    SDL_Surface* imageSurface = IMG_Load(imagePath.c_str());
    if (!imageSurface) {
        // Handle image loading error
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    if (!texture) {
        // Handle texture creation error
        return;
    }

    // Set the default source rectangle to the entire texture
    SDL_QueryTexture(texture, nullptr, nullptr, &srcRect.w, &srcRect.h);
}
