/*
 * game.h
 *
 *  Created on: 23 янв. 2021 г.
 *      Author: Paper
 */
#ifndef GAME_H_
#define GAME_H_
#define max 60
#define cell_width (scr_height/cell_size)
#define cell_size 10
#define cell_height (scr_width/cell_size)
#define scr_height 600
#define scr_width 400
int posx[max] = {20,20,20};
int posy[max] = {20,19,18};
int foodx, foody;
int score;

int dir = 6;
int snake_l = 3;
void gamestatus(SDL_Renderer *renderer){
    if(posy[0]==0-cell_size || posy[0]==(scr_width) || posx[0]==0-cell_size || posx[0]==(scr_height)){
    printf("\nGame over \n\nyour score: %d\n\n", score);
    exit(0);
    }
    int fx = foodx*cell_size;
    int fy = foody*cell_size;
    if(posx[0]==fx && posy[0]==fy){
        placefood(renderer);
        generatefood(renderer);
        score++;
        snake_l++;
    }
    for(int i=2; i<snake_l; i++){
        if(posx[0]==posx[i] && posy[0]==posy[i]){
            printf("\nGame over \n\nyour score: %d\n\n", score);
            exit(0);
        }
    }
}

void gamewindow(SDL_Renderer *renderer) {
    generategrid(renderer);
    generatefood(renderer);
    generatesnake(renderer);
    gamestatus(renderer);
}

int eventcontrol(SDL_Window *window){
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT)
        {
            dir = 1;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP && dir!=2){
            dir = 8;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN && dir!=8){
            dir = 2;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT && dir!=6){
            dir = 4;
        }
        else if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT && dir!=4){
            dir = 6;
        }
    }
    return dir;
}

#endif /* GAME_H_ */
