#include <iostream>

#include "Math.hpp"

using namespace std;

namespace math {

	void Vector2f::setX(float p_x) { x = p_x; }
	void Vector2f::setY(float p_y) { y = p_y; }

	void Vector2f::print() { cout << x << ", " << y << endl; }


	int Random::randInt(int p_min, int p_max) {
		return min + (rand() % static_cast<int>(max - min + 1));
	}
}