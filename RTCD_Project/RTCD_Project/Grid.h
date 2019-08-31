#pragma once
#pragma once
#include <glm\glm.hpp>
#include <map>
#include <vector>
#include "Object.h"

using namespace glm;
using namespace std;

typedef pair<int, int> Indices;

class Grid
{
private:
	int cellSize, width, height;
	int columns, rows;
	map<Indices, vector<Object*>> objBuckets;

	Indices computeCellIndices(vec2 position);

public:
	Grid(int width, int height, int cellSize);
	virtual ~Grid();
	void registerObject(Object* obj);
	vector<Object*> getNeighbours(Object* obj);
	void clearGrid();
	void print();
};
