#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Ball.hpp"

class Entity {
protected:
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;

public:
	Entity(Vector2f p_position, SDL_Texture* p_texture, int p_width, int p_height);
	Vector2f &getPosition();
	void setPosX(float p_x);
	void setPosY(float p_y);

	void setTexture(SDL_Texture* p_texture);

	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();

	SDL_Rect* getRectPtr();
};
