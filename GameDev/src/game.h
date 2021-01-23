/*
 * game.h
 *
 *  Created on: 23 янв. 2021 г.
 *      Author: Paper
 */
#include <sdl.h>
#ifndef GAME_H_
#define GAME_H_

struct Game {
	struct Snake * snake;
	int points;
	int alive;
};

#endif /* GAME_H_ */
