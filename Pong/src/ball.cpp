#include <SDL_image.h>
#include <iostream>
#include <math.h>
#include <algorithm>    // std::min

#include "window.hpp"
#include "ball.hpp"
#include "show_score.hpp"


ball::ball(float _x_move, float _y_move) :
	x_move{ _x_move },
	y_move{ _y_move }
{w = 12; h = 12, x = 400; y = 300; r = 100;	g = 100; b = 100; a = 255; 
}

/*ball::ball() :
	x_move{ 1 },
	y_move{ 0 }
{w = 12; h = 12, x = 400; y = 300; r = 100;	g = 100; b = 100; a = 255; 
}*/

void ball::move_ball() {
	x += x_move / spd;
	y += y_move / spd;
	if (x > 800-w || x < 0) x_move *= -1;
	if (y > 600-h || y < 0) y_move *= -1;
}

void ball::chk_collision(const float &p_x, const float &p_y, const int &p_w, const int &p_h) {

	float x_max = p_x + p_w;
	float x_min = p_x;
	float y_max = p_y + p_h;
	float y_min = p_y;
	float y_mid = p_y + p_h / 2.0;
	float y_diff =  y - y_mid;

	if ((x < x_max && x + w > x_min) && (y < y_max && y + h > y_min)) {
	// bat back
		x_move *= -1; 
		y_move += y_diff / p_h;
		y_move = std::min(y_move, float(1.0));
	}
}

void ball::check_scores() {
	if (ball_in_play && x < 80) {
		ball_in_play = false;
		score_p1 += 1;
		std::cout << std::boolalpha << ball_in_play << ",p1 " << score_p1 << "\n";
	}
	if (ball_in_play && x > 720) {
		ball_in_play = false;
		score_p2 += 1;
		std::cout << std::boolalpha << ball_in_play << ",p2 " << score_p2 << "\n";
	}
	if (x > 100 && x < 700) { ball_in_play = true; }
}