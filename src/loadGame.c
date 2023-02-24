#include "header.h"

void loadGame(GameState *game) {
   
    SDL_Surface *surface = NULL;
    surface = IMG_Load("src/m_star.png");
    if (surface == NULL) {
        printf("Cannot find m_star.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->star = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("src/m_man1.png");
    if (surface == NULL) {
        printf("Cannot find m_man1.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->manFrames[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("src/m_man2.png");
    if (surface == NULL) {
        printf("Cannot find m_man2.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->manFrames[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("src/m_brick.png");
    game->brick = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    surface = IMG_Load("src/fire.png");
    game->fire = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    
    game->font = TTF_OpenFont("src/Crazy! Regular.ttf", 38);
    if (!game->font) {
        printf("Cannot find font file!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->label = NULL;
    
    game->man.x = 320-40;
    game->man.y = 240-40;
    game->man.dx = 0;
    game->man.dy = 0;
    game->man.onLedge = 0;
    game->man.animFrame = 0;
    game->man.facingLeft = 1;
    game->man.slowingDown = 0;
    game->man.lives = 3;
    game->man.isDead = 0;
    game->statusState = STATUS_STATE_LIVES;
    
    for (int i = 0; i < 100; i++) {
        game->stars[i].x = 320+rand()%38400;
        game->stars[i].y = rand()%480;
    }
    
    game->time = 0;
    game->scrollX = 0;
    game->deathCountdown = -1;
    
    //initStars(game);
    
       for (int i = 0; i < 100; i++) {
        game->ledges[i].w = 256;
        game->ledges[i].h = 64;
        game->ledges[i].x = i*384;
        if(i == 0)
            game->ledges[i].y = 400;
        else
            game->ledges[i].y = 300 + 100 - rand()%200;;  
    }
    game->ledges[99].x = 350;
    game->ledges[99].y = 200;   
 
}
