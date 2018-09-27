#pragma once
#include "RGBTriple.h"
#include "Coordinate.h"
#include <string>

using std::string;

class Shape
{
public:
	Shape();
	~Shape();

	void initialize(string stbAttributes); 
	void draw();
	void drawShadow();

private:
	RGBTriple color;
	Coordinate startCoord;



};

