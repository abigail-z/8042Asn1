#pragma once

#include "LinkedList.h"

// Define the Rectangle class here
class Rectangle
{
public:
	Rectangle(int length, int width) : length(length), width(width) {}
	int GetLength() const { return length; }
	int GetWidth() const { return width; }
private:
	int length;
	int width;
};

// Define the AreaCompare and PerimeterCompare functions here

typedef int (*ComparisonFunc)(const Rectangle a, const Rectangle b);

int AreaCompare(const Rectangle a, const Rectangle b)
{
	int aArea = a.GetLength() * a.GetWidth();
	int bArea = b.GetLength() * b.GetWidth();

	return (aArea < bArea) ? -1 : (aArea > bArea);
}

int PerimeterCompare(const Rectangle a, const Rectangle b)
{
	int aPerimeter = a.GetLength() * 2 + a.GetWidth() * 2;
	int bPerimeter = b.GetLength() * 2 + b.GetWidth() * 2;

	return (aPerimeter < bPerimeter) ? -1 : (aPerimeter > bPerimeter);
}

const Rectangle& FindMax(const LinkedList<Rectangle>& list, ComparisonFunc compare)
{
	Rectangle largest = *list.begin();
	
	for (const Rectangle rectangle : list)
		if (compare(rectangle, largest) > 0)
			largest = rectangle;
	
	return largest;
}

// Define the FindMaxByArea() and FindMaxByPerim() functions here

const Rectangle& FindMaxByArea(const LinkedList<Rectangle>& list)
{
	return FindMax(list, AreaCompare);
}

const Rectangle& FindMaxByPerim(const LinkedList<Rectangle>& list)
{
	return FindMax(list, PerimeterCompare);
}
