#pragma once
#include <glm\glm.hpp>
#include <vector>
#include "Object.h"
#include "GameWindow.h"
#include "Circle.h"
#include "Square.h"
#include "Line.h"
#include "OBB.h"
#include "BorderLine.h"
#include "Grid.h"

using namespace std;

class Game
{
public:
	void Load();
	void Render();
	void Inputs();
	void Update(float dt);
	void ReshapeWindow(int weigth, int height);
	void SpawnCircle();
	void SpawnSquare();
	void SpawnOBB();
	void RandomSpawn();

	Game() {};
	virtual ~Game()
	{
		for (vector<Object*>::iterator it = gameObjects.begin(); it < gameObjects.end(); it++)
		{
			delete(*it);
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////// For brute force approach
	/*	bool LineCircleCollision(Line& line, Circle& ball);
		bool CircleAABBCollision(Circle& c1, Square& b);
		bool AABBAABBCollision(Square& A, Square& B);
		void ClosestPtPointAABB(vec2& P, Square& b, vec2& q);
		bool OOBOOBCollision2D(OBB& A, OBB& B);
		bool BorderLineCircleCollision(BorderLine& borderLine, Circle& circle);*/
		//////////////////////////////////////////////////////////////////////////////////////////// For brute force approach end


	//////////////////////////////////////////////////////////////////////////////////////////////////For Grid approach
		bool CircleCircleCollision(Circle& c1, Circle& c2);
		bool OBBCircleCollision(OBB& obb1, Circle& c1);
		bool SquareCircleCollision(Square& square, Circle& c1);
		bool SquareSquareCollision(Square& square, Square& square1);
		bool OBBOBBCollision(OBB& obb, OBB& obb1);
		bool SquareOBBCollision(Square& square, OBB& obb);
		bool CircleLineCollision(Line& line, Circle& c1);
		bool SquareLineCollision(Line& line, Square& square);
		bool OBBLineCollision(Line& line, OBB& obb);
		bool BorderLineCircleCollision(BorderLine& bline, Circle& c2);
		bool BorderLineOBBCollision(BorderLine& bline, OBB& obb);
		bool BorderLineCircleCollision(BorderLine& bline, Square& square);
		

	private:
		vector<Object*> gameObjects;
		GameWindow* window;
		/*void CheckCollisions();*/											//Brute force
		int window_width;
		int window_height;
		Grid* grid;
		void CheckCollisions();												//Needed for grid
		void CollisionReaction(Circle* circle, Circle* circle2);			//Needed for grid
		void CollisionReaction(BorderLine* borderLine, Circle* circle);		// Borderline - square collision
		void CollisionReaction(BorderLine* borderLine, OBB* obb);			// Borderline - square collision
		void CollisionReaction(BorderLine* borderLine, Square* square);		// Borderline - square collision
		void CollisionReaction(OBB* obb, Circle* circle);					// OBB - Circle collision
		void CollisionReaction(Square* square, Circle* circle);				// Square - Circle collision
		void CollisionReaction(Square* square, Square* square1);			// Square - square collision
		void CollisionReaction(Square* square, OBB* obb);					// Square - OBB collision
		void ClosestPtPointOBB(vec2& P, OBB& b, vec2& R);					// Closest point to OBB
		void ClosestPtPointAABB(vec2& P, Square& b, vec2& q);				// Cloest point to AABB
		void CollisionReaction(OBB* obb, OBB* obb1);						// OBB - OBB collsion
		void CollisionReaction(Circle* c1, Line* line);						// Middle - Circle collision
		void CollisionReaction(Square* square, Line* line);					// Middle - Square collision
		void CollisionReaction(OBB* obb, Line* line);						// Middle - OBB collision
};
