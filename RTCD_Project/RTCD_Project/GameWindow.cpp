/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "GameWindow.h"

void GameWindow::Reshape(GLsizei width, GLsizei height)
{	
	if (height == 0) height = 1;               
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	
	glViewport(0, 0, width, height);
		
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();             
	if (width >= height) {
		clipAreaXLeft = -1.0 * aspect;
		clipAreaXRight = 1.0 * aspect;
		clipAreaYBottom = -1.0;
		clipAreaYTop = 1.0;
	}
	else {
		clipAreaXLeft = -1.0;
		clipAreaXRight = 1.0;
		clipAreaYBottom = -1.0 / aspect;
		clipAreaYTop = 1.0 / aspect;
	}
	gluOrtho2D(clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop);
}

int GameWindow::getWidth()
{
	return width;
}

int GameWindow::getHeight()
{
	return height;
}