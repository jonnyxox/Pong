#pragma once
#include<string>
#include<SDL.h>

class window {
public:
	window(const std::string &_title, int _width, int _height);
	~window();

	void poll_events(SDL_Event &event);
	void clear() const;

	inline bool is_closed() const { return closed; }

private:
	bool init();

private:
	std::string title;
	int width{ 800 };
	int height{ 600 };
	bool closed{ false };

	SDL_Window * pong_window = nullptr;

public:
	static SDL_Renderer *renderer;

};