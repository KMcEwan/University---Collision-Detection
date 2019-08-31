/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "BorderLine.h"

vec2 BorderLine::getPoint()
{
	return point;
}

void BorderLine::setColor(float r, float g, float b)
{
	color = vec3(r, g, b);
}


vec2 BorderLine::getDirection()
{
	return direction;
}

// This method is required by the Object superclass and must have an implementation (in this istance the empty implementation)
void BorderLine::update(float dt)
{
}

// This method is required by the Object superclass and must have an implementation
void BorderLine::draw(int width, int height)
{
	// OpenGL draws in a reference system that is centered in the center of a square that has side 2 (Clipping Space, goes from -1 to 1 in both directions), anything outside of this square is not rendered. 
	// OpenGL then stretches such square to fit the actual window on the screen.
	// To make sure that no deformation apears and that objects are visible into the window on the screen you need to transform points coordinates back into the Clipping Space
	float halfWidth = 0.5f * width;
	float halfHeight = 0.5f * height;
	float aspectRatio = (width / (float)height);

	float magnifier = 15.0f; // OpenGL BorderLines are segments not BorderLines so they will be drawn only between the points specified, to make them look like BorderLines the points need to be positioned outside the window
	vec2 stretchedDirection = magnifier * direction; // By adding and subtracting the direction of the BorderLine that is stretched to the point of the BorderLine the start and end point of the OpenGL BorderLine end up outside the window 

	glLoadIdentity();
	glLineWidth(1);
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES); // This comand draws segments not BorderLines
	glVertex2f(((point.x - stretchedDirection.x) / halfWidth - 1.f) * aspectRatio, (point.y - stretchedDirection.y) / halfHeight - 1.0f); // Starting point of the GL_BorderLineS
	glVertex2f(((point.x + stretchedDirection.x) / halfWidth - 1.0f) * aspectRatio, (point.y + stretchedDirection.y) / halfHeight - 1.0f); // Ending point of the GL_BorderLineS
	glEnd();
}

vec2 BorderLine::getPosition()
{
	return transform.getPosition();
}

