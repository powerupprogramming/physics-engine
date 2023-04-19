#include "./GraphicInterface.h"

SDL_Window *GraphicInterface::window = NULL;
SDL_Renderer *GraphicInterface::renderer = NULL;
int GraphicInterface::windowWidth = 0;
int GraphicInterface::windowHeight = 0;

int GraphicInterface::GetWidth()
{
    return windowWidth;
}

int GraphicInterface::GetHeight()
{
    return windowHeight;
}

bool GraphicInterface::OpenWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "There was an error initializing SDL" << std::endl;
        return false;
    }
    SDL_DisplayMode display_mode;
    SDL_GetCurrentDisplayMode(0, &display_mode);
    windowHeight = display_mode.h;
    windowWidth = display_mode.w;
    window = SDL_CreateWindow(NULL, 0, 0, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);
    if (!window)
    {
        std::cout << "There was an error creating SDL window" << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        std::cout << "There was an error creating SDL renderer" << std::endl;
        return false;
    }
    return true;
}

void GraphicInterface::WipeScreen(Uint32 color)
{
    SDL_SetRenderDrawColor(renderer, color >> 16, color >> 8, color, 255);
    SDL_RenderClear(renderer);
}

void GraphicInterface::RenderFrame()
{
    SDL_RenderPresent(renderer);
}

// Color for following functions use a Uint32 color code
void GraphicInterface::DrawLine(int x0, int y0, int x1, int y1, Uint32 color)
{
    lineColor(renderer, x0, y0, x1, y1, color);
}

void GraphicInterface::DrawCircle(int x, int y, int radius, float angle, Uint32 color)
{
    circleColor(renderer, x, y, radius, color);
    lineColor(renderer, x, y, x + cos(angle) * radius, y + sin(angle) * radius, color);
}

void GraphicInterface::DrawFillCircle(int x, int y, int radius, Uint32 color)
{
    filledCircleColor(renderer, x, y, radius, color);
}

void GraphicInterface::DrawRect(int x, int y, int width, int height, Uint32 color)
{
    lineColor(renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y - height / 2.0, color);
    lineColor(renderer, x + width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, color);
    lineColor(renderer, x + width / 2.0, y + height / 2.0, x - width / 2.0, y + height / 2.0, color);
    lineColor(renderer, x - width / 2.0, y + height / 2.0, x - width / 2.0, y - height / 2.0, color);
}

void GraphicInterface::DrawFillRect(int x, int y, int width, int height, Uint32 color)
{
    boxColor(renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, color);
}

void GraphicInterface::DrawPolygon(int x, int y, const std::vector<Vec2D> &vertices, Uint32 color)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        int currentI = i;
        int nextI = (i + 1) % vertices.size();
        lineColor(renderer, vertices[currentI].x, vertices[currentI].y, vertices[nextI].x, vertices[nextI].y, color);
    }
    filledCircleColor(renderer, x, y, 1, color);
}

void GraphicInterface::DrawFillPolygon(int x, int y, const std::vector<Vec2D> &vertices, Uint32 color)
{
    std::vector<short> verticesX;
    std::vector<short> verticesY;
    for (int i = 0; i < vertices.size(); i++)
    {
        verticesX.push_back(static_cast<int>(vertices[i].x));
    }
    for (int i = 0; i < vertices.size(); i++)
    {
        verticesY.push_back(static_cast<int>(vertices[i].y));
    }
    filledPolygonColor(renderer, &verticesX[0], &verticesY[0], vertices.size(), color);
    filledCircleColor(renderer, x, y, 1, 0xFF000000);
}

void GraphicInterface::DrawTexture(int x, int y, int width, int height, float rotation, SDL_Texture *texture)
{
    SDL_Rect destRect = {x - (width / 2), y - (height / 2), width, height};
    float rotationDegrees = rotation * 57.2958;
    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, rotationDegrees, NULL, SDL_FLIP_NONE);
}

void GraphicInterface::CloseWindow(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}