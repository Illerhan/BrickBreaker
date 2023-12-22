#include "MoveComponent.h"

MoveComponent::MoveComponent(float initialVelocityX, float initialVelocityY)
    : velocityX(initialVelocityX), velocityY(initialVelocityY) {}

void MoveComponent::Update(float& x, float& y, float& width, float& height) {
    // Update position based on current velocity
    x += velocityX;
    y += velocityY;

    // Example: Bounce off boundaries
    if (x < 0 || x + width > 800) {
        velocityX = -velocityX;
    }

    if (y < 0) {
        velocityY = -velocityY;
    }
}
void MoveComponent::SetVelocity(float newVelocityX, float newVelocityY) {
    velocityX = newVelocityX;
    velocityY = newVelocityY;
}