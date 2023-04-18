#include "Engine.h"

bool Engine::HasStarted()
{
    return isRunning;
}

///////////////////////////////////////////////////////////////////////////////
// Setup function (executed once in the beginning of the simulation)
///////////////////////////////////////////////////////////////////////////////
void Engine::Initialize()
{
    isRunning = GraphicInterface::OpenWindow();

    // TODO: setup objects in the scene
    entity = new Entity(100, 100);
}

///////////////////////////////////////////////////////////////////////////////
// Input processing
///////////////////////////////////////////////////////////////////////////////
void Engine::HandleUserInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }

            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// Update function (called several times per second to update objects)
///////////////////////////////////////////////////////////////////////////////
void Engine::Update()
{
    // TODO: update all objects in the scene
}

///////////////////////////////////////////////////////////////////////////////
// Render function (called several times per second to draw objects)
///////////////////////////////////////////////////////////////////////////////
void Engine::Render()
{
    GraphicInterface::WipeScreen(0xFFFFFFFF);

    GraphicInterface::RenderFrame();
}

///////////////////////////////////////////////////////////////////////////////
// Destroy function to delete objects and close the window
///////////////////////////////////////////////////////////////////////////////
void Engine::Destroy()
{
    // TODO: destroy all objects in the scene

    GraphicInterface::CloseWindow();
}