#pragma once
#include <glm\glm.hpp>
#include <GL\glut.h>
#include "Object.h"
#include "Transform.h"
#include <algorithm>
#include <glm\gtc\constants.hpp>

using namespace std;
using namespace glm;

class Line : public Object
{
	public:
		Line(vec2& point, vec2& direction) : color(vec3(1.0f, 1.0f, 1.0f)), point(point), direction(direction) {}

		virtual ~Line() {}

		vec2 getPoint();
		vec2 getDirection();
		vec2 getPosition();

		void update(float dt);
		void draw(int width, int height);
		void setColor(float r, float g, float b);


	private:
		vec2 point;
		vec2 direction;
		vec3 color;
		Transform transform;
};