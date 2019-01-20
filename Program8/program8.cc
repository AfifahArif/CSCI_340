/***
Afifah Arif
Program 8 - Heaps and Heapsort
Due Date: November 16, 2018
***/

#include "/home/cs340/progs/18f/p8/prog8.h"

//opens input file and insert items into vector
template <class T>
void get_list(vector<T>& v, const char* path)
{
	v.clear();
	T temp; //temp data
	ifstream inFile;
	inFile.open(path); //open file

	if(!inFile)
	{
		cout<<"ERROR - CANNOT OPEN FILE"<<endl;
		exit(1);
	}

	inFile>>temp; //first entry
	while(!inFile.eof()) //read until file ends
	{
		v.push_back(temp); //insert in vector
		inFile>>temp; //read next entry
	}
	inFile.close(); //close file
}

//constructs heap while also comparing elements with pred
template <class T, class P>
void construct_heap(vector<T>& v, P pred)
{
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

//constructor of print_list class
template <class T>
print_list <T>::print_list(const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c)
{
	sz = s; //heap size
	wid = w; //min num of chars written in cout
	len = l; //max num of items printed in line
	cnt = c; //counter
}

//prints heaped vector
template <class T>
void print_list<T>::operator()(const T& x)
{
	cout.width(wid);
	cout.precision(2);
	cout<<fixed<<showpoint<<x<<"";

	cnt++;

	if(cnt % len == 0 && cnt != 0)
	cout << std::endl;
}

int main()
{
	vector <int> v1; //heap of integers
	vector <float> v2; //heap of floating nums
	vector <string> v3; //heap of strings

	//header message
	cout<<"\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

	//first heap
	cout<<"first heap - ascending order:\n\n";
	get_list(v1, D1);
	construct_heap(v1, less<int>());
	print_list<int> print1(v1.size(), INT_SZ, INT_LN);
	for_each(v1.begin(), v1.end(), print1);

	cout<<"\n\nfirst heap - descending order:\n\n";
	get_list(v1, D1);
	construct_heap(v1, greater<int>());
	for_each(v1.begin(), v1.end(), print1);

	//second heap
	cout<<"\n\nsecond heap - ascending order:\n\n";
	get_list(v2, D2);
	construct_heap(v2, less<float>());
	print_list<float> print2(v2.size(), FLT_SZ, FLT_LN);
	for_each(v2.begin(), v2.end(), print2);

	cout<<"\n\nsecond heap - descending order:\n\n";
	get_list(v2, D2);
	construct_heap(v2, greater<float>());
	for_each(v2.begin(), v2.end(), print2);

	//third heap
	cout<<"\n\nthird heap - ascending order:\n\n";
	get_list(v3, D3);
	construct_heap(v3, less<string>());
	print_list<string> print3(v3.size(), STR_SZ, STR_LN);
	for_each(v3.begin(), v3.end(), print3);

	cout<<"\n\nthird heap - descending order:\n\n";
	get_list(v3, D3);
	construct_heap(v3, greater<string>());
	for_each(v3.begin(), v3.end(), print3);

	//termination message
	cout<<"\n\t\t*** end of program execution ***\n\n";
	return 0;
}