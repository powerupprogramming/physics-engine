#include "Engine.h"

// Entry to Engine
int main() {
    Engine engine;

    engine.Initialize();

    // Game Loop
    while (engine.HasStarted()) {
        engine.HandleUserInput();
        engine.Update();
        engine.Render();
    }

    engine.Destroy();

    return 0;
}