#pragma once
#include "RGBTriple.h"
#include "Coordinate.h"
#include "Picture.h"
#include <string>

using std::string;

class Shape
{
public:
	Shape();
	virtual ~Shape();

	virtual void initialize(string stbAttributes) = 0; 
	virtual void draw(Picture&) = 0;
	virtual void drawWithShadow(Picture&) = 0;

protected:
	RGBTriple color;
	Coordinate startCoord;
};

