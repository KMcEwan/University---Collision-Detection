/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include <vector>
#include <glm\glm.hpp>
#include "Game.h"
#include <iostream>

using namespace std;
using namespace glm;

void Game::Load()
{
	window_width = 640;
	window_height = 480;
	window = new GameWindow("Collision Tests", window_width, window_height, 50, 50);
	grid = new Grid(window->getWidth(), window->getHeight(), 1);

	vec2 point = vec2(window_width / 2, window_height / 2);
	vec2 dir = vec2(100, 0);

	Line* line1 = new Line(point, dir);
	gameObjects.push_back(line1);
	grid->registerObject(line1);

	dir = vec2(0, 100);
	Line* line2 = new Line(point, dir);
	gameObjects.push_back(line2);
	grid->registerObject(line2);

	point = vec2(1, 10);
	BorderLine* borderLine1 = new BorderLine(point, dir);
	borderLine1->setColor(0, 1, 1);
	gameObjects.push_back(borderLine1);

	point = vec2(639, 10);
	BorderLine* borderLine2 = new BorderLine(point, dir);
	borderLine2->setColor(0, 1, 1);
	gameObjects.push_back(borderLine2);

	dir = vec2(100, 0);
	point = vec2(0, 1);
	BorderLine* borderLine3 = new BorderLine(point, dir);
	borderLine3->setColor(0, 1, 1);
	gameObjects.push_back(borderLine3);

	point = vec2(0, 479);
	BorderLine* borderLine4 = new BorderLine(point, dir);
	borderLine4->setColor(0, 1, 1);
	gameObjects.push_back(borderLine4);
}

void Game::SpawnCircle()
{

	int SpawnOfX;
	int SpawnOfY;
	int VelOfX;
	int VelOfY;
	float size = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 15));
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	SpawnOfX = rand() % 640;
	SpawnOfY = rand() % 480;
	VelOfX = rand() % 100 + (-50);
	VelOfY = rand() % 100 + (-50);

	Circle* yellowBall = new  Circle(size, vec2(SpawnOfX, SpawnOfY), vec2(VelOfX, VelOfY), vec2(0, 0));
	yellowBall->setColor(r, g, b);
	gameObjects.push_back(yellowBall);
	grid->registerObject(yellowBall);
}

void Game::SpawnSquare()
{
	int SpawnOfX;
	int SpawnOfY;
	int VelOfX;
	int VelOfY;
	float size = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 15));
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	SpawnOfX = rand() % 600;
	SpawnOfY = rand() % 480;
	VelOfX = rand() % 100 + (-50);
	VelOfY = rand() % 100 + (-50);

	Square* magentaSquare = new Square(vec2(size, size), vec2(SpawnOfX, SpawnOfY), vec2(VelOfX, VelOfY), vec2(0, 0));
	magentaSquare->setColor(r, g, b);
	gameObjects.push_back(magentaSquare);
	grid->registerObject(magentaSquare);
}

void Game::SpawnOBB()
{
	int SpawnOfX;
	int SpawnOfY;
	int VelOfX;
	int VelOfY;
	int DirOfX;
	int DirOfY;
	int AccOfX;
	int AccOfY;
	float size = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 15));
	float size1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 15));
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	SpawnOfX = rand() % 600;
	SpawnOfY = rand() % 480;
	DirOfX = rand() % 50;
	DirOfY = rand() % 50;
	VelOfX = rand() % 100 + (-50);
	VelOfY = rand() % 100 + (-50);
	AccOfX = rand() % 5 + (-2);
	AccOfY = rand() % 5 + (-2);
	
	OBB* obb = new OBB(vec2(SpawnOfX, SpawnOfY), vec2(DirOfX, DirOfY), vec2(size, size1), vec2(VelOfX, VelOfY), vec2(AccOfX, AccOfY));
	gameObjects.push_back(obb);
	grid->registerObject(obb);
	obb->setColor(r, g, b);

}

