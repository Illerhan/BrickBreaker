
#ifndef SPLITSPRITESHEET_H
#define SPLITSPRITESHEET_H

#include <SDL.h>
#include <string>
#include <vector>

class SplitSpriteSheet {
public:
    SplitSpriteSheet(SDL_Renderer* renderer, const std::string& imagePath, int spriteWidth, int spriteHeight);
    ~SplitSpriteSheet();

    SDL_Texture* GetSprite(int row, int col);
    std::string GetSpritePath(int spriteIndex) const;
    int GetColumns() const;

    static SplitSpriteSheet CreateWithDimensions(SDL_Renderer* renderer, const std::string& imagePath, int spriteWidth, int spriteHeight) {
        return SplitSpriteSheet(renderer, imagePath, spriteWidth, spriteHeight);
    }

private:
    SDL_Renderer* renderer;
    SDL_Texture* spriteSheet;
    std::string spriteSheetPath;
    int spriteWidth;
    int spriteHeight;
    int numRows;
    int numCols;
    int columns;
};

#endif // SPLITSPRITESHEET_H
