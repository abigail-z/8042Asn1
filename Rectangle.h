#pragma once

#include <vector>

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

bool AreaCompare(const Rectangle a, const Rectangle b)
{
	int aArea = a.GetLength() * a.GetWidth();
	int bArea = b.GetLength() * b.GetWidth();

	return aArea <= bArea;
}

bool PerimeterCompare(const Rectangle a, const Rectangle b)
{
	int aPerimeter = a.GetLength() * 2 + a.GetWidth() * 2;
	int bPerimeter = b.GetLength() * 2 + b.GetWidth() * 2;

	return aPerimeter <= bPerimeter;
}

template <typename Object, typename Comparator>
const Object& findMax(const std::vector<Object>& arr, Comparator isLessThan)
{
    int maxIndex = 0;
    
    for (int i = 1; i < arr.size(); ++i)
        if (isLessThan(arr[maxIndex], arr[i]))
            maxIndex = i;
    
    return arr[maxIndex];
}


// Define the FindMaxByArea() and FindMaxByPerim() functions here

const Rectangle& FindMaxByArea(const std::vector<Rectangle>& arr)
{
	return findMax(arr, AreaCompare);
}

const Rectangle& FindMaxByPerim(const std::vector<Rectangle>& arr)
{
	return findMax(arr, PerimeterCompare);
}
