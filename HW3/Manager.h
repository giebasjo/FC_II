
// File: Manager.h
// Author(s):

#ifndef _MANAGER_H
#define _MANAGER_H

#include <string>        // string data type
using namespace std;
#include "Employee.h"    // Employee data type


// a Manager is a kind of Employee
class Manager : public Employee {
public:
    Manager(const string& n, double r = 51.25,
            const string& t = "Manager", double b = 350000.0);
    virtual void print() const;  // override base class print
    void set_budget(double b);
    double get_budget() const;
    void set_title(const string& s) { title = s; }
    string get_title() const;
    static int get_num_mgrs();
    ~Manager();
private:
    string title;
    static int no_mgrs;
    double budget;
    Manager();      // no default Managers
    Manager(const Manager&);    // no clones
    Manager& operator=(const Manager&);
};

inline double Manager::get_budget() const
{ return budget; }

inline string Manager::get_title() const
{ return title; }

inline int Manager::get_num_mgrs() 
{ return no_mgrs; }


#endif
