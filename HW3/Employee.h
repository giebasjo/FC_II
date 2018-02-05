
// File: Employee.h
// Author(s):

#ifndef _STOCK_H_
#define _STOCK_H_

#include <string>        // string data type
using namespace std;

class Employee {
public:
    Employee(const string& n, double r);
    virtual void print() const;
    void set_rate(double r);
    double get_rate() const;
    int get_id() const;
    static int get_next_id();
    static int get_num_emps();
    virtual ~Employee();
private:
    static int next_id; // part(a) static member var
    static int num_emps;
    const int id;    // ID -- okay to be public
    string name;     // name (arbitrary size)
    double rate;     // hourly rate
    Employee();      // no default Employees
    Employee(const Employee&);    // no clones
    Employee& operator=(const Employee&);
};

inline double Employee::get_rate() const
{ return rate;  }

inline int Employee::get_id() const 
{ return id;  }

inline int Employee::get_next_id() 
{ return next_id++; }

inline int Employee::get_num_emps()
{ return num_emps; }

#endif
