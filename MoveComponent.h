// MoveComponent.h
#ifndef MOVECOMPONENT_H
#define MOVECOMPONENT_H

#include "Component.h"
#include <SDL.h>

#include "TransformComponent.h"

class MoveComponent : public Component {
public:
    MoveComponent(SDL_Renderer* renderer, int speed = 5);
    void SetTransformComponent(TransformComponent* transform);
    MoveComponent* GetMoveComponent() const;

    virtual void Update() override;

    void MoveLeft();
    void MoveRight();

private:
    SDL_Renderer* renderer;
    int speed;
	TransformComponent* transformComponent;
};

#endif // MOVECOMPONENT_H
