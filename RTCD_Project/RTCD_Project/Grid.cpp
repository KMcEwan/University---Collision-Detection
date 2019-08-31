/*

Name: Kirsty McEwan

Student ID: B00188061

I declare that the following code was produced by (Kirsty McEwan, Lauren McNally, Andrew Clark) as a group assignment for the RTCD module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Grid.h"
#include <algorithm>
#include <iostream>
#include "Circle.h"

Grid::Grid(int width, int height, int cellSize) : width(width), height(height), cellSize(cellSize)
{
	columns = width / cellSize;
	rows = height / cellSize;
}

Grid::~Grid()
{
	for (auto it = objBuckets.begin(); it != objBuckets.end(); it++)
	{
		it->second.clear();  // Deletes the Entity pointer
	}
	objBuckets.clear();
}

Indices Grid::computeCellIndices(vec2 position)
{
	int X = position.x / columns;  //divide the x coordinate of the object position by the number of columns of the grid
	int Y = position.y / rows;	   //divide the y coordinate of the position of the object by the number of rows of the grid
	return Indices(X, Y);
}

void Grid::registerObject(Object* obj)
{
	Indices cellInd = computeCellIndices(obj->getPosition());
	objBuckets[cellInd].push_back(obj);
}

void Grid::clearGrid()
{
	objBuckets.clear();
}

vector<Object*> Grid::getNeighbours(Object* obj)
{
	vector<Object*> neighbours;

	Indices cellInd = computeCellIndices(obj->getPosition());
	neighbours.insert(neighbours.end(), objBuckets[cellInd].begin(), objBuckets[cellInd].end());		

	Indices E(cellInd.first + 1, cellInd.second);
	if (objBuckets.count(E)>0)
		neighbours.insert(neighbours.end(), objBuckets[E].begin(), objBuckets[E].end());

	Indices SE(cellInd.first + 1, cellInd.second + 1);
	if (objBuckets.count(SE)>0)
		neighbours.insert(neighbours.end(), objBuckets[SE].begin(), objBuckets[SE].end());

	Indices S(cellInd.first, cellInd.second + 1);
	if (objBuckets.count(S)>0)
		neighbours.insert(neighbours.end(), objBuckets[S].begin(), objBuckets[S].end());

	return neighbours;
}

void Grid::print()
{
	for each (pair<Indices, vector<Object*>> pair in objBuckets)
	{
		cout << pair.first.first << ", " << pair.first.second << endl;
	}
}