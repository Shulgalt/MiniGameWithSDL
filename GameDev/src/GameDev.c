/*
 ============================================================================
 Name        : GameDev.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sdl.h"
#include "formula.h"
#include "time.h"
#include "food.h"
#include "game.h"
#include "snake.h"

int done = 0;


int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        return 1;
    }
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);
    struct Snake snake;
    struct Food food;
    setup(&snake, &food);


    SDL_Event event;
    while(!done){
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderClear(renderer);
        snakeDeath(&snake, &food);
        snakeEat(&snake, &food);
        snakePhysics(&snake);
        snakeUpdate(renderer, &snake);
        foodUpdate(renderer, &food);
        SDL_RenderPresent(renderer);
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                done = 1;
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_UP] && snake.direction != DOWN){
                snake.direction = UP;
            }
            if(state[SDL_SCANCODE_DOWN] && snake.direction != UP){
                snake.direction = DOWN;
            }
            if(state[SDL_SCANCODE_LEFT] && snake.direction != RIGHT){
                snake.direction = LEFT;
            }
            if(state[SDL_SCANCODE_RIGHT] && snake.direction != LEFT){
                snake.direction = RIGHT;
            }
        }
        SDL_Delay(1200);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    printf("DEAD\n");
}
