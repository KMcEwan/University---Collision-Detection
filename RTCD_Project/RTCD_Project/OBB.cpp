/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "OBB.h"
#include <iostream>

using namespace std;

void OBB::VelocityVerletSolver(float dt)
{
	move(dt * velocity + 0.5f * dt * dt * acceleration);
	vec2 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void OBB::move(vec2 traslation)
{
	transform.Translate(traslation);
}

void OBB::update(float dt)
{
	VelocityVerletSolver(dt);
}

void OBB::draw(int width, int height)
{
	vec2 position = transform.getPosition();

	glLoadIdentity();				
	float aspectRatio = (width / (float)height);
	vec2 mainDir = (getDirection() * halfextents.x * aspectRatio) / (float)width;
	vec2 orthDir = (getOrtDirection() * halfextents.y) / (float)height;
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  

	glBegin(GL_QUADS);
	glColor3f(color.r, color.g, color.b);
	vec2 vertex = 2.0f * (mainDir + orthDir);
	glVertex2f(vertex.x, vertex.y);
	vertex = 2.0f * (-mainDir + orthDir);
	glVertex2f(vertex.x, vertex.y);
	vertex = 2.0f * (-mainDir - orthDir);
	glVertex2f(vertex.x, vertex.y);
	vertex = 2.0f * (mainDir - orthDir);
	glVertex2f(vertex.x, vertex.y);
	glEnd();
}


void OBB::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}

vec2 OBB::getHalfExtents()
{
	return halfextents;
}

vec2 OBB::getDirection()
{
	return direction;
}

vec2 OBB::getOrtDirection()
{
	return normalize(vec2(-direction.y, direction.x));
}


vec2 OBB::getPosition()
{
	return transform.getPosition();
}

vec2 OBB::getVelocity()
{
	return velocity;
}

void OBB::changeDir(vec2 n, vec2 velOther)
{
	float velProj = dot(velocity, n);
	if (velProj != 0)
		velocity -= 2 * velProj *n;
	else
		velocity += 2 * dot(velOther, n) *n;
}

void OBB::InvertVelocityY()
{
	velocity = vec2(velocity.x, -velocity.y);
}

void OBB::InvertVelocityX()
{
	velocity = vec2(-velocity.x, velocity.y);
}
