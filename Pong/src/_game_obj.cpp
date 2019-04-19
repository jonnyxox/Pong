#include <iostream>
#include <SDL_image.h>

#include "_game_obj.hpp"

game_obj::game_obj(int _w, int _h, float _x, float _y, int _r, int _g, int _b, int _a) :
	w{ _w }, h{ _h },
	x{ _x }, y{ _y },
	r{ _r }, g{ _g }, b{ _b }, a{ _a }
{}

void game_obj::draw() const {
	SDL_Rect rect = { x,y,w,h };
	SDL_SetRenderDrawColor(window::renderer, r, g, b, a);
	SDL_RenderFillRect(window::renderer, &rect);
}

void game_obj::poll_event(SDL_Event &event) {

}

