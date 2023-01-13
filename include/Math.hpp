#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

namespace math {

	class Vector2f {
	public:
		float x, y;

		Vector2f(): x(0.0f), y(0.0f) { }

		Vector2f(float p_x, float p_y): x(p_x), y(p_y) { }

		~Vector2f() = default;

		void setX(float p_x);
		void setY(float p_y);

		void print();
	};

	class Random {
	public:
		// Returns random int
		static int randInt(int p_min, int p_max);
	};
}
