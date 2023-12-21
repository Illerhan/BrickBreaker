#include "Game.h"
#include <iostream>
#include "Brick.h"
#include "Renderer.h"
#include "SDL.h"
#include "SplitSpriteSheet.h"

Game::Game() : window(nullptr), actor(nullptr), background(nullptr), ball(nullptr), paddle(nullptr),quit(false) {

    

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
    }

    window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
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
        for (int i = 0; i < 4; ++i) {
            int ballX = i * 100;  // Adjust as needed
            int ballY = 200;      // Adjust as needed
            int ballIndex = rand() % numBallColumns;

            Ball* ball = new Ball(rendererInstance->GetRenderer(), *ballSpriteSheet, ballX, ballY, 40, 22, ballIndex);
            rendererInstance->AddActor(ball);
        }
    }
    else {
        // Handle the case where ballSpriteSheet.GetColumns() is zero
        std::cerr << "Error: Ball sprite sheet has zero columns." << std::endl;
    }
    int numColumns = brickSpriteSheet->GetColumns();
    if (numColumns > 0) {
        for (int i = 0; i < 10; ++i) {
            int brickX = i * 100;
            int brickY = 100;
            int brickIndex = rand() % numColumns;

            Brick* brick = new Brick(rendererInstance->GetRenderer(), *brickSpriteSheet, brickX, brickY, 70, 22, brickIndex);
            rendererInstance->AddActor(brick);
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

    if (ball) {
        delete ball;
        ball = nullptr;
    }

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
            std::cout << "Key pressed: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
        }
        if (paddle)
        {
            paddle->Update();
            paddle->GetMoveComponent()->Update();
        }
        
        background.Render();
        rendererInstance->Render();
        rendererInstance->Present();

    	

        SDL_Delay(16);
    }
}
