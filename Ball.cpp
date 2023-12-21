
#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex)
    : Actor(renderer, spriteSheet.GetSprite(0, spriteIndex), SDL_Rect{ 0, 0, width, height }, x, y, width, height),
    spriteSheet(spriteSheet),
    spriteIndex(spriteIndex) {
    // Additional initialization code if needed
}
Ball::~Ball() {
    // Cleanup code if needed
}

void Ball::Update() {
    // Add any update logic for balls (if necessary)
}

void Ball::Render(SDL_Renderer* renderer) {
    // Render the ball using SDL_RenderCopy or other rendering techniques
    Actor::Render(renderer);
    // Add any additional rendering code for balls
}