#include "header.h"

void doRender(SDL_Renderer *renderer, GameState *game) {

    if (game->statusState == STATUS_STATE_LIVES) {
        draw_status_lives(game);
    }
    else if (game->statusState == STATUS_STATE_GAME) {
        SDL_SetRenderDrawColor(renderer, 189, 183, 107, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
        for (int i = 0; i < 100; i++) {
            SDL_Rect ledgeRect = {game->scrollX+game->ledges[i].x, game->ledges[i].y, game->ledges[i].w, game->ledges[i].h};
            SDL_RenderCopy(renderer, game->brick, NULL, &ledgeRect);
        }
    
        SDL_Rect rect = {game->scrollX+game->man.x, game->man.y, 48, 48};
        SDL_RenderCopyEx(renderer, game->manFrames[game->man.animFrame], NULL, &rect, 0, NULL, (game->man.facingLeft == 0));
        
        if (game->man.isDead) {
            SDL_Rect rect = {game->scrollX+game->man.x-24+38/2+10, game->man.y-24-83/2, 38, 83};
        SDL_RenderCopyEx(renderer, game->fire, NULL, &rect, 0, NULL, (game->time % 20 < 10));
        }
        
        for (int i = 0; i < NUM_STARS; i++) {
            SDL_Rect starRect = {game->scrollX+game->stars[i].x, game->stars[i].y, 54, 54};
            SDL_RenderCopy(renderer, game->star, NULL, &starRect);
        }  
    }
    SDL_RenderPresent(renderer);   
}
