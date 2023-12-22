#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <vector>
#include "Actor.h"

class Renderer {
public:
    Renderer();
    Renderer(SDL_Renderer* rendererParam);
    ~Renderer();

    bool Initialize(SDL_Renderer* rendererParam);
    void Render();
    void Present();
    void ClearActors();
    void RemoveActor(std::vector<Actor*>::iterator it);
    std::vector<Actor*>& GetActors();


    SDL_Renderer* GetRenderer() const;

    void AddActor(Actor* actor);

private:
    SDL_Renderer* renderer;
    std::vector<Actor*> actors;
};

#endif // RENDERER_H
