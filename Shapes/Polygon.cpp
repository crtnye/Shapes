#include "Polygon.h"

Polygon::Polygon() {}

Polygon::~Polygon() {}

void Polygon::initialize(string stbAttributes)
{

	parseCoordinates(stbAttributes);

	std::stringstream attributes;
	attributes.str(stbAttributes);
	string text;
	short R, G, B;

	attributes >> text >> startCoord.x >> startCoord.y >> text;
	getline(attributes, text, ')');
	attributes >> text >> R >> G >> B;

	color.Red = R;
	color.Green = G;
	color.Blue = B;
}

void Polygon::parseCoordinates(string &stbAttributes)
{
	//Start 30 75 Points (35 60 45 80 20 80) Color 0 153 153

	int begin = stbAttributes.find_first_of("(");
	int end = stbAttributes.find_first_of(")");
	int size = end - begin - 1;

	string coordinatesStr = stbAttributes.substr(begin + 1, size); //35 60 45 80 20 80

	std::stringstream coordinates;
	coordinates.str(coordinatesStr);
	int x, y;

	while (coordinates >> x >> y)
	{
		xCoords.push(x);
		yCoords.push(y);
	}
}

void Polygon::draw(Picture &picture)
{
	queue<int> xCoordsLocal = xCoords;
	queue<int> yCoordsLocal = yCoords;

	int currentX = startCoord.x;
	int currentY = startCoord.y;
	int nextX, nextY;

	while (!xCoordsLocal.empty() && !yCoordsLocal.empty())
	{
		nextX = xCoordsLocal.front();
		nextY = yCoordsLocal.front();
		xCoordsLocal.pop();
		yCoordsLocal.pop();

		picture.AddLine(currentX, currentY, nextX, nextY, color);
		currentX = nextX;
		currentY = nextY;
	}
	picture.AddLine(currentX, currentY, startCoord.x, startCoord.y, color);
}

void Polygon::drawWithShadow(Picture &picture)
{
	queue<int> xCoordsLocal = xCoords;
	queue<int> yCoordsLocal = yCoords;

	RGBTriple shadowColor(96, 96, 96);

	int currentX = startCoord.x;
	int currentY = startCoord.y;
	int nextX, nextY;

	while (!xCoordsLocal.empty() && !yCoordsLocal.empty())
	{
		nextX = xCoordsLocal.front();
		nextY = yCoordsLocal.front();
		xCoordsLocal.pop();
		yCoordsLocal.pop();

		picture.AddLine(currentX - 10, currentY - 20, nextX - 10, nextY - 20, shadowColor);
		currentX = nextX;
		currentY = nextY;
	}
	picture.AddLine(currentX - 10, currentY - 20, startCoord.x - 10, startCoord.y - 20, shadowColor);

	this->draw(picture);
}