void Game::RandomSpawn()
{
	for (int i = 0; i < 30; i++)
	{
		SpawnCircle();
		SpawnOBB();
		SpawnSquare();
	}
}


//Brute force approach
//void Game::CheckCollisions()
//{
//	for (vector<Object*>::iterator it = gameObjects.begin(); it < gameObjects.end() - 1; it++) // This loop usses an iterator (google c++ iterator) to go through all game entites objects
//	{
//		Circle* circle = dynamic_cast<Circle*> (*it); // As the iterator is of generic type Entity we need to convert it to a type we can use, Ball. Dynamic cast performs the conversion only if the entity is actually a Ball otherwise it gives back a null pointer
//		if (circle != nullptr) // we check if the conversion was successful
//		{
//			for (vector<Object*>::iterator it1 = it + 1; it1 < gameObjects.end(); it1++) // and we iterate on the remaining elements in the container
//			{
//
//				Circle* circle2 = dynamic_cast<Circle*> (*it1); // we convert the remaining element
//				if (circle2 != nullptr) // check if the conversion happended
//				{
//					// Collision detection test goes here
//					if (CircleCircleCollision(*circle, *circle2))
//					{
//						circle->setColor(1.0f, 0.0f, 0.0f);
//						circle2->setColor(1.0f, 0.0f, 0.0f);
//					}
//				}
//
//				Line* line = dynamic_cast<Line*> (*it1); // we convert the remaining element
//				if (line != nullptr) // check if the conversion happended
//				{
//					if (LineCircleCollision(*line, *circle))
//					{
//						cout << "Line Ball collsion" << endl;
//						circle->setColor(1.0f, 0.75f, 0.5f);
//					}
//				}
//
//
//			}
//		}
//
//		Line* line = dynamic_cast<Line*> (*it); // we convert the remaining element
//		if (line != nullptr) // check if the conversion happended
//		{
//			for (vector<Object*>::iterator it1 = it + 1; it1 < gameObjects.end(); it1++) // and we iterate on the remaining elements in the container
//			{
//				Circle* circle2 = dynamic_cast<Circle*> (*it1); // we convert the remaining element
//				if (circle2 != nullptr) // check if the conversion happended
//				{
//					//cout << "line != null" << endl;
//					// Collision detection test goes here
//					if (LineCircleCollision(*line, *circle2))
//					{
//						cout << "Line Ball collsion" << endl;
//						circle2->setColor(1.0f, 0.75f, 0.5f);
//					}
//				}
//			}
//		}
//
//		BorderLine* bline = dynamic_cast<BorderLine*> (*it); // we convert the remaining element
//		if (bline != nullptr) // check if the conversion happended
//		{
//			for (vector<Object*>::iterator it1 = it + 1; it1 < gameObjects.end(); it1++) // and we iterate on the remaining elements in the container
//			{
//				Circle* circle2 = dynamic_cast<Circle*> (*it1); // we convert the remaining element
//				if (circle2 != nullptr) // check if the conversion happended
//				{
//					//cout << "line != null" << endl;
//					// Collision detection test goes here
//					if (BorderLineCircleCollision(*bline, *circle2))
//					{
//						cout << "BorderLine Ball collsion" << endl;
//						circle2->setColor(0, 1, 1);
//						if (bline->getDirection().x == 0)
//						{
//							circle2->InvertVelocityX();
//						}
//						else if (bline->getDirection().y == 0)
//						{
//							circle2->InvertVelocityY();
//						}
//					}
//				}
//			}
//		}
//	}
//
//}

