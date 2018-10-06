#include "Point.h"

Point::Point() {}

Point::~Point() {}

void Point::initialize(string stbAttributes)
{
	//Position 50 50 Color 0 0 225

	std::stringstream attributes;
	attributes.str(stbAttributes);
	string text;
	short B, G, R;

	attributes >> text >> xCoord >> yCoord >> text >> R >> G >> B;
	color.Blue = B;
	color.Green = G;
	color.Red = R;
}

void Point::draw(Picture &picture)
{
	picture.SetPixelColor(xCoord, yCoord, color);
}

void Point::drawWithShadow(Picture &picture)
{
	RGBTriple shadowColor(96, 96, 96);

	picture.SetPixelColor(xCoord - 10, yCoord - 20, shadowColor);
	picture.SetPixelColor(xCoord, yCoord, color); 
}
