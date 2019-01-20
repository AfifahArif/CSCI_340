/*
Afifah Arif
Class 340 - Assignment 6 (Binary Tree Class)
Due Date: October 30, 2018
*/

#include <iostream>		// cout, endl
#include <iomanip>
#include <math.h>
#include <algorithm>
#include "binTree.h"

using namespace std;

class RND1
{
	private:
		int low, high;

	public:
		static int RND()
		{
			srand(time(NULL));
			return (-999+ (rand() % (static_cast<int>(999 +999 + 1))));
			srand(time(NULL));
		}
};

class RND2
{
	float randm;
	public:
		static float RND()
		{
			srand(time(NULL));
			return -999.99 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(999.99+999.99)));
		}
};

template <class T>
void print(T a)
{
	cout<<a<<" ";
}

int main()
{
	srand(unsigned(time(0)));
	vector<int> A(100);
	vector<float> B(50);
	RND1 obj3=RND1();

	std::cout << "\nIn order traversal of int tree: \n";
	binTree <int> tr=binTree <int> ( );
	int count=1;
	generate(A.begin(), A.end(), &RND1::RND);
	for (auto iv: A) 
	{
		tr.insert(iv);
	}
	tr.inorder(&print);

	//float tree
	std::cout << "\n\nIn order traversal of float tree: \n";
	binTree <float> tr1=binTree <float> ( );
	generate(B.begin(), B.end(), &RND2::RND);
	for (auto iv: B) 
	{
		tr1.insert(iv);
	}

	tr1.inorder(&print);
	//print heights

	cout<<"\nint tree height"<<tr.height;

	cout<<"\nfloat tree height"<<tr1.height();
	cout<<endl;
	system("pause");
	return 0;
}
