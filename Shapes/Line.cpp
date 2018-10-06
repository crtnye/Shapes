#include "Line.h"

Line::Line(){}

Line::~Line(){}

void Line::initialize(string stbAttributes)
{
	//Start 100 80 End 300 150 Color 0 225 0

	std::stringstream attributes;
	attributes.str(stbAttributes);
	string text;
	short R, G, B;

	attributes >> text >> startCoord.x >> startCoord.y >> text >> endCoord.x >> endCoord.y 
		>> text >> R >> G >> B;
	color.Red = R;
	color.Green = G;
	color.Blue = B;
}

void Line::draw(Picture &picture)
{
	picture.AddLine(startCoord.x, startCoord.y, endCoord.x, endCoord.y, color);
}

void Line::drawWithShadow(Picture &picture)
{
	RGBTriple shadowColor(96, 96, 96);
	picture.AddLine(startCoord.x - 10, startCoord.y - 20, endCoord.x - 10, endCoord.y - 20, shadowColor);
	this->draw(picture);
}
