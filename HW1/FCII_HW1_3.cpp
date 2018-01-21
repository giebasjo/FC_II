
// File: FCII_HW1_3.cpp
// Author(s):
//  Harveen Oberoi
//  Daniel Rojas Coy
//  Lucas Duarte Bahia
//  Jordan Giebas

#include <iostream>
using namespace std;

// Employee.h contents

class Employee {
public:
    Employee(int i, const string& n, double r);
    virtual void print() const;
    void set_rate(double r);
    double get_rate() const { return rate; };
    //const int id;    // ID -- okay to be public
    const int get_id() const { return id; };
private:
    const int id;
    string name;     // name (arbitrary size)
    double rate;     // hourly rate
    Employee();      // no default Employees
    Employee(const Employee&);    // no clones
    Employee& operator=(const Employee&);
};

// Employee.cpp contents

const double MINWAGE = 11.25;

Employee::Employee(int i, const string& n, double r)
: id(i), name(n), rate(r > MINWAGE ? r : MINWAGE)
{}

void Employee::print() const {
    cout << "Employee # " << get_id() << ", name: "
         << name << ", rate: " << rate << '\n';
}

void Employee::set_rate(double r)
{ rate = (r > MINWAGE ? r : MINWAGE); }

//const int Employee::get_id() const {}

// Manager.h contents

// a Manager is a kind of Employee
class Manager : public Employee {
public:
    Manager(int i, const string& n, double r,
            const string& t, double b);
    virtual void print() const;  // override base class print
    virtual void set_budget(double b);
    virtual double get_budget() const { return budget; }
private:
    string title;
    double budget;
    Manager();      // no default Managers
    Manager(const Manager&);    // no clones
    Manager& operator=(const Manager&);
};

// Manager.cpp contents

const double DEFAULT_BUDGET = 500000.0;

Manager::Manager(int i, const string& n, double r,
        const string& t, double b)
: Employee(i, n, r),  // base class constructor
  title(t), budget(b > 0.0 ? b : DEFAULT_BUDGET)
{}

void Manager::set_budget(double b)
{ budget = (b > 0.0 ? b : DEFAULT_BUDGET); }

void Manager::print() const
{
    cout << "Manager information:\n";
    Employee::print();
    cout << "title: " << title << '\n';
    cout << "budget: " << budget << '\n';
}

/*
 * This is my code, 
 * not Professor Ostlunds!!!!
 */

// CEO.h contents
class CEO : public Manager {

    public:

        CEO(int i, const string& n, double r, const string& t, double b, double pt, double bp);

        // overloaded print function (virtual is unnecessary- there for brevity
        // to show that this is a derived class)
        virtual void print() const;

        // setters
        void set_bonus_percentage(double bp);
        void set_profit_target(double pt);

        // getters
        double get_bonus_percentage() { return bonus_pctage; }
        double get_profit_target() { return profit_target; }
        string get_title() { return title; }        

    private:

        double profit_target;
        double bonus_pctage;
        string title = "CEO";
        CEO(); // no default CEOs
        CEO(const CEO&); // no clones
        CEO& operator=(const CEO&);

};

// CEO.cpp contents

const double BONUS_PCTAGE = 20.0;
const double PROFIT_TARG = 5000000.0;

CEO::CEO(int i, const string& n, double r, const string& t, 
        double b, double pt, double bp) : Manager(i, n, r, "CEO", b), // Manager (base) constructor, calls Employee too 
        profit_target(pt), bonus_pctage(bp > 0.0 ? bp : BONUS_PCTAGE) {}

void CEO::set_bonus_percentage(double bp) { bonus_pctage = (bp > 0.0 ? bp : BONUS_PCTAGE); }

void CEO::set_profit_target(double pt) { profit_target = (pt > 0.0 ? pt : PROFIT_TARG); }

void CEO::print() const {

    cout << "CEO information:\n";
    Manager::print();
    cout << "profit target: " << profit_target << '\n';
    cout << "bonus percentage: " << bonus_pctage << endl;

}

// main function

int main()
{
    Employee alex(1, "Alex", 57.25);
    Employee bob(2, "Bob", 63.10);
    Manager carl(3, "Carl", 66.75, "Boss", 0.0);
    // Employee dave;    // error!  private default
    // Manager ed(carl); // error!  private copy
    // bob = alex;       // error!  private assignment

    cout << "Alex's ID: " << alex.get_id() << '\n';
    // alex.id = 123;       // error!  access violation
    bob.set_rate(6.31);     // 90% pay cut!  Ouch!
    bob.print();            // Employee::print()
    carl.set_rate(77.7);    // Employee::set_rate()
                            //     via inheritance
    carl.print();           // Employee::print()
    cout << "Carl's budget: " << carl.get_budget()
                              << '\n';
    // alex.get_budget()    // error!  An Employee is
                            // not a kind of Manager
/*
    // part (b)
    cout << "\n----- PART B -----" << endl;
    const Employee *p(&alex);
    cout << "Calling print() on an pointer-to-Employee:" << endl;
    p->print();
    p = &carl;
    cout << "Calling print() on an pointer-to-Manager:" << endl;
    p->print();
    cout << "Calling Employee::print() on an pointer-to-Manager:" << endl;
    p->Employee::print();

    // part (c)
    cout << "\n----- PART C -----" << endl;
    Employee gene(10, "Gene", 68.25);
    const Employee hank(12, "Hank", 67.0);
    Manager ian(13, "Ian", 71.75, "Boss", 250000.0);

    cout << "Gene's id: " << gene.get_id() << '\n';
    cout << "Hank's id: " << hank.get_id() << '\n';
    cout << "Ian's id: " << ian.get_id() << '\n';

    // part (d)
    cout << "\n----- PART D -----" << endl;
    p = &gene;
    p->print();

    p = &hank; 
    p->print();

    p = &ian;
    p->print();
*/
    // part (f)
    cout << "\n----- PART F -----" << endl;
    CEO joe(15, "Joe", 120.0,
             "CEO",               // joe's title will be "CEO"
             100000000.0,   // budget
               4000000.0,   // profit target
                   250.0);  // bonus percentage
    joe.print();
    cout << "Joe's id: " << joe.get_id() << '\n';
    cout << "Joe's rate: " << joe.get_rate() << '\n';
    cout << "Joe's title: " << joe.get_title() << '\n';
    cout << "Joe's budget: " << joe.get_budget() << '\n';
    cout << "Joe's profit target: "
         << joe.get_profit_target() << '\n';
    cout << "Joe's bonus percentage: "
         << joe.get_bonus_percentage() << '\n';

    // 10% raise
    joe.set_rate(joe.get_rate() * 1.1);
    // 20% budget increase
    joe.set_budget(joe.get_budget() * 1.2);
    // 10% profit target reduction
    joe.set_profit_target(
              joe.get_profit_target() * 0.90);
    // 30% increase in bonus percentage
    joe.set_bonus_percentage(
              joe.get_bonus_percentage() * 1.3);
    
    cout << "\n NOW TRYING WITH A POINTER " << endl;
    const Employee* p(&joe);
    p->print();

}

