#include "MoveComponent.h"

#include <iostream>
#include <ostream>

MoveComponent::MoveComponent(SDL_Renderer* renderer, int speed)
    : renderer(renderer), speed(speed) {}

void MoveComponent::Update() {
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
        std::cout << transformComponent->GetX() << std::endl;
        transformComponent->SetX(transformComponent->GetX() - speed);
        std::cout << transformComponent->GetX() << std::endl;
        std::cout << "MoveLeft called!" << std::endl;
    }
}

void MoveComponent::MoveRight() {
    if (transformComponent) {
        std::cout << transformComponent->GetX() << std::endl;
        transformComponent->SetX(transformComponent->GetX() + speed);
        std::cout << transformComponent->GetX() << std::endl;
        std::cout << "MoveRight called!" << std::endl;
    }
}