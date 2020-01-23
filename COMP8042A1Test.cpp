#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string>

#include "Rectangle.h"
#include "Matrix.h"
#include "Josephus.h"
#include "LinkedList.h"

using namespace std;

ostream &operator << (ostream& s, Rectangle r)
{
	s << "Rectangle: " << r.GetLength() << "x" << r.GetWidth();
	return s;
}

template <typename T>
ostream &operator << (ostream& s, Matrix<T>& m)
{
	for (int i = 0; i < m.Rows(); i++)
	{
		for (int j = 0; j < m.Cols(); j++)
		{
			s << m[i][j] << " ";
		}
		s << endl;
	}

	return s;
}


int main()
{
	LinkedList<Rectangle> recList
	{
		Rectangle(1, 3),
		Rectangle(4, 4),
		Rectangle(4, 2),
		Rectangle(7, 2),
		Rectangle(1, 2),
		Rectangle(2, 2),
		Rectangle(6, 2)
	};

	cout << AreaCompare(Rectangle(2, 2), Rectangle(1, 1)) << endl;

	
	cout << "***** Q1: Rectangle class" << endl;
	for (Rectangle r : recList)
		cout << r << endl;
	cout << endl;

	cout << "Highest Area: " << FindMaxByArea(recList) << endl;
	cout << "Highest Perimeter: " << FindMaxByPerim(recList) << endl << endl;

	
	cout << endl << endl << "***** Q2: Matrix class" << endl;
	Matrix<int> matrix = Matrix<int>();
	cout << "Zero-parameter Matrix (rows,cols) = (" << matrix.Rows() << "," << matrix.Cols() << ")" << endl;
	
	matrix.Resize(4, 3);
	cout << "Resized Matrix to 4x3" << endl;
	cout << matrix << endl;
	matrix[2][1] = 12;
	cout << "Modified (2,1)" << endl;
	cout << matrix << endl;

	
	cout << endl << endl << "***** Q3: Josephus problem" << endl;
	cout << "Elimination order (0, 5): ";
	int winner = Josephus(0, 5);
	cout << "+++WINNER: " << winner << endl;
	cout << "Elimination order (1, 5): ";
	winner = Josephus(1, 5);
	cout << "+++WINNER: " << winner << endl;
	cout << "Elimination order (3, 7): ";
	winner = Josephus(3, 7);
	cout << "+++WINNER: " << winner << endl;

	
	return 0;
}
