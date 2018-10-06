#include "Circle.h"

Circle::Circle() {}

Circle::~Circle() {}

void Circle::initialize(string stbAttributes)
{
	//Start 200 200 Radius 54 Color 0 102 0
	std::stringstream attributes;
	attributes.str(stbAttributes);
	string text;
	short R, G, B;

	attributes >> text >> center.x >> center.y >> text >> radius >> text >> R >> G >> B;
	color.Red = R;
	color.Green = G;
	color.Blue = B;
}

void Circle::draw(Picture &picture)
{
	int x = radius;
	int y = 0;
	int i = 0;

	while (x >= y)
	{
		picture.SetPixelColor(center.x + x, center.y + y, color);
		picture.SetPixelColor(center.x + y, center.y + x, color);
		picture.SetPixelColor(center.x - y, center.y + x, color);
		picture.SetPixelColor(center.x - x, center.y + y, color);
		picture.SetPixelColor(center.x - x, center.y - y, color);
		picture.SetPixelColor(center.x - y, center.y - x, color);
		picture.SetPixelColor(center.x + y, center.y - x, color);
		picture.SetPixelColor(center.x + x, center.y - y, color);

		if (i <= 0)
		{
			y = y + 1;
			i = i + (y * 2 + 1);
		}
		else
		{
			x = x - 1;
			i = i - (x * 2 + 1);
		}
	}
}

void Circle::drawWithShadow(Picture &picture)
{
	RGBTriple shadowColor(96, 96, 96);

	int x = radius;
	int y = 0;
	int i = 0;

	while (x >= y)
	{
		picture.SetPixelColor(center.x + x - 10, center.y + y - 20, shadowColor);
		picture.SetPixelColor(center.x + y - 10, center.y + x - 20, shadowColor);
		picture.SetPixelColor(center.x - y - 10, center.y + x - 20, shadowColor);
		picture.SetPixelColor(center.x - x - 10, center.y + y - 20, shadowColor);
		picture.SetPixelColor(center.x - x - 10, center.y - y - 20, shadowColor);
		picture.SetPixelColor(center.x - y - 10, center.y - x - 20, shadowColor);
		picture.SetPixelColor(center.x + y - 10, center.y - x - 20, shadowColor);
		picture.SetPixelColor(center.x + x - 10, center.y - y - 20, shadowColor);

		if (i <= 0)
		{
			y = y + 1;
			i = i + (y * 2 + 1);
		}
		else
		{
			x = x - 1;
			i = i - (x * 2 + 1);
		}
	}
	this->draw(picture);
}