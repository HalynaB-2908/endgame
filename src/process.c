#include "header.h"

void process(GameState *game) {
    game->time++;
    if (game->time > 120) {
        shutdown_status_lives(game);
        game->statusState = STATUS_STATE_GAME;
    }
    if (game->statusState == STATUS_STATE_GAME) {
        if (!game->man.isDead) {
            Man *man = &game->man; 
            man->x += man->dx;  
            man->y += man->dy;
        if (man->dx != 0 && man->onLedge && !man->slowingDown) {
            if (game->time % 8 == 0) {
                if (man->animFrame == 0) {
                    man->animFrame = 1;
                } else {
                    man->animFrame = 0;
                }
            }  
         }   
             man->dy += GRAVITY;
        }
        if (game->man.isDead && game->deathCountdown < 0) {
            game->deathCountdown = 120;
        }
        if (game->deathCountdown > 0) {
            game->deathCountdown--;
            if (game->deathCountdown < 0) {
                game->man.lives--;
                if (game->man.lives >= 0) {
                    init_status_lives(game);
                    game->statusState = STATUS_STATE_LIVES;
                    game->time = 0;
                    game->man.isDead = 0;
                    game->man.x = 100;
                    game->man.y = 240-20;
                    game->man.dx = 0;
                    game->man.dy = 0;
                    game->man.onLedge = 0;
                }
                else {
                    //init_game_over(game);
                    game->statusState = STATUS_STATE_GAMEOVER;
                    game->time = 0;
                }
            }
        }
    }
    game->scrollX = -game->man.x + 320;
    if (game->scrollX > 0)
        game->scrollX = 0;
    
}
