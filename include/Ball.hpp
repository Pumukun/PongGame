#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>

#include "Math.hpp"
#include "Entity.hpp"

class Ball {
protected:
	Vector2f position;
	SDL_Rect currentFrame;
	SDL_Texture* texture;

	float velocity;

	float direction_x, direction_y;

public:

	Ball(Vector2f p_position, SDL_Texture* p_texture);

	~Ball() = default;

	void DrawRect();

	float getX();
	float getY();
	float getVelocity();

	float getDirectionX();
	float getDirectionY();

	void setX(float p_x);
	void setY(float p_y);
	void setVelocity(float p_vel);

	void setDirection(float p_x, float p_y);

	SDL_Texture* getTexture();
	SDL_Rect getCurrentFrame();

	SDL_Rect* getRectPtr();
};
