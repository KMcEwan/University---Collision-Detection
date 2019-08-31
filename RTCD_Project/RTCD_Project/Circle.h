#pragma once
#include <glm\glm.hpp>
#include <gl/glut.h>
#include <iostream>
#include "Object.h"
#include "Transform.h"
#include <algorithm>
#include <glm\gtc\constants.hpp>

using namespace std;
using namespace glm;

class Circle : public Object
{
	public:
		Circle(float r, vec2& pos, vec2& vel, vec2& acc) : color(vec3(1.0f, 1.0f, 1.0f)),
			radius(r), velocity(vel), acceleration(acc)
		{
			move(pos);
		}

		virtual ~Circle() {}

		vec2 getPosition();
		vec2 getVelocity();

		float getRadius();

		void setColor(float r, float g, float b);
		
		void update(float dt);
		void draw(int width, int height);
		void move(vec2 traslation);
		void changeDir(vec2 n, vec2 velOther);
		void InvertVelocityX();
		void InvertVelocityY();

	private:
		float radius;
		vec2 velocity;
		vec2 acceleration;
		vec3 color;
		void VelocityVerletSolver(float dt);
		Transform transform;
		

};