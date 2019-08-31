#pragma once
#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\constants.hpp>
#include <GL\glut.h>
#include <iostream>
#include "Object.h"
#include "Transform.h"
#include <algorithm>


using namespace std;
using namespace glm;

class  BorderLine : public Object
{
private:
	vec2 point;
	vec2 direction;
	vec3 color;
	Transform transform;

public:
	BorderLine(vec2& point, vec2& direction) : color(vec3(1.0f, 1.0f, 1.0f)), point(point), direction(direction) {}

	virtual ~BorderLine() {}

	vec2 getPoint();
	vec2 getDirection();
	vec2 getPosition();

	void update(float dt);
	void draw(int width, int height);
	void setColor(float r, float g, float b);
};
