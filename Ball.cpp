// Ball.cpp

#include "Ball.h"
#include <iostream>

Ball::Ball(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex)
    : Actor(renderer, spriteSheet.GetSprite(0, spriteIndex), SDL_Rect{ 0, 0, width, height }, x, y, width, height),
    spriteSheet(spriteSheet),
    spriteIndex(spriteIndex),
    moveComponent(1.0f, -1.0f) // Initial velocities (adjust as needed)
{
}

bool Ball::CheckBrickCollision(Brick* brick) {

    SDL_Rect ballRect = GetRect();
    SDL_Rect brickRect = brick->GetRect();

    if (SDL_HasIntersection(&ballRect, &brickRect)) {
        // Collision detected with the brick
        return true;
    }

    return false;
}

void Ball::Update() {
    
    float newX = static_cast<float>(x);
    float newY = static_cast<float>(y);
    float newWidth = static_cast<float>(width);
    float newHeight = static_cast<float>(height);

    moveComponent.Update(newX, newY, newWidth, newHeight);
    std::cout << "Ball Position (Update): (" << x << ", " << y << ")" << std::endl;
    // Update ball position

    x = static_cast<int>(newX);
    y = static_cast<int>(newY);
    width = static_cast<int>(newWidth);
    height = static_cast<int>(newHeight);


    srcRect.x = spriteIndex * width; // Adjust based on your sprite sheet layout
    srcRect.y = 0; // Assuming the sprite is in the first row of the sprite sheet
    srcRect.w = width;
    srcRect.h = height;

    // Set up destination rectangle
    destRect.x = x;
    destRect.y = y;
    destRect.w = width;
    destRect.h = height;


}

void Ball::Render(SDL_Renderer* renderer) {
    // Render the ball using SDL_RenderCopy or other rendering techniques
    std::cout << "Rendering Ball at Position: (" << x << ", " << y << ")" << std::endl;
    Actor::Render(renderer);
    // Add any additional rendering code for balls
}

SDL_Rect Ball::GetRect() const {
    SDL_Rect rect{};
    rect.x = this->x;
    rect.y = this->y;
    rect.w = this->width;
    rect.h = this->height;
    return rect;
}

MoveComponent& Ball::GetMoveComponent() {
    return moveComponent;
}