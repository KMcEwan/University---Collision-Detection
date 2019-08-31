/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Square.h"
#include <iostream>

using namespace std;

void Square::VelocityVerletSolver(float dt)
{
	move(dt * velocity + 0.5f * dt * dt * acceleration);
	vec2 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Square::move(vec2 traslation)
{
	transform.Translate(traslation);
}

void Square::update(float dt)
{
	VelocityVerletSolver(dt);
}

void Square::draw(int width, int height)
{
	vec2 position = transform.getPosition();

	glLoadIdentity();				
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  

	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(2 * radii.x * aspectRatio / width, 2 * radii.y / height);
	glVertex2f(-2 * radii.x * aspectRatio / width, 2 * radii.y / height);
	glVertex2f(-2 * radii.x * aspectRatio / width, -2 * radii.y / height);
	glVertex2f(2 * radii.x * aspectRatio / width, -2 * radii.y / height);
	glEnd();
}


void Square::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}

vec2 Square::getPosition()
{
	return transform.getPosition();
}

vec2 Square::getRadii()
{
	return radii;
}

vec2 Square::getVelocity()
{
	return velocity;
}

void Square::changeDir(vec2 n, vec2 velOther)
{
	float velProj = dot(velocity, n);
	if (velProj != 0)
		velocity -= 2 * velProj *n;
	else
		velocity += 2 * dot(velOther, n) *n;
}

void Square::InvertVelocityY()
{
	velocity = vec2(velocity.x, -velocity.y);
}

void Square::InvertVelocityX()
{
	velocity = vec2(-velocity.x, velocity.y);
}

vec2 Square:: getOrtDirection()
{
	return direction;
}

vec2 Square::getHalfExtents()
{
	return getRadii();				
}

vec2 Square::getDirection()
{
	return direction;
}