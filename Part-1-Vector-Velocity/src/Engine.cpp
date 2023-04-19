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

            if (e.key.keysym.sym == SDLK_UP)
            {
                // apply a velocity up
                velocities = velocities + Vec2D(0, -5);
            }
            if (e.key.keysym.sym == SDLK_DOWN)
            {
                // apply a velocity up
                velocities = velocities + Vec2D(0, 5);
            }
            if (e.key.keysym.sym == SDLK_LEFT)
            {
                // apply a velocity up
                velocities = velocities + Vec2D(-5, 0);
            }
            if (e.key.keysym.sym == SDLK_RIGHT)
            {
                // apply a velocity up
                velocities = velocities + Vec2D(5, 0);
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

    // start with x axis
    if (entity->position.x - 10 < 0 || entity->position.x + 10 >= GraphicInterface::GetWidth())
    {
        // reverse x velocity
        velocities = Vec2D(velocities.x * -1, velocities.y);
    }

    // y axis
    if (entity->position.y - 10 < 0 || entity->position.y + 10 >= GraphicInterface::GetHeight())
    {
        // reverse y velocity
        velocities = Vec2D(velocities.x, velocities.y * -1);
    }

    // TODO: update all objects in the scene
    entity->position = entity->position + velocities;
}

///////////////////////////////////////////////////////////////////////////////
// Render function (called several times per second to draw objects)
///////////////////////////////////////////////////////////////////////////////
void Engine::Render()
{
    GraphicInterface::WipeScreen(0xFFFFFFFF);

    GraphicInterface::DrawFillCircle(entity->position.x, entity->position.y, 10, 0xFF0000FF);
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