//Using a grid
void Game::CheckCollisions()
{
	for (vector<Object*>::iterator it = gameObjects.begin(); it < gameObjects.end() - 1; it++) 
	{
		Circle* circle = dynamic_cast<Circle*> (*it);
		if (circle != nullptr)
		{
			
			vector<Object*> objs = grid->getNeighbours(circle);
			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1) 
				{
					Circle* circle2 = dynamic_cast<Circle*> (*it1);
					OBB* obb = dynamic_cast<OBB*> (*it1);
					Square* square = dynamic_cast<Square*> (*it1);
					if (circle2 != nullptr)
					{
						if (CircleCircleCollision(*circle, *circle2))
						{
							CollisionReaction(circle, circle2);
						}
					}
					if (obb != nullptr)
					{
						if (OBBCircleCollision(*obb, *circle))
						{
							CollisionReaction(obb, circle);
						}
					}
					if (square != nullptr)
					{
						if (SquareCircleCollision(*square, *circle))
						{
							CollisionReaction(square, circle);
						}
					}

				}
			}
		}
		BorderLine* bline = dynamic_cast<BorderLine*> (*it); 
		if (bline != nullptr) 
		{
			vector<Object*> objs = grid->getNeighbours(bline);
			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1) 
				{
					Circle* circle = dynamic_cast<Circle*> (*it1);
					OBB* obb = dynamic_cast<OBB*> (*it1);
					Square* square = dynamic_cast<Square*> (*it1);
					if (circle != nullptr)
					{
						if (BorderLineCircleCollision(*bline, *circle))
						{
							CollisionReaction(bline, circle);
						}
					}
					if (obb != nullptr)
					{						
						if (BorderLineOBBCollision(*bline, *obb))
						{							
							CollisionReaction(bline, obb);
						}
					}
					if (square != nullptr)
					{						
						if (BorderLineCircleCollision(*bline, *square))
						{		
								CollisionReaction(bline, square);
						}
					}
				}
			}

		}
		Square* square = dynamic_cast<Square*> (*it); 
		if (square != nullptr) 
		{
			vector<Object*> objs = grid->getNeighbours(square);
			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1) 
				{
					Square* square1 = dynamic_cast<Square*> (*it1);
					OBB* obb = dynamic_cast<OBB*> (*it1);
					if (square1 != nullptr)
					{
						if (SquareSquareCollision(*square, *square1))
						{							
							CollisionReaction(square, square1);
						}
					}
					if (obb != nullptr)
					{
						if (SquareOBBCollision(*square, *obb))
						{							
							CollisionReaction(square, obb);
						}
					}
				}
			}
		}
		OBB* obb = dynamic_cast<OBB*> (*it);
		if (obb != nullptr)
		{
			vector<Object*> objs = grid->getNeighbours(obb);
			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1) 
				{
					OBB* obb1 = dynamic_cast<OBB*> (*it1);
					if (obb1 != nullptr)
					{
						if (OBBOBBCollision(*obb, *obb1))
						{
							CollisionReaction(obb, obb1);
						}
					}
				}
			}
		}
		Line* line = dynamic_cast<Line*> (*it);
		if (line != nullptr)
		{
			vector<Object*> objs = grid->getNeighbours(line);
			for (auto it1 = objs.begin(); it1 != objs.end(); it1++)
			{
				if (*it != *it1)
				{
					Circle* c1 = dynamic_cast<Circle*> (*it1);
					Square* square = dynamic_cast<Square*> (*it1);
					OBB* obb = dynamic_cast<OBB*> (*it1);
					if (c1 != nullptr)
					{
						if (CircleLineCollision(*line, *c1))
						{
							CollisionReaction(c1, line);
						}
					}
					if (square != nullptr)
					{
						if (SquareLineCollision(*line, *square))
						{
							CollisionReaction(square, line);
						}
					}
					if (obb != nullptr)
					{
						if (OBBLineCollision(*line, *obb))
						{
							CollisionReaction(obb, line);
						}
					}
				}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Circle collisions
void Game::CollisionReaction(Circle * circle, Circle * circle2)											//GRID : Circle Circle Collision				
{
	vec2 n = normalize(circle2->getPosition() - circle->getPosition());
	float inters = abs(circle->getRadius() - distance(circle2->getPosition(), circle->getPosition()));

	circle->move(-0.5f * inters * n);
	circle2->move(0.5f * inters * n);

	circle->changeDir(n, circle2->getVelocity());
	circle2->changeDir(n, circle->getVelocity());

	circle->setColor(1.0f, 0.0f, 0.0f);
	circle2->setColor(1.0f, 0.0f, 0.0f);
}

void Game::CollisionReaction(OBB* obb, Circle* circle)													//GRID : Circle OOB Collision	
{
	vec2 n = normalize(circle->getPosition() - obb->getPosition());
	float inters = abs(circle->getRadius() - distance(obb->getPosition(), obb->getPosition()));

	obb->move(-0.1f * inters * n);
	circle->move(0.1f * inters * n);

	obb->changeDir(n, obb->getVelocity());
	circle->changeDir(n, circle->getVelocity());

	obb->setColor(0.0f, 1.0f, 0.0f);
	circle->setColor(0.0f, 1.0f, 0.0f);
}

void Game::CollisionReaction(Square* square, Circle* circle)											//GRID : Circle Square Collision	
{
	vec2 n = normalize(circle->getPosition() - square->getPosition());
	float inters = abs(circle->getRadius() - distance(square->getPosition(), square->getPosition()));

	square->move(-0.1f * inters * n);
	circle->move(0.1f * inters * n);

	square->changeDir(n, square->getVelocity());
	circle->changeDir(n, circle->getVelocity());

	square->setColor(0.0f, 0.0f, 1.0f);
	circle->setColor(0.0f, 0.0f, 1.0f);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Circle collisions end

void Game::CollisionReaction(BorderLine * borderLine, Circle * circle)									//GRID : Borderline Circle Collision	
{
	if (borderLine->getDirection().x == 0)
	{
		circle->InvertVelocityX();
	}
	else if (borderLine->getDirection().y == 0)
	{
		circle->InvertVelocityY();
	}
}

void Game::CollisionReaction(BorderLine * borderLine, Square * square)									//GRID : Borderline square Collision	
{
	if (borderLine->getDirection().x == 0)
	{
		square->InvertVelocityX();
	}
	else if (borderLine->getDirection().y == 0)
	{
		square->InvertVelocityY();
	}
}

void Game::CollisionReaction(BorderLine * borderLine, OBB * obb)										//GRID : Borderline OBB Collision	
{
	if (borderLine->getDirection().x == 0)
	{
		obb->InvertVelocityX();
	}
	else if (borderLine->getDirection().y == 0)
	{
		obb->InvertVelocityY();
	}

	obb->setColor(1.0f, 0.0f, 0.0f);	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Square collisions
void Game::CollisionReaction(Square * square, Square * square1)													
{
	square->setColor(0.0f, 1.0f, 1.0f);																									
	square1->setColor(0.0f, 1.0f, 1.0f);																					
}

void Game::CollisionReaction(Square* square, OBB* obb)
{
	obb->setColor(1.0f, 1.0f, 1.0f);
	square->setColor(1.0f, 1.0f, 1.0f);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// OBB collisions 

void Game::CollisionReaction(OBB * obb, OBB* obb1)
{
	obb->setColor(0.0f, 0.5f, 1.0f);
	obb1->setColor(0.0f, 0.5f, 1.0f);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Middle Line collision

void Game::CollisionReaction(Circle* c1, Line* line)
{
	c1->setColor(0.2f, 0.2f, 0.2f);
}

void Game::CollisionReaction(Square* square, Line* line)
{
	square->setColor(0.2f, 0.2f, 0.2f);
}

void Game::CollisionReaction(OBB* obb, Line* line)
{
	obb->setColor(0.2f, 0.2f, 0.2f);
}


void Game::Update(float dt)
{
	grid->clearGrid();
	for (vector<Object*>::iterator it = gameObjects.begin(); it < gameObjects.end(); it++)
	{
		(*it)->update(dt);
		
		grid->registerObject(*it);
	}
	CheckCollisions();
}

void Game::ReshapeWindow(int width, int height)
{
	window->Reshape(width, height);
}

void Game::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);		
	for (vector<Object*>::iterator it = gameObjects.begin(); it < gameObjects.end(); it++)
	{
		(*it)->draw(window->getWidth(), window->getHeight());
	}

	glutSwapBuffers();				
}

void Game::Inputs()
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Borderline collisions
bool Game::BorderLineCircleCollision(BorderLine& borderLine, Circle& ball)			
{
	vec2 orthDir(-borderLine.getDirection().y, borderLine.getDirection().x);
	vec2 r = borderLine.getPoint() - ball.getPosition();

	float dist = abs(dot(orthDir, r)) / length(orthDir);

	if (dist <= ball.getRadius())
		return true;

	return false;
}

bool Game::BorderLineOBBCollision(BorderLine& borderLine, OBB& obb)			
{
	vec2 orthDir(-borderLine.getDirection().y, borderLine.getDirection().x);
	vec2 r = borderLine.getPoint() - obb.getPosition();

	float dist = abs(dot(orthDir, r)) / length(orthDir);

	if (dist <= obb.getHalfExtents().r)
		return true;

	return false;																					 																									
}

bool Game::BorderLineCircleCollision(BorderLine& borderLine, Square& square)			
{	
	vec2 orthDir(-borderLine.getDirection().y, borderLine.getDirection().x);
	vec2 r = borderLine.getPoint() - square.getPosition();

	float dist = abs(dot(orthDir, r)) / length(orthDir);

	if (dist <= square.getRadii().x)
		return true;

	return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Borderline collisions end

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Circle collisions
bool Game::CircleCircleCollision(Circle& c1, Circle& c2)							
{
	float dist = distance(c1.getPosition(), c2.getPosition());

	if (dist <= c1.getRadius() + c2.getRadius())
		return true;

	return false;
}

bool Game::OBBCircleCollision(OBB& obb1, Circle& c1)									
{
	vec2 closestPoint;
	ClosestPtPointOBB(c1.getPosition(), obb1, closestPoint);
	float dist = distance(c1.getPosition(), closestPoint);
	if (dist <= c1.getRadius())
		return true;
	return false;
}

bool Game::SquareCircleCollision(Square& square, Circle& c1)
{
	vec2 closestPoint;
	ClosestPtPointAABB(c1.getPosition(), square, closestPoint);
	if (distance(c1.getPosition(), closestPoint) <= c1.getRadius())
		return true;
	return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Square collisions 
bool Game::SquareSquareCollision(Square& square, Square& square1)
{
	if (abs(square.getPosition().x - square1.getPosition().x) > (square.getRadii().x + square1.getRadii().x)) return false;
	if (abs(square.getPosition().y - square1.getPosition().y) > (square.getRadii().y + square1.getRadii().y)) return false;
	return true;
}

bool Game::SquareOBBCollision(Square& square, OBB& obb)
{
	vector<vec2> directions{ obb.getDirection(),obb.getOrtDirection(), square.getDirection(), square.getOrtDirection() };
	vec2 T = square.getPosition() - obb.getPosition();
	for (auto dirptr = directions.begin(); dirptr < directions.end(); dirptr++)
		if (abs(dot(T, *dirptr)) > abs(obb.getHalfExtents().x * dot(obb.getDirection(), *dirptr))
			+ abs(obb.getHalfExtents().y * dot(obb.getOrtDirection(), *dirptr))
			+ abs(square.getHalfExtents().x * dot(square.getDirection(), *dirptr))
			+ abs(square.getHalfExtents().y * dot(square.getOrtDirection(), *dirptr)))
			return false;
	return true;																	
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// OBB collision
bool Game::OBBOBBCollision(OBB& obb, OBB& obb1) 
{
	vector<vec2> directions{ obb.getDirection(),obb.getOrtDirection(), obb1.getOrtDirection(), obb1.getOrtDirection() };
	vec2 T = obb1.getPosition() - obb.getPosition();
	for (auto dirptr = directions.begin(); dirptr < directions.end(); dirptr++)
		if (abs(dot(T, *dirptr)) > abs(obb.getHalfExtents().x * dot(obb.getDirection(), *dirptr))
			+ abs(obb.getHalfExtents().y * dot(obb.getOrtDirection(), *dirptr))
			+ abs(obb1.getHalfExtents().x * dot(obb1.getDirection(), *dirptr))
			+ abs(obb1.getHalfExtents().y * dot(obb1.getOrtDirection(), *dirptr)))
			return false;
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Middle Line collision

bool Game::CircleLineCollision(Line& line, Circle& c1)
{
	vec2 orthDir(-line.getDirection().y, line.getDirection().x);
	vec2 r = line.getPoint() - c1.getPosition();

	float dist = abs(dot(orthDir, r)) / length(orthDir);

	if (dist <= c1.getRadius())
		return true;

	return false;
}

bool Game::SquareLineCollision(Line& line, Square& square)
{
	vec2 orthDir(-line.getDirection().y, line.getDirection().x);
	vec2 r = line.getPoint() - square.getPosition();

	float dist = abs(dot(orthDir, r)) / length(orthDir);

	if (dist <= square.getRadii().x)
		return true;

	return false;
}

bool Game::OBBLineCollision(Line& line, OBB& obb)
{
	vec2 orthDir(-line.getDirection().y, line.getDirection().x);
	vec2 r = line.getPoint() - obb.getPosition();

	float dist = abs(dot(orthDir, r)) / length(orthDir);

	if (dist <= obb.getHalfExtents().r)
		return true;

	return false;
}

void Game::ClosestPtPointOBB(vec2& P, OBB& b, vec2& R)
{
	vector<vec2> dirs{ b.getDirection(), b.getOrtDirection() }; 
	vec2 d = P - b.getPosition();
	R = b.getPosition();					
	for (int i = 0; i < 2; i++)				
	{
		float v = dot(d, dirs[i]);
		if (v > b.getHalfExtents()[i])
			v = b.getHalfExtents()[i];

		if (v < -b.getHalfExtents()[i])
			v = -b.getHalfExtents()[i];

		R += v * dirs[i];					
	}
}

void Game::ClosestPtPointAABB(vec2& P, Square& b, vec2& q)						
{
	vec2 min(b.getPosition() - b.getRadii());
	vec2 max(b.getPosition() + b.getRadii());
	for (int i = 0; i < 2; i++)
	{
		float v = P[i];
		if (v < min[i]) v = min[i];
		if (v > max[i]) v = max[i];
		q[i] = v;
	}
}


//bool Game::CircleAABBCollision(Circle & c1, Square & b)							//Brute force
//{
//	vec2 P;
//	ClosestPtPointAABB(c1.getPosition(), b, P);
//	float dist = distance(c1.getPosition(), P);
//	if (dist <= c1.getRadius())
//	{
//		return true;
//	}
//}


//bool Game::AABBAABBCollision(Square& A, Square& B)								////Brute force	
//{
//	if (abs(A.getPosition().x - B.getPosition().x) > (A.getRadii().x + B.getRadii().x)) return false;
//	if (abs(A.getPosition().y - B.getPosition().y) > (A.getRadii().y + B.getRadii().y)) return false;
//
//	return true;
//}
//
//
//void Game::ClosestPtPointAABB(vec2& P, Square& b, vec2& q)						////Brute force
//{
//	vec2 min(b.getPosition() - b.getRadii());
//	vec2 max(b.getPosition() + b.getRadii());
//	for (int i = 0; i < 2; i++)
//	{
//		float v = P[i];
//		if (v < min[i]) v = min[i];
//		if (v > max[i]) v = max[i];
//		q[i] = v;
//	}
//}
//
////bool Game::LineCircleCollision(Line & line, Circle & circle)					////Brute force
//{
//	vec2 orthDir(-line.getDirection().y, line.getDirection().x);
//	vec2 r = line.getPoint() - circle.getPosition();
//
//	float dist = abs(dot(orthDir, r)) / length(orthDir);
//
//	if (dist <= circle.getRadius())
//		return true;
//
//	return false;
//}
