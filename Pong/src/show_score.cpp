#include <iostream>
#include "window.hpp"
#include "show_score.hpp"

score::score(SDL_Renderer *renderer,
	const std::string &font_path,
	int font_size,
	const std::string &show_score,
	const SDL_Color &color)
{
	for (int i = 0; i < 10; ++i) {
		score_texture = loadFont(renderer, font_path, font_size, std::to_string(i), color);
		SDL_QueryTexture(score_texture, nullptr, nullptr, &score_rect.w, &score_rect.h);
		texture_number.push_back(score_texture);
	}
}

void score::display(int x, int y, SDL_Renderer *renderer, int player_score) const {
	score_rect.x = x;
	score_rect.y = y;
	SDL_RenderCopy(renderer, texture_number[player_score], nullptr, &score_rect);
}

SDL_Texture *score::loadFont(SDL_Renderer *renderer,
	const std::string &font_path,
	int font_size,
	const std::string &show_score,
	const SDL_Color &color)
{
		TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
		std::cout << "font: "<< font << "\n";
		if (!font) {
			std::cerr << "Failed to load font.\n";
		}
	auto score_surface = TTF_RenderText_Solid(font, show_score.c_str(), color);

	if (!score_surface) {
		std::cerr << "Failed to create score surface.\n";
	}
	auto score_texture = SDL_CreateTextureFromSurface(renderer, score_surface);
	if (!score_texture) {
		std::cerr << "Failed to create score texture.\n";
	}
	SDL_FreeSurface(score_surface);
	return score_texture;
}