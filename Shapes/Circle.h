#pragma once
#include "Shape.h"
#include <string>
#include <sstream>

class Circle :
	public Shape
{
public:
	Circle();
	virtual ~Circle();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
//	RGBTriple color;
//	Coordinate startCoord;

private:
	int radius;
	Coordinate center;
};

