// Paddle.cpp
#include "Paddle.h"

#include <iostream>
#include <ostream>

Paddle::Paddle(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int width, int height)
    : Actor(renderer, imagePath, x, y, width, height), moveComponent(0.5, moveSpeed) {
}

Paddle::~Paddle() {
    // Destructor for the paddle

}

void Paddle::Update() {  
    
    
    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    
    if (keyboardState[SDL_SCANCODE_LEFT]) {
 
    }
    if (keyboardState[SDL_SCANCODE_RIGHT]) {
        
    }


}

MoveComponent* Paddle::GetMoveComponent() const {
    //std::cout << "MoveComponent pointer: " << moveComponent << std::endl;
    return const_cast<MoveComponent*>(&moveComponent);
}
