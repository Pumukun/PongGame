#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Ball.hpp"

using namespace std;

void ballMovement(Ball &p_ball, bool CollisionCond1, bool CollisionCond2, int WallCol) {
	float vel = p_ball.getVelocity();
	float b_x = p_ball.getX();
	float b_y = p_ball.getY();

	p_ball.setX(b_x + (vel * p_ball.getDirectionX()));
	p_ball.setY(b_y + (vel * p_ball.getDirectionY()));

	if (CollisionCond1) {
		p_ball.setX(p_ball.getX() + 5);
		p_ball.setDirection(-p_ball.getDirectionX(), p_ball.getDirectionY());
	}
	if (CollisionCond2) {
		p_ball.setX(p_ball.getX() - 5);
		p_ball.setDirection(-p_ball.getDirectionX(), p_ball.getDirectionY());
	}

	switch(WallCol) {
	case 0:
		break;
	case 1:
		p_ball.setY(p_ball.getY() + 5);
		p_ball.setDirection(p_ball.getDirectionX(), -p_ball.getDirectionY());
		break;
	case 2:
		p_ball.setY(p_ball.getY() - 5);
		p_ball.setDirection(p_ball.getDirectionX(), -p_ball.getDirectionY());
		break;
	default:
		break; 
	}
}

int WallCollision(Ball &p_ball) {
	// Collision with walls
	if (p_ball.getY() <= 0) return 1;
	if (p_ball.getY() + 16 >= 256) return 2;
	return 0;
}

bool collisionCheck(Ball &p_ball, Entity &p_entity) {
	// Collision with player
	if (p_entity.getPosition().x > 256) {
		if (p_ball.getX() + 16 >= p_entity.getPosition().x && (p_ball.getY() >= p_entity.getPosition().y && p_ball.getY() <= p_entity.getPosition().y + 64 - 16))
			return true;
	} else {
		if (p_ball.getX() - 16 <= p_entity.getPosition().x && (p_ball.getY() >= p_entity.getPosition().y && p_ball.getY() <= p_entity.getPosition().y + 64 - 16))
			return true;
	}
	return false;
}

void PlayersPositionCheck(Entity &Player1, Entity &Player2, float &player1_vel, float &player2_vel) {
	Player1.setPosY(Player1.getPosition().y + player1_vel);
	Player2.setPosY(Player2.getPosition().y + player2_vel);

	if (Player1.getPosition().y < -1) {
		Player1.setPosY(1);
		player1_vel = 0;
	}
	if (Player1.getPosition().y > 256 - 63) {
		Player1.setPosY(255 - 64);
		player1_vel = 0;
	}

	if (Player2.getPosition().y < -1) {
		Player2.setPosY(1);
		player2_vel = 0;
	}
	if (Player2.getPosition().y > 256 - 63) {
		Player2.setPosY(255 - 64);
		player2_vel = 0;
	}

	if (player1_vel > 2) player1_vel = 2;
	if (player1_vel < -2) player1_vel = -2;

	if (player2_vel > 2) player2_vel = 2;
	if (player2_vel < -2) player2_vel = -2;
}

int score_cnt1 = 0;
int score_cnt2 = 0;

void ScoreCounter(Ball &p_ball, Entity &p_player1, Entity &p_player2, vector<SDL_Texture*> &p_digits, Entity &ldig1, Entity &ldig2, Entity &rdig1, Entity &rdig2) {

	if (p_ball.getX() > 515 || p_ball.getX() < -19) {
		int random_1_2 = rand() % 2 + 1;

		p_ball.setX(256);
		p_ball.setY(128);

		if (random_1_2 == 1) 
			p_ball.setDirection(p_ball.getDirectionX(), -p_ball.getDirectionY());
		else p_ball.setDirection(-p_ball.getDirectionX(), p_ball.getDirectionY());

		p_player1.setPosY(96);
		p_player2.setPosY(96);

		cout << score_cnt1 << ", " << score_cnt2 << endl;

		ldig1.setTexture(p_digits[score_cnt1 / 10]);
		ldig2.setTexture(p_digits[score_cnt1 % 10]);

		rdig2.setTexture(p_digits[score_cnt2 / 10]);
		rdig1.setTexture(p_digits[score_cnt2 % 10]);

		SDL_Delay(2000);
	}

	if (p_ball.getX() > 513)
		score_cnt1++;
	if (p_ball.getX() < -17)
		score_cnt2++;
}

