#pragma once

#include "Graphics.h"
#include "../util/Vector2.h"



class Drawable
{
public:
	FrameBuffer frame;
	Vector2 position;

	virtual void Draw(Graphics& graphics) = 0;
};
