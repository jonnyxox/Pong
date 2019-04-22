#pragma once

#include <string>
#include "window.hpp"

class game_obj {
public:
	game_obj(int _w, int _h, float _x, float _y, int _r, int _g, int _b, int _a);
	game_obj() = default;
	~game_obj() = default;

	void draw() const;
	//void poll_event(SDL_Event &event);
	
	int w{ 0 }, h{ 0 };
	float x{ 0 }, y{ 0 };
	int r{ 200 }, g{ 200 }, b{ 200 }, a{ 255 };
};