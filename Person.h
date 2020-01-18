#pragma once

struct Person
{
	Person(int n)
		: next(nullptr)
		, number(n)
	{
	}

	Person* next;
	const int number;
};
