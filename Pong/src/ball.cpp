#include <SDL_image.h>
#include <iostream>
#include <math.h>      

#include "ball.hpp"


ball::ball(float _x_move, float _y_move) :
	x_move{ _x_move },
	y_move{ _y_move }
{w = 12; h = 12, x = 400; y = 300; r = 100;	g = 100; b = 100; a = 255; }

ball::ball() :
	x_move{ 1 },
	y_move{ 1 }
{w = 12; h = 12, x = 400; y = 300; r = 100;	g = 100; b = 100; a = 255; }

void ball::move_ball() {
	x += x_move / spd;
	y += y_move / spd;
	if (x > 800-w || x < 0) x_move *= -1;
	if (y > 600-h || y < 0) y_move *= -1;
}

void ball::chk_collision(const float &p_x, const float &p_y, const int &p_w, const int &p_h) {

	float x_max = p_x+p_w;
	float x_min = p_x;
	float y_max = p_y+p_h;
	float y_min = p_y;

	if ((x < x_max && x + w > x_min) && (y < y_max && y + h > y_min)) {
		x_move *= -1; 
		//y_move *= -1;
	}

}