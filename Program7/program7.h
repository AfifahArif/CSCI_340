/*
Afifah Arif
Program: Assignment 7 (Binary Search Trees and Tree Sort)
Due Date: November 8, 2018
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#ifndef PROGRAM7_H
#define PROGRAM7_H
#define SEED 1 //RNG seed
#define N 100 //number of rand ints
#define NO_ITEMS = 16 //max number of elements printed in line
#define ITEM_W 3 //size of each elements on printout
#define COUT_SZ cout << "size =" << setw(ITEM_W) << sz << ":" //prints size

unsigned sz; //vector size

class RND //class generates rand ints
{
	private:
		int seed;
	
	public:
		RND(const int& s = SEED): seed(s)
		{
			srand(seed);
		}

	int operator()
	{
		return rand() % N + 1;
	}
};

template<class T> void print(T& x)
{
	static unsigned cnt = 0;
	const string sp(12, ' ');

	cout << setw(ITEM_W) << x << ''; cnt++;

	if(cnt % NO_ITEMS == 0 || cnt == sz) 
		cout << endl << sp;
	if(cnt ==sz) cnt = 0;
}
#endif
