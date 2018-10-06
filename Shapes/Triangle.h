#pragma once
#include "Shape.h"
#include <string>
#include <sstream>

class Triangle :
	public Shape
{
public:
	Triangle();
	virtual ~Triangle();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
//	RGBTriple color;
//	Coordinate startCoord;

private:
	int width;
	int height;
};

