#include "Renderer.h"

Renderer::Renderer() : renderer(nullptr) {}

Renderer::Renderer(SDL_Renderer* rendererParam) : renderer(nullptr) {
    Initialize(rendererParam);
}

Renderer::~Renderer() {
    ClearActors();

    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
}

bool Renderer::Initialize(SDL_Renderer* rendererParam) {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }

    if (rendererParam) {
        renderer = rendererParam;
        if (!renderer) {
            // Handle renderer creation error
            return false;
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Set render draw color

        return true;
    }

    // Handle error (window is null)
    return false;
}

void Renderer::Render() {
    SDL_RenderClear(renderer);

    for (Actor* actor : actors) {
        actor->Render(renderer);
    }
}

void Renderer::Present() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::GetRenderer() const {
    return renderer;
}

void Renderer::AddActor(Actor* actor) {
    actors.push_back(actor);
}
void Renderer::ClearActors() {
    for (Actor* actor : actors) {
        delete actor;
    }
    actors.clear();
}

void Renderer::RemoveActor(std::vector<Actor*>::iterator it) {
    // Find and erase the actor from the vector
    actors.erase(it);
}

std::vector<Actor*>& Renderer::GetActors() {
    return actors;
}
