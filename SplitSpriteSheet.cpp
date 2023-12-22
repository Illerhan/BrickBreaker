#include "SplitSpriteSheet.h"
#include <iostream>
#include <SDL_image.h>

SplitSpriteSheet::SplitSpriteSheet(SDL_Renderer* renderer, const std::string& imagePath, int spriteWidth, int spriteHeight)
    : renderer(renderer), spriteSheet(nullptr), spriteWidth(spriteWidth), spriteHeight(spriteHeight), numRows(0), numCols(0), columns(0) {

    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        // Handle error
        std::cerr << "Failed to load sprite sheet: " << IMG_GetError() << std::endl;
        return;
    }

    spriteSheet = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!spriteSheet) {
        // Handle error
        std::cerr << "Failed to create texture from sprite sheet: " << SDL_GetError() << std::endl;
        return;
    }

    int width, height;
    SDL_QueryTexture(spriteSheet, NULL, NULL, &width, &height);

    numCols = width / spriteWidth;
    numRows = height / spriteHeight;
    columns = numCols;
}

int SplitSpriteSheet::GetColumns() const {
    return columns;
}

SplitSpriteSheet::~SplitSpriteSheet() {
    if (spriteSheet) {
        SDL_DestroyTexture(spriteSheet);
        spriteSheet = nullptr;
    }
}

SDL_Texture* SplitSpriteSheet::GetSprite(int row, int col) {
    SDL_Rect srcRect = { col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight };
    SDL_Texture* sprite = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, spriteWidth, spriteHeight);

    // Set the render target to the new texture
    SDL_SetRenderTarget(renderer, sprite);

    // Copy the sprite from the sprite sheet to the new texture
    SDL_RenderCopy(renderer, spriteSheet, &srcRect, NULL);

    // Reset the render target
    SDL_SetRenderTarget(renderer, NULL);

    return sprite;
}

std::string SplitSpriteSheet::GetSpritePath(int spriteIndex) const {
    // Implement this based on your sprite sheet organization
    return spriteSheetPath + "sprite_" + std::to_string(spriteIndex) + ".png";
}