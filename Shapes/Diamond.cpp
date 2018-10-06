#include "Diamond.h"

Diamond::Diamond() {}

Diamond::~Diamond(){}

void Diamond::initialize(string stbAttributes)
{
	//Start 100 100 Width 15 Height 20 Color 102 255 255
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

void Diamond::draw(Picture &picture)
{
	picture.AddLine(startCoord.x, startCoord.y, startCoord.x + (width / 2), startCoord.y + (height / 2), color);
	picture.AddLine(startCoord.x + (width / 2), startCoord.y + (height / 2), startCoord.x + width, startCoord.y, color);
	picture.AddLine(startCoord.x + width, startCoord.y, startCoord.x + (width / 2), startCoord.y - (height / 2), color);
	picture.AddLine(startCoord.x + (width / 2), startCoord.y - (height / 2), startCoord.x, startCoord.y, color);
}

void Diamond::drawWithShadow(Picture &picture)
{
	RGBTriple shadowColor(96, 96, 96);

	picture.AddLine(startCoord.x - 10, startCoord.y - 20, startCoord.x + (width / 2) - 10, 
		startCoord.y + (height / 2) - 20, shadowColor);
	picture.AddLine(startCoord.x + (width / 2) - 10, startCoord.y + (height / 2) - 20, 
		startCoord.x + width - 10, startCoord.y - 20, shadowColor);
	picture.AddLine(startCoord.x + width - 10, startCoord.y - 20, startCoord.x + (width / 2) - 10, 
		startCoord.y - (height / 2) - 20, shadowColor);
	picture.AddLine(startCoord.x + (width / 2) - 10, startCoord.y - (height / 2) - 20, startCoord.x - 10, 
		startCoord.y - 20, shadowColor);

	this->draw(picture);
}

