#pragma once

#include <cmath>
#include <iostream>


class Vector2
{
public:
	float x = 0;
	float y = 0;

	Vector2();
	Vector2(float x, float y);
	Vector2(Vector2& other);
	Vector2(Vector2&& other);
	Vector2& operator=(Vector2& other);

	float Length();
	Vector2 Normalized();
};

