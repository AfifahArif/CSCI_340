/*
Programmer: Afifah Arif
Class: CSCI 340 - Section 1
Program: 1 - Randomly Generated Numbers
*/

#include <iostream>		/* cout, endl */	
#include <iomanip>		/* setw  - set field width*/
#include <vector>		/* vector */
#include <cstdlib>		/* srand, rand */
#include <ctime>		/* time */
#include <algorithm>	/* sort algorithm */

void genRndNums(std::vector<int>* nums) 
{
	for(int i = 0; i < 250 ; i++) 
		nums->push_back(1 + rand()% 10000);
}

int main() 
{
	srand(time(NULL));

	std::vector<int>* nums = new 
		std::vector<int>();

	genRndNums(nums);

	std::sort(nums->begin(), 
		nums->end());

	for(std::vector<int>::iterator it = nums->begin(); it != nums->end(); ++it) 
		std::cout << *it << std::setw(5) << " ";

	return 0;
}
