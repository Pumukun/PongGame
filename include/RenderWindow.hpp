#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "Ball.hpp"

using namespace std;

class RenderWindow {
protected:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:

	RenderWindow(const char* p_title, int p_width, int p_height);
	SDL_Texture* loadTexture(const char* p_filePath);

	int getRefreshRate();

	void clear();
	void render(Entity &p_entity);
	void render(Ball &p_ball);
	void display();

	void cleanUp();
};
