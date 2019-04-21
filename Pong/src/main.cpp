#include <iostream>
#include <vector>
#include <string>

#include "window.hpp"
#include "player.hpp"
#include "ball.hpp"
#include "court.hpp"
#include "show_score.hpp"


void poll_all_events(window &window, const Uint8 *keystate, player &player1, player &player2 ) {
	SDL_Event event;
	player1.poll_events(keystate);
	player2.poll_events(keystate);
	if (SDL_PollEvent(&event)) {
		window.x_close_chk(event);
	}
	window.poll_events(keystate);
}

int main(int argc, char *argv[]) {

	window pong_window("Pong", 800, 600);
	int font_size{ 80 };
	player player1(1, 100, 100);
	player player2(2, 700, 500);
	ball ball(1,1);
	court court_net;
	score score1(window::renderer, "D:/CPP_graphics/Pong/src/bit5x5.ttf", font_size, std::to_string(ball.score_p1), {100, 100, 100, 255});
	score score2(window::renderer, "D:/CPP_graphics/Pong/src/bit5x5.ttf", font_size, std::to_string(ball.score_p2), { 100, 100, 100, 255 });
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	while (!pong_window.is_closed()) {
		SDL_PumpEvents();
		poll_all_events(pong_window, keystate, player1, player2);
		court_net.draw();
		ball.check_scores();
		score1.display(260,100, window::renderer, ball.score_p1);
		score2.display(480,100, window::renderer, ball.score_p2);
	    player1.draw();
		player2.draw();
		ball.chk_collision(player1.x, player1.y, player1.w, player1.h);
		ball.chk_collision(player2.x, player2.y, player2.w, player2.h);
		ball.draw();
		ball.move_ball();
		pong_window.clear();
	}
	return 0;
}