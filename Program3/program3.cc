/***
Afifah Arif
Program 3 - Sieve of Eratosthenes
Due Date: 9/24/18
***/

#include "program3.h"              // header file

#include <iostream>		// cout, endl
#include <cstring>		// characters
#include <iomanip>		// setw - set field width
#include <set>			// container
#include <algorithm>	// sieve of eratosthenes algorithm

using namespace std;

void sieveEra (int n)
{
	bool prime[n+1];	// creates boolean array
	memset(prime, true, sizeof(prime));

	for(int p=2; p*p<=n; p++)
	{
		if(prime[p] == true)
		{
			for(int i=p*2; i<=n; i +=p)		// runs through all multiples
			prime[i] = false;
		}
	}

	// prints prime #s
	for(int p=2; p<=n; p++)
		if(prime[p])
		cout << p << " ";
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	cout << "The following values are prime numbers: " << n << setw(4) << endl;

	sieveEra(n);

	return 0;
}
