
// File: FCII_HW1_2.cpp
// Author(s):

#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> si1{ 4, 2, 5, -3, 0, -1, 9, 6, 6, 2, 5, 4, 12 };
	for (int el : si1)
		cout << el << ' ';
	cout << '\n';
}
