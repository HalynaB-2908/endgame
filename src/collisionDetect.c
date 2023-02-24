#include "header.h"

int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2) {
    return (!((x1 > (x2 + wt2)) || (x2 > (x1 + wt1)) || (y1 > (y2 + ht2)) || (y2 > (y1 + ht1))));
}

void collisionDetect(GameState *game) {
  
    for (int i = 0; i < NUM_STARS; i++) {
   
        if (collide2d(game->man.x, game->man.y, game->stars[i].x, game->stars[i].y, 48, 48, 27, 27)) {
        game->man.isDead = 1;
        }
    }
  
    for (int i = 0; i < 100; i++) {
        float mw = 48, mh = 48;
        float mx = game->man.x, my = game->man.y;
        float bx = game->ledges[i].x, by = game->ledges[i].y, bw = game->ledges[i].w, bh = game->ledges[i].h;
        
    if ((mx + mw)/2 > bx && (mx+mw)/2 < (bx + bw)) {
        if (my < (by + bh) && my > by && game->man.dy < 0) {
            game->man.y = by + bh;
            my = by + bh;
            game->man.dy = 0;
            game->man.onLedge = 1;   
        } 
    }
    if ((mx + mw) > bx && mx < (bx + bw)) {
        if ((my + mh) > by && my < by && game->man.dy > 0) {
            game->man.y = by - mh;
            my = by - mh;
            game->man.dy = 0;
            game->man.onLedge = 1;
        }
    }
    if ((my + mh) > by && my < (by + bh)) {
        if (mx < (bx + bw) && (mx + mw) > (bx + bw) && game->man.dx < 0) {
            game->man.x = bx + bw;
            mx = bx + bw;
            game->man.dx = 0;
        }
        else if ((mx + mw) > bx && mx < bx && game->man.dx > 0) {
            game->man.x = bx - mw;
            mx = bx - mw;
            game->man.dx = 0;
            }
        }
    }
} 
