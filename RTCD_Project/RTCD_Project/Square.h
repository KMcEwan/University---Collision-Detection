#pragma once
#include <glm\glm.hpp>
#include <GL\glut.h>
#include <iostream>
#include "Transform.h"
#include "Object.h"


using namespace std;
using namespace glm;

class Square : public Object
{
public:
	Square(vec2 radii, vec2& pos, vec2& vel, vec2& acc) : color(vec3(1.0f, 1.0f, 1.0f)),
		radii(radii), velocity(vel), acceleration(acc)
	{
		move(pos);
		direction = vec2(0,1);
		halfextents = vec2(1, 0);
	}

	
	 vec2 getOrtDirection(); 	

	virtual ~Square() {}

	vec2 getPosition();

	vec2 getRadii();

	vec2 getVelocity();

	void setColor(float r, float g, float b);

	void move(vec2 traslation);

	void changeDir(vec2 n, vec2 velOther);

	void InvertVelocityX();

	void InvertVelocityY();
		
	void update(float dt);
	void draw(int width, int height);

	vec2 getDirection();

	vec2 getHalfExtents();

private:
	vec2 radii;
	vec2 velocity;
	vec2 acceleration;
	vec3 color;
	void VelocityVerletSolver(float dt);
	Transform transform;
	vec2 direction;
	vec2 halfextents;
};