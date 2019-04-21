#include <SDL_image.h>
#include <iostream>

#include "player.hpp"

player::player(int _n, float _x, float _y) :
	n{ _n }
{
	w = 10; h = 60, x = _x, y = _y, r = 100; g = 100; b = 100; a = 255;
}

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
	if (y > (600.0 - h)) y = 600.0 - h;
	if (y < 0) y = 0;
}