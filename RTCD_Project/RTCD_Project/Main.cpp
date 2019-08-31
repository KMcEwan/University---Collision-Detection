/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <glm/glm.hpp>
#include "Game.h"
#include "Timer.h"
#include <ctime>
#include <GL\glut.h>

int refreshMillis = 16;      

Game* game;
LowResTimer timer;
double oldTime = 0;


void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0); 
}

void display() {
	game->Render();
}


void reshape(GLsizei width, GLsizei height)
{
	game->ReshapeWindow(width, height);
}

void update(int value)
{
	game->Update(timer.getTime() - oldTime);
	glutPostRedisplay();						
	glutTimerFunc(refreshMillis, update, 0);	
	oldTime = timer.getTime();
}

void GLUTRenderer()
{
	glutDisplayFunc(display);		
	glutReshapeFunc(reshape);		
	glutTimerFunc(0, update, 0);	
	initGL();						
	glutMainLoop();					
}

void onMouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{

		int numb = 0;
		for (int i = 0; i < 1; i++)
		{
			numb = 1 + (rand() % 3);
			cout << numb << endl;
			if (numb == 1)
			{				
				game->SpawnCircle();				
			}
			if (numb == 2)
			{				
				game->SpawnSquare();				
			}
			if (numb == 3)
			{
				game->SpawnOBB();				
			}
		}
		
	}
}

void processKeys(unsigned char key, int x, int y) 
{

	if (key == 32)
	{
		game->RandomSpawn();
	}
}

int main(int argc, char** argv) {
	srand(time(0));
	glutInit(&argc, argv);            
	game = new Game();
	game->Load();
	timer.startTimer();
	glutMouseFunc(onMouseButton);
	glutKeyboardFunc(processKeys);
	GLUTRenderer();
	delete game;
	return 0;
}