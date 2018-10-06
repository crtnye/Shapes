#include "Star.h"


Star::Star() {}

Star::~Star() {}

void Star::initialize(string stbAttributes)
{
	// Start 200 200 Width 40 Color 255 128 0

	std::stringstream attributes;
	attributes.str(stbAttributes);
	string text;
	short R, G, B;

	attributes >> text >> startCoord.x >> startCoord.y >> text >> width >> text >> R >> G >> B;
	color.Red = R;
	color.Green = G;
	color.Blue = B;
}

void Star::draw(Picture &picture)
{
	picture.AddLine(startCoord.x, startCoord.y, startCoord.x + width, startCoord.y, color);
	picture.AddLine(startCoord.x + width, startCoord.y, startCoord.x + (width * .2), startCoord.y - (width * .7), color);
	picture.AddLine(startCoord.x + (width * .2), startCoord.y - (width * .7), startCoord.x + (width * .5), 
		startCoord.y + (width * .4), color);
	picture.AddLine(startCoord.x + (width * .5), startCoord.y + (width * .4), startCoord.x + (width * .8),
		startCoord.y - (width * .7), color);
	picture.AddLine(startCoord.x + (width * .8), startCoord.y - (width * .7), startCoord.x, startCoord.y, color);
}

void Star::drawWithShadow(Picture &picture)
{
	RGBTriple shadowColor(96, 96, 96);

	picture.AddLine(startCoord.x - 10, startCoord.y - 20, startCoord.x + width - 10, startCoord.y - 20, shadowColor);
	picture.AddLine(startCoord.x + width - 10, startCoord.y - 20, startCoord.x + (width * .2) - 10, 
		startCoord.y - (width * .7) - 20, shadowColor);
	picture.AddLine(startCoord.x + (width * .2) - 10, startCoord.y - (width * .7) - 20, startCoord.x + (width * .5) - 10,
		startCoord.y + (width * .4) - 20, shadowColor);
	picture.AddLine(startCoord.x + (width * .5) - 10, startCoord.y + (width * .4) - 20, startCoord.x + (width * .8) - 10,
		startCoord.y - (width * .7) - 20, shadowColor);
	picture.AddLine(startCoord.x + (width * .8) - 10, startCoord.y - (width * .7) - 20, startCoord.x - 10, 
		startCoord.y - 20, shadowColor);

	this->draw(picture);
}