int main(int argc, char* args[]) {

	// Инициализация библиотеки SDL и проверка все ли норм
	if (SDL_Init(SDL_INIT_VIDEO) > 0) 
		cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << endl;
	if (!IMG_Init(IMG_INIT_PNG))
		cout << "IMG_INIT HAS FAILED. ERROR: " << SDL_GetError() << endl;

	// Инициализация окна
	RenderWindow window("game v1.0", 512, 256); 


	// Загрузка текстур
	SDL_Texture* rackTexture = window.loadTexture("res/gfx/racket.png");
	SDL_Texture* ballTexture = window.loadTexture("res/gfx/ball.png");

	SDL_Texture* digit0 = window.loadTexture("res/gfx/0_dig.png");
	SDL_Texture* digit1 = window.loadTexture("res/gfx/1_dig.png");
	SDL_Texture* digit2 = window.loadTexture("res/gfx/2_dig.png");
	SDL_Texture* digit3 = window.loadTexture("res/gfx/3_dig.png");
	SDL_Texture* digit4 = window.loadTexture("res/gfx/4_dig.png");
	SDL_Texture* digit5 = window.loadTexture("res/gfx/5_dig.png");
	SDL_Texture* digit6 = window.loadTexture("res/gfx/6_dig.png");
	SDL_Texture* digit7 = window.loadTexture("res/gfx/7_dig.png");
	SDL_Texture* digit8 = window.loadTexture("res/gfx/8_dig.png");
	SDL_Texture* digit9 = window.loadTexture("res/gfx/9_dig.png");

	vector<SDL_Texture*> digits = {digit0, digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8, digit9};

	Entity LeftDigit1({96, 10}, digits[0], 16, 16);
	Entity LeftDigit2({96 + 18, 10}, digits[0], 16, 16);
	Entity RightDigit1({512 - 96, 10}, digits[0], 16, 16);
	Entity RightDigit2({512 - 96 - 18, 10}, digits[0], 16, 16);

	Entity Player1({10, 96}, rackTexture, 16, 64);
	Entity Player2({486, 96}, rackTexture, 16, 64);

	Ball ball({256, 128}, ballTexture);

	
	bool gameRunning = true;
	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f; // Обновления экрана, каждый раз когда заполнится аккумулятор
	float currentTime = utils::hireTimeInSeconds();

	float player1_vel = 0, player2_vel = 0;

	// main game loop
	while (gameRunning) {
		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= timeStep) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT)
					gameRunning = false;

				switch(event.type) {
            	/* Look for a keypress */
            	case SDL_KEYDOWN:
                	/* Check the SDLKey values and move change the coords */
                	switch(event.key.keysym.sym) {
                    case SDLK_UP:
                        player2_vel -= 2;
                        break;
                    case SDLK_DOWN:
                        player2_vel += 2;
                        break;

                    case SDLK_w:
                        player1_vel -= 2;
                        break;
                    case SDLK_s:
                        player1_vel += 2;
                        break;
                    default:
                        break;
                	}
                }

                switch(event.type) {
                	case SDL_KEYUP:
                	switch(event.key.keysym.sym){
                    case SDLK_UP:
                        if(player2_vel < 0)
                            player2_vel = 0;
                        break;
                    case SDLK_DOWN:
                        if(player2_vel > 0)
                            player2_vel = 0;
                        break;

                   	case SDLK_w:
                        if(player1_vel < 0)
                            player1_vel = 0;
                        break;
                    case SDLK_s:
                        if(player1_vel > 0)
                            player1_vel = 0;
                        break;

                    default:
                        break;
                }
                break;
            
            	default:
                	break;
        	}		
		}

			accumulator -= timeStep;
		}

		// Texture display
		window.clear();

		window.render(Player1);
		window.render(Player2);
		window.render(ball);

		window.render(LeftDigit1);
		window.render(LeftDigit2);
		window.render(RightDigit1);
		window.render(RightDigit2);

		window.display();

		int WallCol = WallCollision(ball);
		bool CollisionPlayer1 = collisionCheck(ball, Player1);
		bool CollisionPlayer2 = collisionCheck(ball, Player2);
		

		PlayersPositionCheck(Player1, Player2, player1_vel, player2_vel);
		ballMovement(ball, CollisionPlayer1, CollisionPlayer2, WallCol);
		ScoreCounter(ball, Player1, Player2, digits, LeftDigit1, LeftDigit2, RightDigit1, RightDigit2);

		int frameTicks = SDL_GetTicks() - startTicks;

		if (frameTicks < 1000 / window.getRefreshRate())
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
