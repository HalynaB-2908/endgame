#include "header.h"

int processEvents(SDL_Window *window, GameState *game) {
    SDL_Event event;
    int done = 0;
    
    while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_WINDOWEVENT_CLOSE: {
                    if(window) {
                        SDL_DestroyWindow(window);
                        window = NULL;
                        done = 1;
                    }
                }
                break;
                case SDL_KEYDOWN: {
                    switch(event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            done = 1;
                        break;
                        case SDLK_UP:
                            if (game->man.onLedge) {
                                game->man.dy = -10;
                                game->man.onLedge = 0;
                            }
                            break;
                    }  
                }
                break;
                case SDL_QUIT:
                    done = 1;
                break;
            }
        }
         
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
        game->man.dy -= 0.2f;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        game->man.dx -= 0.5;
        if (game->man.dx < -6) {
            game->man.dx = -6;
        }
        game->man.facingLeft = 0;
    }
    else if (state[SDL_SCANCODE_RIGHT]) {
        game->man.dx += 0.5;
        if (game->man.dx > 6) {
        game->man.dx = 6;
        }
        game->man.facingLeft = 1;
        game->man.slowingDown = 0;
    } else {
        game->man.animFrame = 0;
        game->man.dx *= 0.8f;
        game->man.slowingDown = 0;
        if (fabsf(game->man.dx) < 0.1f) {
            game->man.dx = 0;
        }
    }
    /*
    if (state[SDL_SCANCODE_UP]) {
        game->man.y -= 10;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        game->man.y += 10;
    }
    */
    return done;
}
