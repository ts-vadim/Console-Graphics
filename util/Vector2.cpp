#include "Vector2.h"


Vector2::Vector2()
{
	std::cout << "Vector2() created: " << this << std::endl;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
	std::cout << "Vector2(x, y): " << this << std::endl;
}

Vector2::Vector2(Vector2& other)
{
	x = other.x;
	y = other.y;
	std::cout << "Vector2(&): " << this << " from " << &other << std::endl;
}

Vector2::Vector2(Vector2&& other)
{
	x = other.x;
	y = other.y;
	std::cout << "Vector2(&&): " << this << " from " << &other << std::endl;
}

Vector2& Vector2::operator=(Vector2& other)
{
	std::cout << "Vector2: " << this << " = " << &other << std::endl;
	x = other.x;
	y = other.y;
	return *this;
}

float Vector2::Length()
{
	return sqrtf(pow(x, 2) + pow(y, 2));
}

Vector2 Vector2::Normalized()
{
	float length = Length();
	return Vector2(x / length, y / length);
}