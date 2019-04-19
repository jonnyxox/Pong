#include <iostream>
#include <stdexcept>

#include "window.hpp"
#include "score.hpp"

score::score(SDL_Renderer *renderer,
	const std::string &font_path,
	int font_size,
	const std::string &show_score,
	const SDL_Color &color)
{
	score_texture = loadFont(renderer, font_path, font_size, show_score, color);
	SDL_QueryTexture(score_texture, nullptr, nullptr, &score_rect.w, &score_rect.h);
}

void score::display(int x, int y, SDL_Renderer *renderer) const {
	score_rect.x = x;
	score_rect.y = y;
	SDL_RenderCopy(renderer, score_texture, nullptr, &score_rect);
}

SDL_Texture *score::loadFont(SDL_Renderer *renderer,
	const std::string &font_path,
	int font_size,
	const std::string &show_score,
	const SDL_Color &color)
{
//	try {
		TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
		std::cout << "font: "<< font << "\n";
		if (!font) {
			std::cerr << "Failed to load font.\n";
		}

	/*	if (font == NULL) {
			throw(::std::runtime_error("Font failed to load! ERROR: "));
		}
	}
	catch (std::runtime_error const& msg)
	{
		printf("%s", msg.what());
		if (SDL_GetError() != NULL)
		{
			printf("%s", SDL_GetError());
		}
		if (TTF_GetError() != NULL)
		{
			printf("%s", TTF_GetError());
		}
	}*/
	
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