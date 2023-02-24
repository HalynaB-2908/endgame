#include "header.h"

void init_status_lives(GameState *game) {
    char str[128] = "";
    sprintf(str, "x %d", (int)game->man.lives);
  SDL_Color white = {255, 255, 255, 255};
  SDL_Surface *tmp = TTF_RenderText_Blended(game->font, str, white);
  game->labelW = tmp->w;
  game->labelH = tmp->h;
  game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
  SDL_FreeSurface(tmp);

}
void draw_status_lives(GameState *game) {
    SDL_Renderer *renderer = game->renderer;
    SDL_SetRenderDrawColor(renderer, 85, 107, 47, 255);    
    SDL_RenderClear(renderer);
    
    SDL_Rect rect = {320 - 70, 240 - 24, 48, 48};
    SDL_RenderCopyEx(renderer, game->manFrames[0], NULL, &rect, 0, NULL, (game->man.facingLeft == 0));
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect textRect = {320 - 20, 240 - game->labelH/2, game->labelW, game->labelH};
    SDL_RenderCopy(renderer, game->label, NULL, &textRect);
}

void shutdown_status_lives(GameState *game) {
    SDL_DestroyTexture(game->label);
    game->label = NULL;
}
