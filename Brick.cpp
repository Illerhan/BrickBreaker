#include "Brick.h"

#include "Ball.h"


Brick::Brick(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex)
    : Actor(renderer, spriteSheet.GetSprite(0, spriteIndex), SDL_Rect{ 5, 5, width, height }, x, y, width, height),
    spriteSheet(spriteSheet),
    spriteIndex(spriteIndex) {
    // Additional initialization code if needed
}
Brick::~Brick() {
    // Cleanup code if needed
}

SDL_Rect Brick::GetRect() const {
    SDL_Rect rect;
    rect.x = static_cast<int>(x);
    rect.y = static_cast<int>(y);
    rect.w = width;
    rect.h = height;
    return rect;
}



void Brick::Update() {
    // Add any update logic for bricks (if necessary)
}

void Brick::Render(SDL_Renderer* renderer) {
    // Render the brick using SDL_RenderCopy or other rendering techniques
    Actor::Render(renderer);
    // Add any additional rendering code for bricks
}