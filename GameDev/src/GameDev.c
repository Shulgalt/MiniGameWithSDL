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
#include <stdlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <formula.h>


#include <SDL.h>

// Размеры окна для вывода


int main(int argc, char *argv[]) {
	SDL_Window *window;
	SDL_Renderer *renderer;
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		return 1;
	}
	window = SDL_CreateWindow("Snake By Shulgalt", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, 0);

	return EXIT_SUCCESS;
}
