#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "Component.h"

class TransformComponent : public Component {
public:
    TransformComponent() : x(0), y(0) {}
    TransformComponent(int initialX, int initialY) : x(initialX), y(initialY) {}

    virtual void Update() override {
        // Update logic for the transform
    }

    int GetX() const { return x; }
    int GetY() const { return y; }

    void SetX(int newX) { x = newX; }
    void SetY(int newY) { y = newY; }

private:
    int x;
    int y;
};
#endif // TRANSFORMCOMPONENT_H