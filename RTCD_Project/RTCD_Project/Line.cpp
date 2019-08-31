/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Line.h"

vec2 Line::getPoint()
{
	return point;
}

void Line::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}


vec2 Line::getDirection()
{
	return direction;
}

vec2 Line::getPosition()
{
	return transform.getPosition();
}

void Line::update(float dt)
{
}

void Line::draw(int width, int height)
{	
	float halfWidth = 0.5f * width;
	float halfHeight = 0.5f * height;
	float aspectRatio = (width / (float)height);

	float magnifier = 15.0f; 
	vec2 stretchedDirection = magnifier * direction;  

	glLoadIdentity();
	glLineWidth(1);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES); 
	glVertex2f(((point.x - stretchedDirection.x) / halfWidth - 1.0f) * aspectRatio, (point.y - stretchedDirection.y) / halfHeight - 1.0f); 
	glVertex2f(((point.x + stretchedDirection.x) / halfWidth - 1.0f) * aspectRatio, (point.y + stretchedDirection.y) / halfHeight - 1.0f); 
	glEnd();
}