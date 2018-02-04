
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
    Manager(const string& n, double r,
            const string& t, double b);
    virtual void print() const;  // override base class print
    void set_budget(double b);
    double get_budget() const { return budget; }
    void set_title(const string& s) { title = s; }
    string get_title() const { return title; }
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

#endif
