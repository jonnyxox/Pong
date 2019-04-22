#include <iostream>
#include "window.hpp"
#include "show_win.hpp"

win::win(SDL_Renderer *renderer,
	const std::string &font_path,
	int font_size,
	const std::string &show_win,
	const SDL_Color &color)
{
		p1_win_texture = loadFont(renderer, font_path, font_size, "Player 1 Wins, Press Space to Restart Game", color);
		SDL_QueryTexture(p1_win_texture, nullptr, nullptr, &win_rect.w, &win_rect.h);
		p2_win_texture = loadFont(renderer, font_path, font_size, "Player 2 Wins, Press Space to Restart Game", color);
		SDL_QueryTexture(p1_win_texture, nullptr, nullptr, &win_rect.w, &win_rect.h);
}

bool win::win_chk(int x, int y, SDL_Renderer *renderer, const int &score_p1, const int &score_p2) const
{
	int score_to_win_game = 9;
	if (score_p1 > score_to_win_game && score_p1 > score_p2) {
		win_rect.x = x;
		win_rect.y = y;
		SDL_RenderCopy(renderer, p1_win_texture, nullptr, &win_rect);
		return false;
	}
	if (score_p2 > score_to_win_game && score_p2 > score_p1) {
		win_rect.x = x;
		win_rect.y = y;
		SDL_RenderCopy(renderer, p2_win_texture, nullptr, &win_rect);
		return false;
	}
	return true;
}

SDL_Texture *win::loadFont(SDL_Renderer *renderer,
	const std::string &font_path,
	int font_size,
	const std::string &show_win,
	const SDL_Color &color)
{
	TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
	std::cout << "font: " << font << "\n";
	if (!font) {
		std::cerr << "Failed to load font.\n";
	}
	auto win_surface = TTF_RenderText_Solid(font, show_win.c_str(), color);

	if (!win_surface) {
		std::cerr << "Failed to create score surface.\n";
	}
	auto win_texture = SDL_CreateTextureFromSurface(renderer, win_surface);
	if (!win_texture) {
		std::cerr << "Failed to create score texture.\n";
	}
	SDL_FreeSurface(win_surface);
	return win_texture;
}