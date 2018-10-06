#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Diamond.h"
#include "Star.h"
#include "Polygon.h"
#include "Circle.h"

using std::ifstream;

void createShape(const string &shapeType, string& shapeAttributes, vector<Shape*> &shapes);
void createAllShapes(ifstream &instructions, vector<Shape*> &shapes);
void drawAllShapes(vector<Shape*> &shapes, const bool &shadow, Picture &myDrawing);
void getInstructionsFile(ifstream &instructions, string &fileName);
void deleteAllShapes(vector<Shape*> &shapes);


void main()
{
	ifstream instructions;
	string fileName;

	getInstructionsFile(instructions, fileName);

	if (instructions.is_open() && !instructions.eof())
	{
		vector<Shape*> shapes;
		bool shadow = false;

		string pictureAttributes;
		std::stringstream pictureAttributesStream;

		getline(instructions, pictureAttributes);
		pictureAttributesStream.str(pictureAttributes);

		string text;
		int width, height;
		short B, G, R;

		pictureAttributesStream >> text >> text >> width >> height >> text >> B >> G >> R >> text >> shadow;

		RGBTriple background(B, G, R);
		Picture myDrawing(width, height, background);

		createAllShapes(instructions, shapes);
		drawAllShapes(shapes, shadow, myDrawing);

		string bmpFileName = fileName.substr(0, fileName.length() - 3) + "bmp";
		myDrawing.WriteToFile(bmpFileName.c_str());

		deleteAllShapes(shapes);
	}
	instructions.close();
}

void createShape(const string &shapeType, string &shapeAttributes, vector<Shape*> &shapes)
{
	if (shapeType == "POINT")
	{
		Shape* newPoint = new Point;
		newPoint->initialize(shapeAttributes);
		shapes.push_back(newPoint);
	}
	else if (shapeType == "LINE")
	{
		Shape* newLine = new Line;
		newLine->initialize(shapeAttributes);
		shapes.push_back(newLine);
	}
	else if (shapeType == "TRIANGLE")
	{
		Shape* newTriangle = new Triangle;
		newTriangle->initialize(shapeAttributes);
		shapes.push_back(newTriangle);
	}
	else if (shapeType == "RECTANGLE")
	{
		Shape* newRectangle = new Rectangle;
		newRectangle->initialize(shapeAttributes);
		shapes.push_back(newRectangle);
	}
	else if (shapeType == "DIAMOND")
	{
		Shape* newDiamond = new Diamond;
		newDiamond->initialize(shapeAttributes);
		shapes.push_back(newDiamond);
	}
	else if (shapeType == "STAR")
	{
		Shape* newStar = new Star;
		newStar->initialize(shapeAttributes);
		shapes.push_back(newStar);
	}
	else if (shapeType == "POLYGON")
	{
		Shape* newPolygon = new Polygon;
		newPolygon->initialize(shapeAttributes);
		shapes.push_back(newPolygon);
	}
	else if (shapeType == "CIRCLE")
	{
		Shape* newCircle = new Circle;
		newCircle->initialize(shapeAttributes);
		shapes.push_back(newCircle);
	}
}

void drawAllShapes(vector<Shape*> &shapes, const bool &shadow, Picture &myDrawing)
{
	for (vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); ++it)
	{
		if (shadow == true)
		{
			(*it)->drawWithShadow(myDrawing);
		}
		else
		{
			(*it)->draw(myDrawing);
		}
	}
}

void getInstructionsFile(ifstream &instructions, string &fileName)
{
	cout << "Please enter a file name (include .stb): " << endl;
	cin >> fileName;

	instructions.open(fileName);

	while (!instructions.is_open())
	{
		cout << "I'm sorry, the file you entered could not be opened." << endl
			<< "Please enter another file name including the '.stb' file extension: ";
		cin >> fileName;
		instructions.open(fileName);
	}
}

void deleteAllShapes(vector<Shape*> &shapes)
{
	for (auto it = shapes.begin(); it != shapes.end(); it++)
	{
		delete *it;
	}
}

void createAllShapes(ifstream &instructions, vector<Shape*> &shapes)
{
	while (!instructions.eof())
	{
		string shapeType;
		string shapeAttributes;

		getline(instructions, shapeType, ' ');
		getline(instructions, shapeAttributes);

		createShape(shapeType, shapeAttributes, shapes);
	}
}