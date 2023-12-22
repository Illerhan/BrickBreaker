// MoveComponent.h
#pragma once

class MoveComponent {
public:
    MoveComponent(float initialVelocityX, float initialVelocityY);
    ~MoveComponent() = default;

    void Update(float& x, float& y, float& width, float& height);

    void SetVelocity(float newVelocityX, float newVelocityY);

private:
    float velocityX;
    float velocityY;
};