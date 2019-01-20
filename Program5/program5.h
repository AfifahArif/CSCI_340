/***
Afifah Arif
Program 5 - The Josephus Problem (header file)
Due Date: October 11, 2018
***/

#ifndef PROGRAM5_H
#define PROGRAM5_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int No_Items=12; // const declaration for No_Items
const string Init_Val="A1"; // const declaration for Init_Val

void init_vals(vector <string>& v, unsigned& N, unsigned& M);
void print_vector(const vector <string>& v, const unsigned& cnt);

#endif
