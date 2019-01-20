/***
Afifah Arif
Program 5 - The Josephus Problem
Due Date: October 11, 2018
***/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct args
{
	unsigned N, M, K;
};

void init_vals(list<string> &L,args& in)
{
	cin>>in.N>>in.M>>in.K;
	cout<<"\nThe values of n m k are: "<<in.N<<" "<<in.M<<" "<<in.K;
	list<string>::iterator it;

	for(int i=0;i<in.N;i++)
	{
		string s;
		stringstream ss;
		ss<<char('A'+i/9);
		ss>>s;
		s+=char(((i+1)%9)+'0');
		L.push_back(s);
	}
}

void print(list < string >& L)
{
	int c=1;
	int i=0;

	for(list<string>::iterator it=L.begin(); it!=L.end(); it++)
	{
		cout<<*it<<" ";

		if(c==12)
		{
			c=1;cout<<"\n";
		}
		c++;
	}
	cout<<"\n";
}

int M;
int K;

void print_list ( const list < string >& L, const unsigned& cnt )
{
	cout<<"\nAt begining of the joseph problem\n";
	list < string > l=L;
	prnt(l);

	int counter=0;
	int sz=L.size()-1;
	int c=cnt;
	
	while(c<sz)
	{
		counter += M - 1;
		if( counter >= l.size() ) counter %= l.size();
		list<string>::iterator it = l.begin();

		for(int i=0;i<static_cast<unsigned int>( counter );i++)
		it++;
		l.erase( it );
		c++;
		if((c)%K==0)
		{
		cout<<"\n After deleting K name\n";
		prnt(l);
		}
	}	
	cout<<"\nLast remaining person: "<<*(l.begin());
}
	
int main()
{
	list<string> L;
	struct args in;
	init_vals(L,in);
	M=in.M;
	K=in.K;
	print_list(L,0);
}