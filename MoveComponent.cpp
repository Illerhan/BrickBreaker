#include "MoveComponent.h"

#include <iostream>
#include <ostream>

MoveComponent::MoveComponent(SDL_Renderer* renderer, int speed)
    : renderer(renderer), speed(speed) {}

void MoveComponent::Update() {
    std::cout << "MoveComponent Update() called" << std::endl;
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_LEFT]) {
        MoveLeft();
    }

    if (keystate[SDL_SCANCODE_RIGHT]) {
        MoveRight();
    }
}

void MoveComponent::SetTransformComponent(TransformComponent* transform) {
    transformComponent = transform;
}



void MoveComponent::MoveLeft() {
    if (transformComponent) {
        transformComponent->SetX(transformComponent->GetX() - speed);
        std::cout << "MoveLeft called!" << std::endl;
    }
}

void MoveComponent::MoveRight() {
    if (transformComponent) {
        transformComponent->SetX(transformComponent->GetX() + speed);
        std::cout << "MoveRight called!" << std::endl;
    }
}