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

void add_rand(double& d) {
	d += (rand() % 100) / 100.0;
}

double dpow(double a, double b) {
	return pow(a, b);
}

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
	/*

// (b)

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



// (c)

	cout << "\n Sorting vector v3:\n";
	before_v3= time(0);
	cout << setw(21) << "time before v3:  " << before_v3 << '\n';
	//
	std::sort(v3.begin(), v3.end());
	//
	after_v3 = time(0);
	cout << setw(21) << "time after v3:  " << after_v3 << '\n';
	cout << setw(21) << "to sort v3:  " << after_v3 - before_v3 << " seconds\n";

	cout << "\nperforming 10000000 binary searchs in v3:\n";
	before_v3 = time(0);
	cout << setw(21) << "time before search:  " << before_v3 << '\n';
	num_found=0
		;
	for (int i(0); i < 10000000; ++i) {
		int val(msrand() % 200'000'000);
		if (binary_search(v3.begin(), v3.end(), val)) //!= v3.end())
			++num_found;
	}
	after_v3 = time(0);
	cout << setw(21) << "time after search:  " << after_v3 << '\n';
	cout << setw(21) << "to perform search:  " << after_v3 - before_v3 << " seconds\n";
	cout << setw(21) << "num matches found:  " << num_found << "\n";
 */
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

/*
	cout << "\n Creating s2, a set of 50,000,000 random ints:\n";
	
	// TODO: change this
	auto before_v3 = time(0);
	//before_v3 = time(0);

	cout << setw(21) << "time before s2:  " << before_v3 << '\n';
	set<int> s2;
	//TODO: 50mil
	for (int i(0); i < 500000; ++i)
		s2.insert(msrand() % 200'000'000);
	// TODO: change this
	auto after_v3 = time(0);
	//after_v3 = time(0);
	cout << setw(21) << "time after s2:  " << after_v3 << '\n';
	cout << setw(21) << "to create s2:  " << after_v3 - before_v3 << " seconds\n";

	cout << "\nperforming 10000000 lookups in v3:\n";
	before_v3 = time(0);
	cout << setw(21) << "time before looks:  " << before_v3 << '\n';
	// TODO: change this
	//num_found = 0;
	auto num_found = 0;
	//TODO: 10mil
	for (int i(0); i < 1000000; ++i) {
		int val(msrand() % 200'000'000);
		if ( s2.find(val) != s2.end())
			++num_found;
	}
	after_v3 = time(0);
	cout << setw(21) << "time after looks:  " << after_v3 << '\n';
	cout << setw(21) << "to perform looks:  " << after_v3 - before_v3 << " seconds\n";
	cout << setw(21) << "num matches found:  " << num_found << "\n";

	*/

// (e)
/*
	cout << "\n Creating us, a unordered set of 50,000,000 random ints:\n";

	// TODO: change this
	auto before_v3 = time(0);
	//before_v3 = time(0);

	cout << setw(21) << "time before s2:  " << before_v3 << '\n';
	set<int> us2;
	//TODO: 50mil
	for (int i(0); i < 500000; ++i)
		us2.insert(msrand() % 200'000'000);
	// TODO: change this
	auto after_v3 = time(0);
	//after_v3 = time(0);
	cout << setw(21) << "time after s2:  " << after_v3 << '\n';
	cout << setw(21) << "to create s2:  " << after_v3 - before_v3 << " seconds\n";

	cout << "\nperforming 10000000 lookups in v3:\n";
	before_v3 = time(0);
	cout << setw(21) << "time before looks:  " << before_v3 << '\n';
	// TODO: change this
	//num_found = 0;
	auto num_found = 0;
	//TODO: 10mil
	for (int i(0); i < 1000000; ++i) {
		int val(msrand() % 200'000'000);
		if (us2.find(val) != us2.end())
			++num_found;
	}
	after_v3 = time(0);
	cout << setw(21) << "time after looks:  " << after_v3 << '\n';
	cout << setw(21) << "to perform looks:  " << after_v3 - before_v3 << " seconds\n";
	cout << setw(21) << "num matches found:  " << num_found << "\n";
*/

// (f)

cout << "\n####### PART F #######\n";

    vector<double> dv1(v1.size());
    cout << "initially:\n";
    cout << setw(8) << "dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
    for (auto& el : dv1) cout << el << ' '; cout << '\n';
    for (int i(0); i < v1.size(); ++i)
        dv1[i] = sqrt(v1[i]);
    cout << "after filled with square roots:\n";
    cout << setw(8) << "dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
    for (auto& el : dv1) cout << el << ' '; cout << '\n';

//  write the rest of the code for part (f) here
	
	cout << "Assign and transform:\n";
	dv1.assign (dv1.size(), 0.0);
	transform(v1.begin(), v1.end(), dv1.begin(), (double(*)(int)) sqrt);
	cout << setw(8) << "\n dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
	for (auto& el : dv1) cout << el << ' '; cout << '\n';


// (g)
//  write your code for part (g) here, except for add_rand() defined above main()
	cout << "\n####### PART G #######\n";

	vector<double> dv2(dv1);
	cout << "\nCopy of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	for_each(dv2.begin(), dv2.end(), add_rand);
	cout << "\nadd_rand():\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';


// (h)
//  write your code for part (h) here
	cout << "\n####### PART G #######\n";

	// Shuffle
	random_shuffle(dv2.begin(), dv2.end());
	cout << "\nShuffle of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	// Reverse
	reverse(dv2.begin(), dv2.end());
	cout << "\nReverse of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	// Sort
	sort(dv2.begin(), dv2.end());
	cout << "\nSort of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	// Lower bounds
	auto l2(lower_bound(dv2.begin(), dv2.end(), 2.0));
	auto l3(lower_bound(dv2.begin(), dv2.end(), 3.0));
	cout << "\nLower bound:\n";
	for (auto it(l2); it != l3; ++it) {
		cout << *it << " ";
	}

// (i)
//  write your code for part (i) here
	cout << "\n\n####### PART I #######\n";
	
	// EXP
	transform(dv2.begin(), dv2.end(), dv2.begin(), (double(*)(double)) exp);
	cout << "\nExp of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';
	
	// CEIL
	transform(dv2.begin(), dv2.end(), dv2.begin(), (double(*)(double)) ceil);
	cout << "\nLog of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	// LOG
	transform(dv2.begin(), dv2.end(), dv2.begin(), (double(*)(double)) log);
	cout << "\nCeil of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';


// (j)
//  write your code for part (j) here
	cout << "\n####### PART J #######\n";

	cout << "dv1: ";
	for (auto& el : dv1) cout << el << ' '; cout << '\n';

	vector<double> dv3;
	dv3.assign(dv1.size(), 0.0);
	transform(dv1.begin(), dv1.end(), dv2.begin(), dv3.begin(), dpow);
	cout << "\nPow(dv1[i],dv2[i]):\n";
	cout << "dv2: ";
	for (auto& el : dv3) cout << el << ' '; cout << '\n';


// (k)
//  write your code for part (k) here
	cout << "\n####### PART K #######\n";
	vector<int> v2(v1);
	cout << "v1 equal to v2: " << equal(v1.begin(), v1.end(), v2.begin()) << "\n";

	random_shuffle(v1.begin(), v1.end());
	cout << "  v1 was shuffled\n";
	cout << "v1 equal to v2: " << equal(v1.begin(), v1.end(), v2.begin()) << "\n";
	cout << "v1 permutation of v2: " << is_permutation(v1.begin(), v1.end(), v2.begin()) << "\n";

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
