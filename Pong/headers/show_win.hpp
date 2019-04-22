#pragma once

#include<SDL_ttf.h>
#include<SDL.h>
#include<string>
#include<vector>

class win {
public:
	win(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &show_win, const SDL_Color &color);

	bool win_chk(int x, int y, SDL_Renderer *renderer, const int &score_p1, const int &score_p2 ) const;
	static SDL_Texture *loadFont(SDL_Renderer *renderer,
		const std::string &font_path,
		int font_size,
		const std::string &show_win,
		const SDL_Color &color);
private:

		SDL_Texture *p1_win_texture = nullptr;
		SDL_Texture *p2_win_texture = nullptr;
	mutable SDL_Rect win_rect;

};