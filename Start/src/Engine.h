#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "./GraphicInterface.h"

class Engine
{
private:
    bool isRunning = false;

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