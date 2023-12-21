#ifndef BRICK_H
#define BRICK_H

#include "Actor.h"
#include "SplitSpriteSheet.h"  // Include the SplitSpriteSheet header
#include <SDL.h>

class Brick : public Actor {
public:
    Brick(SDL_Renderer* renderer, SplitSpriteSheet& spriteSheet, int x, int y, int width, int height, int spriteIndex);
    ~Brick();

    static const int spriteWidth = 72;
    static const int spriteHeight = 22;

    virtual void Update() override;
    virtual void Render(SDL_Renderer* renderer) override;

private:
    SplitSpriteSheet& spriteSheet;
    int spriteIndex;
};

#endif // BRICK_H
