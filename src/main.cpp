#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "PrimitiveComponent.h"
#include "Solver.h"
#include "ChaosScene.h"
#include "World.h"

using namespace Chaos;

void DrawCircle(SDL_Renderer* renderer, int cx, int cy, int r)
{
    for (int x = -r; x <= r; x++)
        for (int y = -r; y <= r; y++)
            if (x*x + y*y <= r*r)
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
}


int main(){
    
    UWorld world;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Chaos Clone",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1200, 900,
        0
    );

    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    Uint32 lastTime = SDL_GetTicks();

    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
        }

        Uint32 currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        world.GetChaosScene()->OnStartFrame(dt);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        
        for (auto&b :world.GetWorldComponents()){
            b.UpdateTransform();
            DrawCircle(renderer, (int)b.Transform.x,(int)b.Transform.y,10);
            SDL_RenderPresent(renderer);
        }
    }
    SDL_Quit();
    return 0;
}