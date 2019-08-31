/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Circle.h"
#include <iostream>

using namespace std;

void Circle::VelocityVerletSolver(float dt)
{
	move(dt * velocity + 0.5f * dt * dt * acceleration);
	vec2 velInBetween = velocity + 0.5f * dt * acceleration;
	velocity = velInBetween + 0.5f * acceleration;
}

void Circle::move(vec2 traslation)
{
	transform.Translate(traslation);
}

void Circle::update(float dt)
{
	VelocityVerletSolver(dt);
}

void Circle::draw(int width, int height) 
{
	vec2 position = transform.getPosition();
	glLoadIdentity();				
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  

																 
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(color.r, color.g, color.b);						
	glVertex2f(0.0f, 0.0f);										
	int numSegments = 100;
	float angle;
	for (int i = 0; i <= numSegments; i++) {					
		angle = i * 2.0f * pi<float>() / numSegments;			
		glVertex2f(cos(angle) * (2.0f * radius / width)* aspectRatio,
			sin(angle) * (2.0f * radius / height));
	}
	glEnd();
}

void Circle::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}

vec2 Circle::getPosition()
{
	return transform.getPosition();
}

float Circle::getRadius()
{
	return radius;
}

vec2 Circle::getVelocity()
{
	return velocity;
}

void Circle::InvertVelocityY()
{
	velocity = vec2(velocity.x, -velocity.y);
}

void Circle::InvertVelocityX()
{
	velocity = vec2(-velocity.x, velocity.y);
}

void Circle::changeDir(vec2 n, vec2 velOther)
{
	float velProj = dot(velocity, n);
	if (velProj != 0)
		velocity -= 2 * velProj *n;
	else
		velocity += 2 * dot(velOther, n) *n;
}
