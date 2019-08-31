#pragma once
#pragma once
#include <glm\glm.hpp>
#include <GL\glut.h>
#include <iostream>
#include "Transform.h"
#include "Object.h"


using namespace std;
using namespace glm;

class OBB : public Object
{
public:
	OBB(vec2& center, vec2& direction, vec2& halfextents, vec2& vel, vec2& acc) :direction(normalize(direction)), halfextents(halfextents), velocity(vel), acceleration(acc)
	{
		move(center);
	};

	virtual ~OBB() {}

	vec2 getPosition();

	vec2 getDirection();

	vec2 getHalfExtents();

	vec2 getOrtDirection();

	vec2 getRadii();

	vec2 getVelocity();

	void setColor(float r, float g, float b);

	void move(vec2 traslation);	

	void changeDir(vec2 n, vec2 velOther);

	void InvertVelocityX();

	void InvertVelocityY();

private:
	vec2 center;
	vec2 direction;
	vec2 halfextents;

	vec2 velocity;
	vec2 acceleration;
	vec3 color;
	Transform transform;

	void VelocityVerletSolver(float dt);
	
	void update(float dt);
	void draw(int width, int height);
};