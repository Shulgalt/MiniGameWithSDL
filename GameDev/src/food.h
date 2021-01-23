/*
 * food.h
 *
 *  Created on: 12 янв. 2021 г.
 *      Author: Paper
 */
#ifndef FOOD_H_
#define FOOD_H_
#define cell_width (scr_height/cell_size)
#define cell_size 10
#define cell_height (scr_width/cell_size)
#define scr_height 600
#define scr_width 400
int foodx, foody;
int placefood(SDL_Renderer *renderer) {
    srand(time(NULL));
    foodx = rand() % cell_width;
    foody = rand() % cell_height;
    return 0;
}

void generatefood(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rect = { foodx*cell_size, foody*cell_size, cell_size, cell_size };
    SDL_RenderFillRect(renderer, &rect);
}

#endif /* FOOD_H_ */
