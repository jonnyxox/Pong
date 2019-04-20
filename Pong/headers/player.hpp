#pragma once

#include <string>
#include "window.hpp"
#include "_game_obj.hpp"

class player : public game_obj {
public:
	player(int n, float _x, float _y);
	~player() = default;
	//void poll_events(SDL_Event &event);
	void poll_events(const Uint8 *keystate);

	int score{ 0 };
private:
	int n;
	float spd{ 10 };

};