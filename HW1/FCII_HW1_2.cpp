
// File: FCII_HW1_2.cpp
// Author(s):

#include <iostream>
#include <set>
using namespace std;

bool gtr_than(int i, int j) { return i > j; }
bool even_up_odd_down(int i, int j) {

    if ( (i%2==0) && (j%2==0) ) {
        return i < j;
    }
    if ( (i%2==0) && (j%2==1) ) {
        return i > j;
    }
    if ( (i%2==1) && (j%2==0) ) {
        return i < j;
    }
    if ( (i%2==1) && (j%2==1) ) {
        return i > j;
    }   

    return -1;
}

int main()
{
	set<int> si1{ 4, 2, 5, -3, 0, -1, 9, 6, 6, 2, 5, 4, 12 };
	for (int el : si1)
		cout << el << ' ';
	cout << '\n';

        typedef bool (*pFbii) (int, int);

        set<int, bool (*)(int,int)> si2(gtr_than);

        for (int elm : si1) { si2.insert(elm); }
        for (int i : si2) { cout << i << ' '; }

        set<int, pFbii> si3(gtr_than);

        cout << "\n For si3: " << endl;
        for (int elm : si1) { si3.insert(elm); }
        for (int i : si3) { cout << i << ' '; }

        set<int, pFbii> si4(even_up_odd_down);
        
        cout << "\n For si4: " << endl;
        for (int elm : si1) { si4.insert(elm); }
        for (int i : si4) { cout << i << ' '; }

}
