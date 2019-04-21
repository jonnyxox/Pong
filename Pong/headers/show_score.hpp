#pragma once

#include<SDL_ttf.h>
#include<SDL.h>
#include<string>
#include<vector>

class score {
public:
	score(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &show_score, const SDL_Color &color);
	void display(int x, int y, SDL_Renderer *renderer, int player_score) const;
	static SDL_Texture *loadFont(SDL_Renderer *renderer,
		const std::string &font_path,
		int font_size,
		const std::string &show_score,
		const SDL_Color &color);
private:
	SDL_Texture *score_texture = nullptr;
	mutable SDL_Rect score_rect;
	std::vector<SDL_Texture*> texture_number; // this is a vector of pointers
};