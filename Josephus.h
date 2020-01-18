#include <iostream>

#include "Person.h"

// The Josephus problem is the following game:
//  N people, numbered 1 to N, are sitting in a circle.
//  Starting at person 1, a hot potato is passed.
//  After M passes, the person holding the hot potato is eliminated,
//      the circle closes ranks, and the game continues
//      with the person who was sitting after the eliminated person
//      picking up the hot potato.
//  The last remaining person wins.
//  Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins.
//      If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5.
// m is number of people
// n is number of passes before elimination
int Josephus(int m, int n)
{
	Person* current = CreateCircle(n);

	for (int i = 0; i < n - 1; ++i)
	{
		// skip m
		for (int j = 0; j < m; ++j)
		{
			current = current->next;
		}

		// print the number to be removed
		std::cout << current->number << " ";

		// remove it
		Person* temp = current;
		current = temp->next;
		current->prev = temp->prev;
		temp->prev->next = current;
		delete temp;
	}

    int winner = current->number;
	delete current;

	return winner;
}
