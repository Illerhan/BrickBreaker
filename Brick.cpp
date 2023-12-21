#include "Brick.h"

Brick::Brick(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex)
    : Actor(renderer, spriteSheet.GetSprite(0, spriteIndex), SDL_Rect{ 0, 0, width, height }, x, y, width, height),
    spriteSheet(spriteSheet),
    spriteIndex(spriteIndex) {
    // Additional initialization code if needed
}
Brick::~Brick() {
    // Cleanup code if needed
}

void Brick::Update() {
    // Add any update logic for bricks (if necessary)
}

void Brick::Render(SDL_Renderer* renderer) {
    // Render the brick using SDL_RenderCopy or other rendering techniques
    Actor::Render(renderer);
    // Add any additional rendering code for bricks
}