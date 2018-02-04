
//
// File: FCII_HW2_4.cpp
// Author(s): Duerte Bahia, Giebas, Oberoi, Rojas Coy
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Term {
public:
	Term() {
		n_terms++;
	}
	virtual ~Term() {
		n_terms--;
	}
	virtual string to_string() = 0;
	virtual double to_value() = 0;

	// 
	virtual void set_value(double) = 0;

	//
	static int n_terms;
	static int get_nterms() {
		return n_terms;
	}
	
};

class Constant : public Term {
public:
	Constant(double v) : value(v) {
		n_const++;
	}
	virtual ~Constant() {
		n_const--;
	}
	virtual string to_string() {
		ostringstream oss;
		oss << value;
		return oss.str();
	}
	virtual double to_value(){
		return value;
	}
	//
	static int n_const;
	static int get_ncons() {
		return n_const;
	}
	//
	virtual void set_value(double d) {};
private:
	double value;
};

class BinaryOp : public Term {
public:
	BinaryOp(Term * lf, Term * rt) {
		left = lf;    // now owner of lf
		right = rt;
	}
	virtual ~BinaryOp() {
		delete left;  // ... so can delete
		delete right;
	}
	
	virtual void set_value(double d) {};
protected:
	Term *left, *right;
};

class Plus : public BinaryOp {    // concrete class
public:
	Plus(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Plus() {}
	virtual string to_string() {
		ostringstream oss;
		oss << "(" << left->to_string() << " + "
			<< right->to_string() << ")";
		return oss.str();
	}
	virtual double to_value() {
		return (left->to_value() + right->to_value());
	}
};

// Homework

class Minus : public BinaryOp {    // concrete class
public:
	Minus(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Minus() {}
	virtual string to_string() {
		ostringstream oss;
		oss << "(" << left->to_string() << " - "
			<< right->to_string() << ")";
		return oss.str();
	}
	virtual double to_value() {
		return (left->to_value() - right->to_value());
	}
};

class Times : public BinaryOp {    // concrete class
public:
	Times(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Times() {}
	virtual string to_string() {
		ostringstream oss;
		oss << "(" << left->to_string() << " * "
			<< right->to_string() << ")";
		return oss.str();
	}
	virtual double to_value() {
		return (left->to_value() * right->to_value());
	}
};

class Divide : public BinaryOp {    // concrete class
public:
	Divide(Term * l, Term * r) : BinaryOp(l, r) {}
	virtual ~Divide() {}
	virtual string to_string() {
		ostringstream oss;
		oss << "(" << left->to_string() << " / "
			<< right->to_string() << ")";
		return oss.str();
	}
	virtual double to_value() {
		return (left->to_value() / right->to_value());
	}
};

// Generate random terms
Term* rand_term() {

	Term* c1 = new Constant((rand() % 5000 + 1) / 1000.0);
	Term* c2 = new Constant((rand() % 5000 + 1) / 1000.0);
	Term* c3 = new Constant((rand() % 5000 + 1) / 1000.0);
	Term* c4 = new Constant((rand() % 5000 + 1) / 1000.0);

	Term* t1;
	Term* t2;
	Term* t3;

	int i = rand() % 4;

	if (i == 1) {
		t1 = new Plus(c1, c2);
	}
	else if (i == 2) {
		t1 = new Minus(c1, c2);
	}
	else if (i == 3) {
		t1 = new Times(c1, c2);
	}
	else {
		t1 = new Divide(c1, c2);
	}

	i = rand() % 4;

	if (i == 1) {
		t2 = new Plus(c3, c4);
	}
	else if (i == 2) {
		t2 = new Minus(c3, c4);
	}
	else if (i == 3) {
		t2 = new Times(c3, c4);
	}
	else {
		t2 = new Divide(c3, c4);
	}

	i = rand() % 4;


	if (i == 1) {
		t3 = new Plus(t1, t2);
	}
	else if (i == 2) {
		t3 = new Minus(t1, t2);
	}
	else if (i == 3) {
		t3 = new Times(t1, t2);
	}
	else {
		t3 = new Divide(t1, t2);
	}

	return(t3);
}

//

class Variable : public Term {
public:
	Variable(double v) : value(v) {}
	virtual ~Variable() {}
	
	virtual string to_string() {
		ostringstream oss;
		oss << "X";
		return oss.str();
	}
	
	virtual double to_value(){
		return value;
	}
	
	//
	virtual void set_value(double d) {
		value = d;
	}
	//

