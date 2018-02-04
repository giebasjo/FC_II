
//
// File: FCII_HW3_3.cpp
// Author(s):
//

#include <iostream>
#include <string>
using namespace std;

// define min_of<T> and abs_val<T> templates functions here

int main()
{
	cout << boolalpha;
	cout << "min_of(4, 6):        " << min_of(4, 6) << '\n';
	cout << "min_of(3.3, -1.2):   " << min_of(3.3, -1.2) << '\n';
	cout << "min_of('A', 'a'):    " << min_of('A', 'a') << '\n';
	cout << "min_of(false, true): " << min_of(false, true) << '\n';

	cout << "abs_val(2):          " << abs_val(2) << '\n';
	cout << "abs_val(-4):         " << abs_val(-4) << '\n';
	cout << "abs_val(3.3):        " << abs_val(3.3) << '\n';
	cout << "abs_val(-3.3):       " << abs_val(-3.3) << '\n';
}
