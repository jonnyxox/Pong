#pragma once

#include "_game_obj.hpp"

class ball : public game_obj {
public:
	ball(float _x_move, float _y_move);
	ball();

	void move_ball();
	void chk_collision(const float &p_x, const float &p_y, const int &p_w, const int &p_h);
	void check_scores();

public:
	int score_p1{ 0 };
	int score_p2{ 0 };

private:
	float x_move{ 0.0 }, y_move{ 0.0 };
	float spd{ 10.0};
	bool ball_in_play{ true };
};
