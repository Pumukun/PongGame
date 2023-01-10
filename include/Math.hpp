#pragma once

#include <iostream>

using namespace std;

class Vector2f {
public:
	float x, y;

	Vector2f(): x(0.0f), y(0.0f) { }

	Vector2f(float p_x, float p_y): x(p_x), y(p_y) { }

	~Vector2f() = default;

	void setX(float p_x) { x = p_x; }
	void setY(float p_y) { y = p_y; }

	void print() {
		cout << x << ", " << y << endl;
	}
};