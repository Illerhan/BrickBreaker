#ifndef PADDLE_H
#define PADDLE_H

#include "Actor.h"
#include "MoveComponent.h"
#include "TransformComponent.h"

class Paddle : public Actor {
public:
    Paddle(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int width, int height);

    virtual ~Paddle();

    virtual void Update() override;

    MoveComponent* GetMoveComponent() const;

private:

    MoveComponent moveComponent;
    static const int moveSpeed = 50;
};

#endif // PADDLE_H
