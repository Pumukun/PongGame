#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>

#include "Math.hpp"
#include "Entity.hpp"


Ball::Ball(Vector2f p_position, SDL_Texture* p_texture) {
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

void Ball::DrawRect() {
	currentFrame.x = position.x;
	currentFrame.y = position.y;
}

float Ball::getX() { return position.x; }
float Ball::getY() { return position.y; }
float Ball::getVelocity() { return velocity; }

float Ball::getDirectionX() { return direction_x; }
float Ball::getDirectionY() { return direction_y; }

void Ball::setX(float p_x) { position.x = p_x; }
void Ball::setY(float p_y) { position.y = p_y; }
void Ball::setVelocity(float p_vel) { velocity = p_vel; }

void Ball::setDirection(float p_x, float p_y) { 
	direction_x = p_x; 
	direction_y = p_y;
}

SDL_Texture* Ball::getTexture() { return texture; }
SDL_Rect Ball::getCurrentFrame() { return currentFrame; }

SDL_Rect* Ball::getRectPtr() { return &currentFrame; }
