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

	Ball(Vector2f p_position, SDL_Texture* p_texture) {
		position = p_position;

		currentFrame.x = 0;
		currentFrame.y = 0;
		currentFrame.w = 16;
		currentFrame.h = 16;

		texture = p_texture;
		velocity = 2.0f;
		direction_x = 1.0f;
		direction_y = -1.0f;
	}

	~Ball() { }

	void DrawRect() {
		currentFrame.x = position.x;
		currentFrame.y = position.y;
	}

	float getX() { return position.x; }
	float getY() { return position.y; }
	float getVelocity() { return velocity; }

	float getDirectionX() { return direction_x; }
	float getDirectionY() { return direction_y; }

	void setX(float p_x) { position.x = p_x; }
	void setY(float p_y) { position.y = p_y; }
	void setVelocity(float p_vel) { velocity = p_vel; }

	void setDirection(float p_x, float p_y) { 
		direction_x = p_x; 
		direction_y = p_y;
	}

	SDL_Texture* getTexture() { return texture; }
	SDL_Rect getCurrentFrame() { return currentFrame; }

	SDL_Rect* getRectPtr() { return &currentFrame; }

	
};