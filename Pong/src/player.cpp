#include <SDL_image.h>
#include <iostream>

#include "player.hpp"

player::player(int _n, float _x, float _y) :
	n{ _n }
{
	w = 10; h = 60, x = _x, y = _y, r = 100; g = 100; b = 100; a = 255;
}


/*void player::poll_events(SDL_Event &event) {
	if (n == 2) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				y -= 10;
				break;
			case SDLK_DOWN:
				y += 10;
				break;
			}
		}

	}
	if (n == 1) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_a:
				y -= 10;
				break;
			case SDLK_z:
				y += 10;
				break;
			}
		}
	}

	if (1 == 1) { ; }


	if (y > (600 - h)) y = 600 - h;
	if (y < 0) y = 0;
}*/

void player::poll_events(const Uint8 *keystate)
{

	if (n == 2) {
		if (keystate[SDL_SCANCODE_UP]) {
			y -= 1 /  spd;
		}
		else if (keystate[SDL_SCANCODE_DOWN]) {
			y += 1 / spd;
		}
	}
	if (n == 1) {
		if (keystate[SDL_SCANCODE_A]) {
			y -= 1 / spd;
		}
		else if (keystate[SDL_SCANCODE_Z]) {
			y += 1 / spd;
		}
	}
	if (y > (600. - h)) y = 600.0 - h;
	if (y < 0) y = 0;
}