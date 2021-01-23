/*
 * formula.h
 *
 *  Created on: 23 янв. 2021 г.
 *      Author: Paper
 */
#ifndef FORMULA_H_
#define FORMULA_H_
#define start_cell_x 0
#define start_cell_y 0
#define cell_width (scr_height/cell_size)
#define cell_size 10
#define cell_height (scr_width/cell_size)
#define scr_height 600
#define scr_width 400

void generategrid(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect field = {
        start_cell_x * cell_size,
        start_cell_y * cell_size,
        cell_width * cell_size,
        cell_height * cell_size
    };

    SDL_RenderFillRect(renderer, &field);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 0; i <= cell_width; i++) {
        if(i==0 || i==cell_width ){
            SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
            SDL_RenderDrawLine(renderer, i * cell_size, 0, i * cell_size, cell_height * cell_size);
        }
    }
    for (int i = 0; i <= cell_height; i++) {
        if(i==0 || i==cell_height ){
            SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
            SDL_RenderDrawLine(renderer, 0, i * cell_size, cell_width * cell_size, i * cell_size);
        }
    }
}

#endif /* FORMULA_H_ */
