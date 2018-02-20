// File: FCII_HW5.cpp
// Authors(s): Duarte Bahia, Giebas, Oberoi, Rojas Coy

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>        // for sqrt(), exp(), pow()
#include <ctime>        // for time()
#include <random>       // for minstd_rand
using namespace std;


/***************************************************************/


int main()
{
    cout << boolalpha;  // true, false not 1, 0

                             // seed to 0 so everyone gets the same "random" numbers
    minstd_rand msrand(0);   // linear congruential with range 0 through 2^32-1

// (a)
    vector<int> v1;
    for (int i(0); i < 25; ++i)
        v1.push_back(msrand() % 10);
    cout << setw(8) << "v1: " << "size: " << setw(4) << v1.size() << ":  ";
    for (auto& el : v1) cout << el << ' '; cout << '\n';

    multimap<char,int> mm1;
    for (vector<int>::iterator it(v1.begin()); it != v1.end(); ++it) {
        pair<char,int> pci;
        pci.first = 'a' + msrand() % 5;  // random char in 'a','b','c','d','e'
        pci.second = *it;
        mm1.insert(pci);
    }
    cout << setw(8) << "mm1: " << "size: " << setw(4) << mm1.size() << ":  ";
    for (auto& el : mm1) cout << el.first << el.second << ' '; cout << '\n';

// (b)
/***** uncomment the code below for part (b)
    cout << "\ncreating x3, a vector of 50,000,000 random ints:\n";
    auto before_v3 = time(0);
    cout << setw(21) << "time before v3:  " << before_v3 << '\n';
    vector<int> v3;
    for (int i(0); i < 50'000'000; ++i)
        v3.push_back(msrand() % 200'000'000);
    auto after_v3 = time(0);
    cout << setw(21) << "time after v3:  " << after_v3 << '\n';
    cout << setw(21) << "to create v3:  " << after_v3 - before_v3 << " seconds\n";

    cout << "\nperforming 1000 lookups in v3:\n";
    before_v3 = time(0);
    cout << setw(21) << "time before looks:  " << before_v3 << '\n';
    int num_found(0);
    for (int i(0); i < 1000; ++i) {
        int val(msrand() % 200'000'000);
        if (find(v3.begin(), v3.end(), val) != v3.end())
            ++num_found;
    }
    after_v3 = time(0);
    cout << setw(21) << "time after looks:  " << after_v3 << '\n';
    cout << setw(21) << "to perform looks:  " << after_v3 - before_v3 << " seconds\n";
    cout << setw(21) << "num matches found:  " << num_found << "\n";

*****/

// (c)
/***** uncomment and complete the code below for part (c)
    copy and paste the code from (b) above.
    modify the code to sort vector v3, instead of creating
    a new vector, and report the time needed to do the sort.
    then, modify the code to use the binary_search algorithm
    rather than the find algorithm, and perform 10,000,000
    lookups rather than 1000; report the time needed for the
    lookups.

*****/

// (d)
/***** uncomment and complete the code below for part (d)
    copy and paste the code from (c) above.
    modify the code to create a set of 50,000,000 random ints,
    using the set<int>::insert member function rather than
    vector<int>::push_back, and report the time needed to
    create the set.
    then, modify the code to use the set<int>::find() member
    function rather than the find() algorithm, and to perform
    10,000,000 lookups rather than 1000; report the time
    needed to do the lookups.
*****/

// (e)
/***** uncomment and complete the code below for part (e)
    copy and paste the code from (d) above.
    modify the code to create an unordered_set of 50,000,000
    random ints, and report the time needed to create the
    unordered_set.
    use unordered_set<int>::find (which has the same interface
    as set<int>::find) to perform 10,000,000 lookups; report
    the time needed to do the lookups.
*****/

// (f)
/* uncomment and test this code:
    vector<double> dv1(v1.size());
    cout << "initially:\n";
    cout << setw(8) << "dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
    for (auto& el : dv1) cout << el << ' '; cout << '\n';
    for (int i(0); i < v1.size(); ++i)
        dv1[i] = sqrt(v1[i]);
    cout << "after filled with square roots:\n";
    cout << setw(8) << "dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
    for (auto& el : dv1) cout << el << ' '; cout << '\n';
*/

//  write the rest of the code for part (f) here

// (g)
//  write your code for part (g) here, except for add_rand() defined above main()


// (h)
//  write your code for part (h) here


// (i)
//  write your code for part (i) here


// (j)
//  write your code for part (j) here


// (k)
//  write your code for part (k) here


// (l)
//  write your code for part (l) here


// (m)
//  write your code for part (m) here


// (n)
//  write your code for part (n) here


// (o)
//  write your code for part (o) here


// (p)
//  write your code for part (p) here


// (q)
//  write your code for part (q) here


// (s)
//  write your code for part (s) here


// (t)
//  write your code for part (t) here


// (u)
//  write your code for part (u) here


// (v)
//  write your code for part (v) here

}
