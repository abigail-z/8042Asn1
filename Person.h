#pragma once

struct Person
{
	Person(int n)
		: next(nullptr)
		, prev(nullptr)
		, number(n)
	{
	}

	Person* next;
	Person* prev;
	const int number;
};

Person* CreateCircle(int n)
{
	Person* head = new Person(1);
	Person* current = head;
	for (int i = 2; i <= n; ++i)
	{
		current->next = new Person(i);
		current->next->prev = current;
		current = current->next;
	}
	current->next = head;
	head->prev = current;

	return head;
}
