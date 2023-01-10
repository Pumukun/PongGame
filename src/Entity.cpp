#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture, int p_width, int p_height):position(p_position), texture(p_texture) {
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_width;
	currentFrame.h = p_height;
}

Vector2f &Entity::getPosition() { return position; }
void Entity::setPosX(float p_x) { position.x = p_x; }
void Entity::setPosY(float p_y) { position.y = p_y; }

void Entity::setTexture(SDL_Texture* p_texture) { texture = p_texture; }

SDL_Texture* Entity::getTexture() { return texture; }
SDL_Rect Entity::getCurrentFrame() { return currentFrame; }

SDL_Rect* Entity::getRectPtr() { return &currentFrame; }