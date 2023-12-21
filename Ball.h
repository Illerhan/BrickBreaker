// Ball.h
#ifndef BALL_H
#define BALL_H

#include "Actor.h"
#include "SplitSpriteSheet.h"

class Ball : public Actor {
public:
    Ball(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex);
    ~Ball();

    static const int spriteWidth = 30;
    static const int spriteHeight = 24;

    virtual void Update() override;
    virtual void Render(SDL_Renderer* renderer) override;

private:
    SplitSpriteSheet& spriteSheet;
    int spriteIndex;
};

#endif // BALL_H
