#pragma once

template <typename T>
class Matrix
{
public:
	// Zero-parameter constructor
	Matrix()
		: Matrix(0, 0)
	{
	}

	// Constructor with size parameters
	Matrix(int rows, int cols)
		: rows(rows)
		, cols(cols)
	{
		collection = new T*[rows];

		for (int i = 0; i < rows; ++i)
		{
			collection[i] = new T[cols]{};
		}
	}

	// Copy constructor
	Matrix(const Matrix<T>& old)
		: rows(old.rows)
		, cols(old.cols)
	{
		collection = new T * [rows];

		for (int i = 0; i < rows; ++i)
		{
			collection[i] = new T[cols];

			for (int j = 0; j < cols; ++j)
			{
				collection[i][j] = old.collection[i][j];
			}
		}
	}

	// Destructor
	~Matrix()
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] collection[i];
		}

		delete[] collection;
	}

	// Square bracket accessor operator
	T* operator[] (int row)
	{
		return collection[row];
	}
	
	// Row count accessor
	int Rows() const
	{
		return rows;
	}

	// Column count accessor
	int Cols() const
	{
		return cols;
	}

	// Resize number of rows and columns
	void Resize(int rows, int cols)
	{
		// initialize new array
		T** temp = new T*[rows];
		for (int i = 0; i < rows; ++i)
		{
			temp[i] = new T[cols]{};
		}

		// copy from old array
		int minRows = rows > this->rows ? this->rows : rows;
		int minCols = cols > this->cols ? this->cols : cols;
		for (int i = 0; i < minRows; ++i)
		{
			for (int j = 0; j < minCols; ++j)
			{
				temp[i][j] = collection[i][j];
			}
		}
		
		// delete old array
		for (int i = 0; i < this->rows; ++i)
		{
			delete[] collection[i];
		}
		delete[] collection;

		// store new data
		collection = temp;
		this->rows = rows;
		this->cols = cols;
	}

private:
	T** collection;
	int rows;
	int cols;
};
