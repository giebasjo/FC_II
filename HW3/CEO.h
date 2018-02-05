
// File: CEO.h
// Author(s):

#ifndef _CEO_H
#define _CEO_H

#include <string>         // string data type
using namespace std;
#include "Manager.h"      // Manager class

// a CEO is a kind of Manager
class CEO : public Manager {
public:
    CEO(const string& n, double r, double b, double t, double p);
    void print() const;
    void set_profit_target(double);
    double get_profit_target() const;
    void set_bonus_percentage(double);
    double get_bonus_percentage() const;
    static int get_num_ceos();
    ~CEO();
private:
    static int no_ceos;
    double profit_target;
    double bonus_percentage;
    CEO();      // no default CEOs
    CEO(const CEO&);    // no clones
    CEO& operator=(const CEO&);
};

inline double CEO::get_profit_target() const 
{ return profit_target; }

inline double CEO::get_bonus_percentage() const
{ return bonus_percentage; }

inline int CEO::get_num_ceos() 
{ return no_ceos; }

#endif
