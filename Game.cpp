// Game.cpp

#include "Game.h"
#include <iostream>
#include "Brick.h"
#include "Renderer.h"
#include "SDL.h"
#include "SplitSpriteSheet.h"

Game::Game() : window(nullptr), actor(nullptr), background(nullptr), paddle(nullptr), ball(nullptr), quit(false) {

    int screenWidth = 800; // Adjust based on your window width

    // Calculate the total width of the wall

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
    }

    window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        // Handle window creation error
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        // Handle renderer creation error
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        // Handle initialization error for PNG support
    }
    if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) {
        // Handle initialization error for JPEG support
    }

    rendererInstance = new Renderer();

    int paddleX = 350;
    int paddleY = 500;

    if (!rendererInstance->Initialize(renderer)) {
        // Handle renderer initialization error
    }
    std::string paddleImagePath = "Images/Paddle.png";
    SplitSpriteSheet* brickSpriteSheet = new SplitSpriteSheet(rendererInstance->GetRenderer(), "Images/Bricks.png", 70, 18);
    SplitSpriteSheet* ballSpriteSheet = new SplitSpriteSheet(rendererInstance->GetRenderer(), "Images/Balls.png", 30, 24);
    paddle = new Paddle(rendererInstance->GetRenderer(), paddleImagePath, paddleX, paddleY, 128, 24);
    std::cout << "Paddle created: " << paddle << std::endl;
    rendererInstance->AddActor(paddle);
    int numBallColumns = ballSpriteSheet->GetColumns();

    if (numBallColumns > 0) {
        int ballX = 100;  // Adjust as needed
        int ballY = 200;   // Adjust as needed
        int ballIndex = rand() % numBallColumns;
        ball = new Ball(rendererInstance->GetRenderer(), *ballSpriteSheet, ballX, ballY, 40, 22, ballIndex);
        rendererInstance->AddActor(ball);

    }
    else {
        // Handle the case where ballSpriteSheet.GetColumns() is zero
        std::cerr << "Error: Ball sprite sheet has zero columns." << std::endl;
    }
    int numRows = 6; // Number of rows
    int numBricksPerRow = 10; // Number of bricks per row
    int totalWallWidth = numBricksPerRow * 72;
    int start = (screenWidth - totalWallWidth) / 2;

    int brickWidth = 70; // Adjust as needed
    int brickHeight = 22; // Adjust as needed
    int numColumns = brickSpriteSheet->GetColumns();
    if (numColumns > 0) {
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numBricksPerRow; ++col) {
                int brickX = start + col * brickWidth;
                int brickY = start + row * brickHeight;
                int brickIndex = rand() % numColumns;

                Brick* brick = new Brick(rendererInstance->GetRenderer(), *brickSpriteSheet, brickX, brickY, brickWidth, brickHeight, brickIndex);
                rendererInstance->AddActor(brick);
            }
        }
    }
    else {
        std::cerr << "Error: Sprite sheet has zero columns." << std::endl;
    }

    delete brickSpriteSheet;
    delete ballSpriteSheet;

    //SDL_Texture* bricks = splitSpriteSheet.GetSprite(0, 0);  // Example: Get the sprite at row 0, column 0

    background = Background(rendererInstance->GetRenderer());
    background.SetColor({ 0,0,0,255 });
    actor = new Actor(rendererInstance->GetRenderer(), "Images/background.png", 0, 0, 800, 600);

    //ball = new Ball(rendererInstance->GetRenderer(), "Images/ball.png", 400, 400, 20, 20);
    //rendererInstance->AddActor(ball);

    const char* sdlError = SDL_GetError();
    if (*sdlError) {
        std::cerr << "SDL error: " << sdlError << std::endl;
        SDL_ClearError();  // Clear the error for the next iteration
    }
}

Game::~Game() {
    delete rendererInstance;


    IMG_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Run() {

    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set draw color to white
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Set blend mode


        // Update game objects
        if (paddle) {
            paddle->Update();
        }

        if (ball) {
            ball->Update();
            HandleBrickCollisions();
        }

        // Render game objects
        background.Render();

        if (paddle) {
            paddle->Render(rendererInstance->GetRenderer());
        }

        if (ball) {
            ball->Render(rendererInstance->GetRenderer());
        }

        rendererInstance->Render();
        rendererInstance->Present();

        SDL_Delay(16);
    }
}

void Game::HandleBrickCollisions() {
    auto& actors = rendererInstance->GetActors();
    for (auto it = actors.begin(); it != actors.end(); ) {
        Actor* actor = *it;

        // Check if the actor is a Brick
        if (Brick* brick = dynamic_cast<Brick*>(actor)) {
            if (ball->CheckBrickCollision(brick)) {
                // Collision detected, remove the brick
                it = actors.erase(it);
                delete brick; // Free memory
                continue; // Skip the increment in the loop
            }
        }

        // Increment iterator
        ++it;
    }
}