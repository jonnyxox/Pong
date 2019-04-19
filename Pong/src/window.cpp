#include<iostream>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include "window.hpp"

SDL_Renderer *window::renderer = nullptr;

window::window(const std::string &_title, int _width, int _height) :
	title{ _title },
	width{ _width },
	height{ _height }
{
	closed = !init();
}

window::~window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(pong_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialise SDL.\n";
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Failed to intialise SDL_image.\n";
		return false;
	} 

	if (TTF_Init() == -1)
	{
		std::cerr << "Failed to intialise SDL_ttf.\n";
		return false;
	}
	pong_window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height, 0
	);

	if (pong_window == nullptr) {
		std::cerr << "Failed to create window.\n";
		return false;
	}

	window::renderer = SDL_CreateRenderer(pong_window, -1, SDL_RENDERER_ACCELERATED);

	if (window::renderer == nullptr) {
		std::cerr << "Failed to create renderer.\n";
		return false;
	}

	return true;
};

void window::poll_events(SDL_Event &event) {

	switch (event.type) {
	case SDL_QUIT:
		closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			closed = true;
			break;
		}
	default: break;
	}
}

void window::clear() const {
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // sets color for renderer
	SDL_RenderClear(renderer); // gets color onto renderer





}
