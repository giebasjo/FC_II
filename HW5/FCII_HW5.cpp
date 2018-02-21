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
#include <iterator>
#include <functional>
using namespace std;


/***************************************************************/

// Part g
void add_rand(double& d) {
	d += (rand() % 100) / 100.0;
}
// Part j
double dpow(double a, double b) {
	return pow(a, b);
}
// Part r
class TimesX {
public:
	TimesX(double d): x(d) {};
	double m(int y) {
		return x*y;
	}
	double operator() (double y) {
		return x*y;
	}
private:
	double x;
};
// Part s
class SeqInt {
public:
	SeqInt(int sta = 1, int ste = 1) : start(sta), step(ste), current(sta) {}
	int operator() () {
		current += step;
		return(current - step);
	}

private:
	int start;
	int step;
	int current;
};
/***************************************************************/
int main()
{
    cout << boolalpha;  // true, false not 1, 0

                             // seed to 0 so everyone gets the same "random" numbers
    minstd_rand msrand(0);   // linear congruential with range 0 through 2^32-1

// (a)
	cout << "\n####### PART A #######\n\n";
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
	
	cout << "\n####### PART B #######\n";
	//TODO
	int huge_number = 50000000;
	int big_number = 10000000;

    cout << "\ncreating x3, a vector of 50,000,000 random ints:\n";
    auto before_v3 = time(0);
    cout << setw(21) << "time before v3:  " << before_v3 << '\n';
    vector<int> v3;
    for (int i(0); i < huge_number; ++i)
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
	cout << "\n####### PART C #######\n";

	cout << "\n Sorting vector v3:\n";
	before_v3= time(0);
	cout << setw(21) << "time before v3:  " << before_v3 << '\n';
	//
	std::sort(v3.begin(), v3.end());
	//
	after_v3 = time(0);
	cout << setw(21) << "time after v3:  " << after_v3 << '\n';
	cout << setw(21) << "to sort v3:  " << after_v3 - before_v3 << " seconds\n";

	cout << "\nperforming 10,000,000 binary searchs in v3:\n";
	before_v3 = time(0);
	cout << setw(21) << "time before search:  " << before_v3 << '\n';
	num_found=0
		;
	for (int i(0); i < big_number; ++i) {
		int val(msrand() % 200'000'000);
		if (binary_search(v3.begin(), v3.end(), val)) //!= v3.end())
			++num_found;
	}
	after_v3 = time(0);
	cout << setw(21) << "time after search:  " << after_v3 << '\n';
	cout << setw(21) << "to perform search:  " << after_v3 - before_v3 << " seconds\n";
	cout << setw(21) << "num matches found:  " << num_found << "\n";

// (d)


	cout << "\n####### PART D #######\n";

	cout << "\n Creating s2, a set of 50,000,000 random ints:\n";
	before_v3 = time(0);

	cout << setw(21) << "time before s2:  " << before_v3 << '\n';
	set<int> s2;
	
	for (int i(0); i < huge_number; ++i)
		s2.insert(msrand() % 200'000'000);
	
	after_v3 = time(0);
	cout << setw(21) << "time after s2:  " << after_v3 << '\n';
	cout << setw(21) << "to create s2:  " << after_v3 - before_v3 << " seconds\n";

	cout << "\nperforming 10,000,000 lookups in v3:\n";
	before_v3 = time(0);
	cout << setw(21) << "time before looks:  " << before_v3 << '\n';
	
	num_found = 0;
	
	for (int i(0); i < big_number; ++i) {
		int val(msrand() % 200'000'000);
		if ( s2.find(val) != s2.end())
			++num_found;
	}
	after_v3 = time(0);
	cout << setw(21) << "time after looks:  " << after_v3 << '\n';
	cout << setw(21) << "to perform looks:  " << after_v3 - before_v3 << " seconds\n";
	cout << setw(21) << "num matches found:  " << num_found << "\n";


// (e)

	cout << "\n####### PART E #######\n";

	cout << "\n Creating us, a unordered set of 50,000,000 random ints:\n";

	before_v3 = time(0);
	
	cout << setw(21) << "time before s2:  " << before_v3 << '\n';
	set<int> us2;
	
	for (int i(0); i < huge_number; ++i)
		us2.insert(msrand() % 200'000'000);
	
	after_v3 = time(0);
	cout << setw(21) << "time after s2:  " << after_v3 << '\n';
	cout << setw(21) << "to create s2:  " << after_v3 - before_v3 << " seconds\n";

	cout << "\nperforming 10,000,000 lookups in v3:\n";
	before_v3 = time(0);
	cout << setw(21) << "time before looks:  " << before_v3 << '\n';
	
	num_found = 0;
	
	for (int i(0); i < big_number; ++i) {
		int val(msrand() % 200'000'000);
		if (us2.find(val) != us2.end())
			++num_found;
	}
	after_v3 = time(0);
	cout << setw(21) << "time after looks:  " << after_v3 << '\n';
	cout << setw(21) << "to perform looks:  " << after_v3 - before_v3 << " seconds\n";
	cout << setw(21) << "num matches found:  " << num_found << "\n";


// (f)

cout << "\n####### PART F #######\n";

    vector<double> dv1(v1.size());
    cout << "\ninitially:\n";
    cout << setw(8) << "dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
    for (auto& el : dv1) cout << el << ' '; cout << '\n';
    for (int i(0); i != v1.size(); ++i)
        dv1[i] = sqrt(v1[i]);
    cout << "after filled with square roots:\n";
    cout << setw(8) << "dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
    for (auto& el : dv1) cout << el << ' '; cout << '\n';

//  write the rest of the code for part (f) here
	
	cout << "\nAssign and transform:\n";
	dv1.assign (dv1.size(), 0.0);
	transform(v1.begin(), v1.end(), dv1.begin(), (double(*)(int)) sqrt);
	cout << setw(8) << "\n dv1: " << "size: " << setw(4) << dv1.size() << ":  ";
	for (auto& el : dv1) cout << el << ' '; cout << '\n';


// (g)
//  write your code for part (g) here, except for add_rand() defined above main()
	cout << "\n####### PART G #######\n";

	vector<double> dv2(dv1);
	cout << "\nCopy of dv1:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	for_each(dv2.begin(), dv2.end(), add_rand);
	cout << "\nadd_rand():\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';


// (h)
//  write your code for part (h) here
	cout << "\n####### PART H #######\n";

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
	cout << "\nValues betwee de lower bound of 2.0 and 3.0:\n";
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
	cout << "\nCeil of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';

	// LOG
	transform(dv2.begin(), dv2.end(), dv2.begin(), (double(*)(double)) log);
	cout << "\nLog of dv2:\n";
	cout << "dv2: ";
	for (auto& el : dv2) cout << el << ' '; cout << '\n';


// (j)
//  write your code for part (j) here
	cout << "\n####### PART J #######\n";

	vector<double> dv3;
	dv3.assign(dv1.size(), 0.0);
	transform(dv1.begin(), dv1.end(), dv2.begin(), dv3.begin(), dpow); //dpow is used to circumvent the cast issue
	cout << "\nPow(dv1[i],dv2[i]):\n";
	for (auto& el : dv3) cout << el << ' '; cout << '\n';


// (k)
//  write your code for part (k) here
	cout << "\n####### PART K #######\n";
	vector<int> v2(v1);
	cout << "\nv1 equal to v2: " << equal(v1.begin(), v1.end(), v2.begin()) << "\n";

	random_shuffle(v1.begin(), v1.end());
	cout << "  v1 was shuffled\n";
	cout << "v1 equal to v2: " << equal(v1.begin(), v1.end(), v2.begin()) << "\n";
	cout << "v1 permutation of v2: " << is_permutation(v1.begin(), v1.end(), v2.begin()) << "\n";

// (l)
//  write your code for part (l) here
	cout << "\n####### PART L #######\n";
	
	// 3s
	cout << "\nThere are " << count(v1.begin(), v1.end(), 3) << " 3s in v1\n";
	// minmax
	auto result = std::minmax_element(v1.begin(), v1.end());
	cout << "The min of v1 is " << *result.first << "\n";	
	cout << "The max of v1 is " << *result.second << "\n";
	// find 9
	cout << "Elements after the first 9: \n";
	auto first9 = find (v2.begin(), v2.end(), 9);
	
	for (auto it(first9); it != v2.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

// (m)
//  write your code for part (m) here
	cout << "\n####### PART M #######\n";
	
	deque<int> d1;
	copy(v1.begin(), v1.end(), back_inserter(d1));
	cout << "\nd1:\n";
	for (auto& el : d1) cout << el << ' '; 
	cout << '\n';


// (n)
//  write your code for part (n) here
	//TODO:
	
	cout << "\n####### PART N #######\n";
	

	forward_list<int> fl1;
	
	copy(v1.rbegin(), v1.rend(), front_inserter(fl1));
	cout << "\nfl1:\n";
	for (auto& el : fl1) cout << el << ' ';
	cout << '\n';
	
// (o)
//  write your code for part (o) here
	cout << "\n####### PART O #######\n";

	ostream_iterator<int> out_it(cout, "\t");
	cout << "\nv1:\n";
	copy(v1.begin(), v1.end(), out_it);
	cout << "\n\nd1:\n";
	copy(d1.begin(), d1.end(), out_it);
	cout << "\n\nfl1:\n";
	copy(fl1.begin(), fl1.end(), out_it);
	cout << '\n';

// (p)
//  write your code for part (p) here

	cout << "\n####### PART P #######\n";

	ostream_iterator<int> out_it2(cout, " ");
	cout << "\nv1:\n";
	copy(v1.begin(), v1.end(), out_it2);
	cout << '\n';

	auto middle = v1.begin();
	advance(middle, v1.size() / 2);
	copy(d1.begin(), d1.end(), inserter(v1, middle));
	cout << "\nv1:\n";
	for (auto& el : v1) cout << el << ' ';
	cout << '\n';



// (q)
//  write your code for part (q) here
	cout << "\n####### PART Q #######\n";

	v1.resize(v1.size() / 2);
	
	cout << "\nv1:\n";
	for (auto& el : v1) cout << el << ' ';
	cout << '\n';

// (r)
//  write your code for part (r) here
	
	cout << "\n####### PART R #######\n";

	auto op15(TimesX(1.5));

	deque<double> d2;

	transform(v1.begin(), v1.end(), back_inserter(d2), op15);

	ostream_iterator<double> osdsp(cout, " ");
	cout << "\n(r)\nd2:\t";
	copy(d2.begin(), d2.end(), osdsp); cout << '\n';


// (s)
//  write your code for part (s) here

	cout << "\n####### PART S #######\n";
	SeqInt si11, si51(5), si0m2(0, -2);
	cout << "\n(s)\ns11:\t";
	for (int i(0); i < 10; ++i) cout << si11() << ' ';
	cout << "\ns51:\t";
	for (int i(0); i < 10; ++i) cout << si51() << ' ';
	cout << "\nsi0m2:\t";
	for (int i(0); i < 10; ++i) cout << si0m2() << ' ';
	cout << "\n";


// (t)
//  write your code for part (t) here
	
	cout << "\n####### PART T #######\n";
	vector<int> v4;
	SeqInt odds(1, 2);
	ostream_iterator<int> oss5(cout, " ");

	generate_n(back_inserter(v4), 10, odds);
	
	cout << "\n(t)\nV4:\t";
	copy(v4.begin(), v4.end(), oss5); cout << '\n';

	
// (u)
//  write your code for part (u) here

	cout << "\n####### PART U #######\n";
	deque<double> d3;
	ostream_iterator<double> oss6(cout, " ");

	transform(d2.begin(), d2.end(), dv2.begin(), back_inserter(d3), minus<double>() );
	cout << "\nd3:\t";
	copy(d3.begin(), d3.end(), oss6); cout << '\n';

// (v)
//  write your code for part (v) here
	cout << "\n####### PART V #######\n";

	set<int> s1;
	// s2 was already in use, using s22 instead
	set<int, greater<int>> s22;

	
	copy(v1.begin(), v1.end(), inserter(s1, s1.begin()));
	
	copy(v1.begin(), v1.end(), inserter(s22, s22.begin()));
	cout << "\ns1:\t";
	for (auto& el : s1) cout << el << ' ';
	cout << '\n';
	cout << "\ns2:\t";
	for (auto& el : s22) cout << el << ' ';
	cout << '\n';
}