	static int n_const;
	static int get_ncons(){
		return n_const;
	}
	
private:
	double value;
};


/////////////////////////////////////////////////////

int Term::n_terms = 0;
int Constant::n_const = 0;

int main()
{
	Term *c1 = new Constant(1.1);
	Term *c2 = new Constant(2.2);
	Term *c3 = new Constant(3.3);
	Term *p1 = new Plus(c1, c2);    // p1 now owns c1 and c2
	Term *p2 = new Plus(p1, c3);    // p2 now owns p1 and c3
	cout << p2->to_string() << " = "
		<< p2->to_value() << "\n";
	delete p2;    // all Terms deleted


	Term *ca = new Constant(1.5);
	Term *cb = new Constant(2.7);
	Term *cc = new Constant(0.8);
	Term *cd = new Constant(3.3);
	Term *ce = new Constant(4.7);
	Term *m = new Minus(ce, cc);
	Term *d = new Divide(cd, ca);
	Term *t = new Times(d, cb);
	Term *p = new Plus(m, t);
	cout << p->to_string() << " = "
		<< p->to_value() << "\n";
	delete p;



	{
		cout << "# Terms: " << Term::get_nterms()
			<< '\n';             // should display 0
		cout << "# Constants: " << Constant::get_ncons()
			<< '\n';             // should display 0
		Term *ca = new Constant(0.6);
		Term *cb = new Constant(-2.2);
		Term *cc = new Constant(0.7);
		Term *m = new Minus(ca, cb);
		Term *p = new Plus(m, cc);
		cout << p->to_string() << " = "
			<< p->to_value() << "\n";
		cout << "# Terms: " << Term::get_nterms()
			<< '\n';             // should display 5
		cout << "# Constants: " << Constant::get_ncons()
			<< '\n';             // should display 3
		delete p;
		cout << "# Terms: " << Term::get_nterms()
			<< '\n';             // should display 0
		cout << "# Constants: " << Constant::get_ncons()
			<< '\n';             // should display 0
	}

	cout << "\n Random expressions: \n";

	Term* tt = rand_term();
	cout << tt->to_string() << " = "
		<< tt->to_value() << "\n";
	delete tt;

	tt = rand_term();
	cout << tt->to_string() << " = "
		<< tt->to_value() << "\n";
	delete tt;

	tt = rand_term();
	cout << tt->to_string() << " = "
		<< tt->to_value() << "\n";
	delete tt;

	tt = rand_term();
	cout << tt->to_string() << " = "
		<< tt->to_value() << "\n";
	delete tt;

	tt = rand_term();
	cout << tt->to_string() << " = "
		<< tt->to_value() << "\n";
	delete tt;

	tt = NULL;

	/////
	cout << "\n Algebraic Expressions: \n";

	Term *k1 = new Variable(1.5);
	Term *k2 = new Constant(3.3);
	Term *k3 = new Constant(0.7);
	Term *k4 = new Constant(4.2);
	Term *k5 = new Constant(1.1);

	Term *pp1 = new Plus(k1, k2);
	Term *pp2 = new Divide(pp1, k3);
	Term *pp3 = new Times(k4, k5);
	Term *pp4 = new Minus(pp2, pp3);

	cout << pp4->to_string() << " = "
		<< pp4->to_value() << "\n";

	k1->set_value(5.5);

	cout << pp4->to_string() << " = "
		<< pp4->to_value() << "\n";
	
	delete pp4;   

	/////
	cout << "\n Quadratic Expressions: \n";

	k1 = new Variable(1.0);
	k2 = new Constant(2.2);
	k3 = new Constant(3.3);
	
	pp1 = new Times(k1, k1);
	pp2 = new Times(k2, k1);
	pp3 = new Plus(pp2, k3);
	pp4 = new Plus(pp1, pp3);

	cout << pp4->to_string() << " = "
		<< pp4->to_value() << "\n";
	
	k1->set_value(-1);

	cout << pp4->to_string() << " = "
		<< pp4->to_value() << "\n";
	
	cout << "Up to here there is no problem. However, when the destructor of pp4 (the whole expression) is called, it starts destroying the terms to the left and right recursively. When the destructor to the left is called (X*X), again each destructor is called, the left one is destructed, but the one on the right no longer exists; the pointer is pointing to an empty memory location, so it cannot be destroyed. This causes the program to crash \n";

	// delete pp4; // This line causes de program to crash

}

