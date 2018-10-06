#pragma once
#include "Shape.h"
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

class Polygon :
	public Shape
{
public:
	Polygon();
	virtual ~Polygon();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
//	RGBTriple color;
//	Coordinate startCoord;

private:
	queue<int> xCoords;
	queue<int> yCoords;

	void parseCoordinates(string &stbAttributes);

};

