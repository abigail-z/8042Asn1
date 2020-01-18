#pragma once

#include <vector>

template <typename Object>
class matrix
{

public:
	matrix(int rows, int cols)
		: array{rows}
	{
		for (auto& thisRow : array)
			thisRow.resize(cols);
	}

    matrix(std::initializer_list<std::vector<Object>> lst)
		: array(lst.size())
    {
        int i = 0;
        for(auto & v : lst)
            array[i++] = std::move(v);
    }
    
    matrix(const std::vector<std::vector<Object>>& v)
		: array{v}
	{
	}

    matrix(std::vector<std::vector<Object>>&& v)
		: array{std::move(v)}
	{
	}

    // *** Provide zero-parameter constructor here
	matrix()
		: array ()
	{
	}

    const std::vector<Object>& operator[](int row) const
    {
        return array[row];
    }

	std::vector<Object>& operator[](int row)
    {
        return array[row];
    }
    
    int numrows() const
    {
        return array.size();
    }

    int numcols() const
    {
        return numrows() ? array[0].size() : 0;
    }

    // *** Provide resize method here
	void resize(int rows, int cols)
	{
		array.resize(rows);
		for (std::vector<Object>& row : array)
		{
			row.resize(cols);
		}
	}

private:
	std::vector<std::vector<Object>> array;

};
