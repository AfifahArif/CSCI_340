/***
Afifah Arif
Assignment 9 = Hashing with Linear Probing and Indirect Sorting
Due Date: November 27, 2018
***/

#include "/home/cs340/progs/18f/p9/hTable.h"

#ifndef H_TABLE
#define H_TABLE

void ptr_sort( vector <Entry*> );
bool predicate( Entry*, Entry* );

//constructor
HT::HT(  const unsigned& s )
{
	hTable.resize(s);
	pTable.resize(s);
	psize = 0;
	hsize = SZ_TBL;
	for(unsigned int i = 0; i != s; i++)
	{
		hTable[i].key = FREE;
	}
}

//destructor
HT::~HT()
{

}

void HT::insert( const Entry& e ) //insert items into a hash table
{
	int index = hash(e.key);
	unsigned int i;
	for(i = 0; i < hsize; i++)
	{
		if(hTable[(index+i)%hsize].key == FREE)
		{
			cout << " entry = " << (index + i) % hsize << endl;
			hTable[(index+i)%hsize] = e;
			pTable[psize] = &hTable[(index+i)%hsize];
			psize++;
			break;
		}

		if(hTable[(index+i)%hsize].key == e.key)
		{
			cout << " not inserted - duplicate key!!!" << endl;
			break;
		}
	}

	if(i == hsize)
		cout << " not inserted - table full!!!" << endl;
}

void HT::search( const string& s ) //searches hash table for key
{
	int index = hash(s);
	unsigned int i;
	for(i = 0; i < hsize; i++)
	{
		if(hTable[(index+i)%hsize].key == s)
		{
			cout << " ==> number: "<< setw(4) << hTable[(index+i)%hsize].num
			<< " - item: " << hTable[(index+i)%hsize].desc << endl;
			break;
		}
	}
	if(hTable[(index+i)%hsize].key != s)

	cout << " not in table!!" << endl;
}

void HT::hTable_print() //prints hash table
{
	bool lastEmpty = false;
	for( unsigned int i = 0; i < hsize; i++ )
	{
		if( hTable[i].key != FREE )
		{
			if( lastEmpty )
			cout << endl;

			cout << setw(4) << i << ":  " << hTable[i].key << " - "
			<< setw(5) << hTable[i].num << "   -  " << hTable[i].desc << endl;
			lastEmpty = false;
		}
		else lastEmpty = true;
	}
	cout << endl;
}

void HT::pTable_print() //will print pointer table
{
	ptr_sort( pTable );
	for(unsigned int i = 0; i < psize; i++ )
	{
		cout << "   " << pTable[i]->key
		<< " - " << right << setw(4) << pTable[i]->num
		<< " - " << left << pTable[i]->desc << endl;
	}
	cout << endl;
}

void ptr_sort( vector <Entry*> pTable ) //will sort pointer table
{
	sort( pTable.begin(), pTable.end(), predicate );
}

//predicate pointer table sort function
bool predicate( Entry* left, Entry* right )
{
	if( left->key < right->key ) return true;

	return false;
}
#endif