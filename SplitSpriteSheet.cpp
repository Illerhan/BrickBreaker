#include "SplitSpriteSheet.h"

#include <iostream>
#include <ostream>
#include <SDL_image.h>

SplitSpriteSheet::SplitSpriteSheet(SDL_Renderer* renderer, const std::string& imagePath, int spriteWidth, int spriteHeight)
    : renderer(renderer), spriteSheet(nullptr), spriteWidth(spriteWidth), spriteHeight(spriteHeight), numRows(0), numCols(0) {

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
    std::cout << "width: " << width << ", spriteWidth: " << spriteWidth << ", numCols: " << numCols << ", columns: " << columns << std::endl;

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
    }
}

SDL_Texture* SplitSpriteSheet::GetSprite(int row, int col) {
    SDL_Rect srcRect = { col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight };
    SDL_Texture* sprite = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, spriteWidth, spriteHeight);
    SDL_SetRenderTarget(renderer, sprite);
    SDL_RenderCopy(renderer, spriteSheet, &srcRect, NULL);
    SDL_SetRenderTarget(renderer, NULL);

    return sprite;
}
std::string SplitSpriteSheet::GetSpritePath(int spriteIndex) const {
    // Create and return the path to the sprite based on spriteIndex
    // You'll need to implement this based on your sprite sheet organization
    // For example, if your sprites are named sprite_0.png, sprite_1.png, etc.:
    return spriteSheetPath + "sprite_" + std::to_string(spriteIndex) + ".png";
}