#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height):window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
	if (window == NULL)
		cout << "Window failed to init. ERROR: " << SDL_GetError() << endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		cout << "Failed to load Texture. ERROR: " << SDL_GetError() << endl;

	return texture;
}

int RenderWindow::getRefreshRate() {
	int displayIndex = SDL_GetWindowDisplayIndex(window);

	SDL_DisplayMode mode;

	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &p_entity) {
	// Какой должна быть текстура
	SDL_Rect source;
	source.x = p_entity.getCurrentFrame().x; 
	source.y = p_entity.getCurrentFrame().y;
	source.w = p_entity.getCurrentFrame().w;
	source.h = p_entity.getCurrentFrame().h;

	// Какая будет на выходе
	SDL_Rect destination;
	destination.x = p_entity.getPosition().x;
	destination.y = p_entity.getPosition().y;
	destination.w = p_entity.getCurrentFrame().w;
	destination.h = p_entity.getCurrentFrame().h;


	SDL_RenderCopy(renderer, p_entity.getTexture(), &source, &destination);
}

void RenderWindow::render(Ball &p_ball) {
	SDL_Rect source;
	source.x = p_ball.getCurrentFrame().x; 
	source.y = p_ball.getCurrentFrame().y;
	source.w = p_ball.getCurrentFrame().w;
	source.h = p_ball.getCurrentFrame().h;

	// Какая будет на выходе
	SDL_Rect destination;
	destination.x = p_ball.getX();
	destination.y = p_ball.getY();
	destination.w = p_ball.getCurrentFrame().w;
	destination.h = p_ball.getCurrentFrame().h;


	SDL_RenderCopy(renderer, p_ball.getTexture(), &source, &destination);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp() { SDL_DestroyWindow(window); }
