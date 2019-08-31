#pragma once
#include <glm\glm.hpp>
#include <gl/glut.h>

class GameWindow
{
	public :
		GameWindow(char* title, int width, int height, int posX, int posY) : width(width), height(height) // Window name, width, height, position
		{
			glutInitDisplayMode(GLUT_DOUBLE);
			glutInitWindowSize(width, height);
			glutInitWindowPosition(posX, posY);
			glutCreateWindow(title);
		}

		virtual ~GameWindow() {}

		void Reshape(GLsizei width, GLsizei height);
		int getWidth();
		int getHeight();


	private:
		int width, height;
		double clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;
};