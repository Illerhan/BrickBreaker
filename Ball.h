// Ball.h

#ifndef BALL_H
#define BALL_H

#include "Actor.h"
#include "Brick.h"
#include "MoveComponent.h"
#include "SplitSpriteSheet.h"

class Ball : public Actor {
public:
    Ball(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex);

    bool CheckBrickCollision(Brick* brick);

    void Update() override;
    void Render(SDL_Renderer* renderer) override;

    SDL_Rect GetRect() const;

    MoveComponent& GetMoveComponent();

private:
    SplitSpriteSheet& spriteSheet;
    int spriteIndex;

    MoveComponent moveComponent;
    float x;
    float y;
    float width;
    float height;
};

#endif // BALL_H
