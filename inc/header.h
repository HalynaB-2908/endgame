#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "SDL_ttf.h"
#include "SDL_mixer.h"


#define GRAVITY 0.35f
#define STATUS_STATE_LIVES 0
#define STATUS_STATE_GAME 1
#define STATUS_STATE_GAMEOVER 2
#define NUM_STARS 100
//#define NUM_LEDGES 120

typedef struct
{
    float x, y;
    float dx, dy;
    short lives;
    char *name;
    int onLedge, isDead;
    int animFrame, facingLeft, slowingDown;
} Man;

typedef struct 
{
    int x, y;  
} Star;

typedef struct 
{
    int x, y, w, h;
} Ledge;

typedef struct 
{
    float scrollX;
    Man man;
    Star stars[NUM_STARS];
    
    Ledge ledges[100];
    
    SDL_Texture *star;
    SDL_Texture *manFrames[2];
    SDL_Texture *brick;
    SDL_Texture *fire;
    SDL_Texture *label;
    int labelW, labelH;
    
    SDL_Joystick *joystick;
    
    TTF_Font *font;
    
    int time, deathCountdown;
    int statusState;
    
    Mix_Chunk *bgMusic, *jumpSound, *landSound, *dieSound;
    
    SDL_Renderer *renderer;
} GameState;

int processEvents(SDL_Window *window, GameState *game);
void doRender(SDL_Renderer *renderer, GameState *game);
void loadGame(GameState *game);
void collisionDetect(GameState *game);
void process(GameState *game);
void init_status_lives(GameState *game);
void draw_status_lives(GameState *game);
void shutdown_status_lives(GameState *game);

#endif
