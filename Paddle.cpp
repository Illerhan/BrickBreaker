// Paddle.cpp
#include "Paddle.h"

#include <iostream>
#include <ostream>

Paddle::Paddle(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int width, int height)
    : Actor(renderer, imagePath, x, y, width, height), moveComponent(renderer, moveSpeed) {
    moveComponent.SetTransformComponent(GetTransformComponent());
}

Paddle::~Paddle() {
    // Destructor for the paddle

}

void Paddle::Update() {
    
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    std::cout << "MoveComponent pointer: " << GetMoveComponent() << std::endl;
    if (keyboardState[SDL_SCANCODE_LEFT]) {
        moveComponent.MoveLeft();
    }
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        moveComponent.MoveRight();
    }

    moveComponent.Update();

}

MoveComponent* Paddle::GetMoveComponent() const {
    return const_cast<MoveComponent*>(&moveComponent);
}
