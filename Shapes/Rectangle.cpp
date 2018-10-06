#include "Rectangle.h"

Rectangle::Rectangle(){}

Rectangle::~Rectangle(){}

void Rectangle::initialize(string stbAttributes)
{
	std::stringstream attributes;
	attributes.str(stbAttributes);
	string text;
	short R, G, B;

	attributes >> text >> startCoord.x >> startCoord.y >> text >> width >> text >> height
		>> text >> R >> G >> B;
	color.Red = R;
	color.Green = G;
	color.Blue = B;
}

void Rectangle::draw(Picture &picture)
{
	picture.AddLine(startCoord.x, startCoord.y, startCoord.x + width, startCoord.y, color);
	picture.AddLine(startCoord.x, startCoord.y, startCoord.x, startCoord.y + height, color);
	picture.AddLine(startCoord.x, startCoord.y + height, startCoord.x + width, startCoord.y + height, color);
	picture.AddLine(startCoord.x + width, startCoord.y + height, startCoord.x + width, startCoord.y, color);
}

void Rectangle::drawWithShadow(Picture &picture)
{
	RGBTriple shadowColor(96, 96, 96);

	picture.AddLine(startCoord.x - 10, startCoord.y - 20, startCoord.x + width - 10, startCoord.y - 20, shadowColor);
	picture.AddLine(startCoord.x - 10, startCoord.y - 20, startCoord.x - 10, startCoord.y + height - 20, shadowColor);
	picture.AddLine(startCoord.x - 10, startCoord.y + height - 20, startCoord.x + width - 10, startCoord.y + height - 20, 
		shadowColor);
	picture.AddLine(startCoord.x + width - 10, startCoord.y + height - 20, startCoord.x + width - 10, startCoord.y - 20, 
		shadowColor);

	this->draw(picture);
}
