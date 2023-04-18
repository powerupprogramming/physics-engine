#include "Engine.h"

// Entry to Engine
int main() {
    Engine engine;

    engine.Setup();

    // Game Loop
    while (engine.IsRunning()) {
        engine.Input();
        engine.Update();
        engine.Render();
    }

    engine.Destroy();

    return 0;
}