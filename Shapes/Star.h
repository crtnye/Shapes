#pragma once
#include "Shape.h"
#include <string>
#include <sstream>

class Star :
	public Shape
{
public:
	Star();
	virtual ~Star();

	virtual void initialize(string stbAttributes);
	virtual void draw(Picture&);
	virtual void drawWithShadow(Picture&);

//protected:
//	RGBTriple color;
//	Coordinate startCoord;

private:
	int width;
};

