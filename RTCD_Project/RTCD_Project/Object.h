#pragma once
#include <glm\glm.hpp>

using namespace glm;

class Object
{
public:
	virtual vec2 getPosition() = 0;
	virtual void update(float dt) = 0;
	virtual void draw(int width, int height) = 0;
};