#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "Entity.h"
#include "Vec2D.h"
#include "./GraphicInterface.h"

class Engine
{
private:
    bool isRunning = false;
    Entity *entity;
    Vec2D velocities;

public:
    Engine() = default;
    ~Engine() = default;
    bool HasStarted();
    void Initialize();
    void HandleUserInput();
    void Update();
    void Render();
    void Destroy();
};

#endif