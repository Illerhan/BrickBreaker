#ifndef GAME_H
#define GAME_H

#include "Background.h"
#include "Ball.h"
#include "Paddle.h"
#include "Renderer.h"

class Game {
public:
    Game();
    ~Game();

    void Run();

private:
    bool quit;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Actor* actor;  // Now we have an Actor in the Game class
    Background background;
    Renderer* rendererInstance;
    Paddle* paddle;
    Ball* ball;
};

#endif // GAME_H
