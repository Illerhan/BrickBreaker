#ifndef ACTOR_H
#define ACTOR_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>


class Actor {
public:
    Actor(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int width, int height);
    Actor(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect& srcRect, int x, int y, int width, int height);
    virtual ~Actor();

    virtual void Update();
    virtual void Render(SDL_Renderer* renderer);
    

private:
    SDL_Renderer* renderer;
    void LoadTextureFromImage(const std::string& imagePath);

protected:
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;

};

#endif // ACTOR_H
