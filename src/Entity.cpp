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

SDL_Texture* Entity::getTexture() { return texture; }
SDL_Rect Entity::getCurrentFrame() { return currentFrame; }