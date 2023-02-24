#include "header.h"

int main() {
   GameState gameState;
   SDL_Window *window = NULL;
   SDL_Renderer *renderer = NULL;
   
   SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO);
   
   gameState.joystick = SDL_JoystickOpen(0);
   srand((int)time(NULL));
   
   window = SDL_CreateWindow("Game Window",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            640,
                            480,
                            0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED  |SDL_RENDERER_PRESENTVSYNC);
    gameState.renderer = renderer;
    
   // SDL_RenderSetLogicalSize(renderer, 640, 480);
    TTF_Init();
    loadGame(&gameState);
    int done = 0;

    while (!done) {
        done = processEvents(window, &gameState);
        
        process(&gameState);
        collisionDetect(&gameState);
        doRender(renderer, &gameState);
        SDL_Delay(10);
    }
    SDL_DestroyTexture(gameState.star);
    SDL_DestroyTexture(gameState.manFrames[0]);
    SDL_DestroyTexture(gameState.manFrames[1]);
    if (gameState.label != NULL)
        SDL_DestroyTexture(gameState.label);
    TTF_CloseFont(gameState.font);
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
