
// File: Employee.cpp
// Author(s):

#include <iostream> // cout, <<
#include <string>   // string data type
#include <iomanip>  // setw()
using namespace std;

#include "Employee.h"

const double MINWAGE = 11.25;

int Employee::next_id = 1; // definition of next_id outside of public member functions 
int Employee::num_emps = 0;

Employee::Employee(const string& n, double r) : id(next_id++), name(n), rate(r > MINWAGE ? r : MINWAGE) 
{
    num_emps++;
}

void Employee::print() const {
    cout << "Employee # " << id << ", name: "
         << name << ", rate: " << fixed << setprecision(2) << rate << '\n';
}

void Employee::set_rate(double r)
{ rate = (r > MINWAGE ? r : MINWAGE); }

int Employee::get_next_id() {

    return next_id++;

}

int Employee::get_num_emps() {
    return num_emps;
}
