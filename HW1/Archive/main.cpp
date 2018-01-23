
//
// File: EuropeanOptions.cpp
// Author(s):
//

#include <iostream>
#include <vector>
#include <cmath>      // for pow()
#include <algorithm>  // for max()
#include <iomanip>    // for setw()
#include <string>
using namespace std;

/* ---------------- EuropeanCallOption class definition ----------------- */

class EuropeanCallOption {
private:
    // Basic values of a stock option
    double S0;         // initial stock price
    double K;          // strike price
    double r;          // risk-free rate
    double sigma;      // volatility
    double T;          // expiration time
    // Inner class used by the binomial tree method
    class Price {
    public:
        double stockPrice;
        double optionPrice;
    };

    // a private helper function
    void put_BinomialTree(string header, const vector<vector<Price>>& bT);

public:
    // constructor defined inline within the class definition
    EuropeanCallOption(double s0, double k, double rfr,
                       double v, double et)
            : S0(s0), K(k), r(rfr), sigma(v), T(et)
    {}

    // Calculate the Price of the option
    // using the binomial tree method
    double binomialPrice(int numIntervals);

    // ... other pricing methods can be added here ...
    double BSMPrice();

};


/* ---------- EuropeanCallOption member function definition ----------- */

void EuropeanCallOption::put_BinomialTree(string header,
                                          const vector<vector<Price>>& bT)
{
    int N = (bT.size() == 0)
            ? 0
            : bT.size() - 1;

    if (N > 9) {  // if tree is too big, refuse to print anything
        // cout << header << "\n";
        // cout << "BinomialTree has " << N << " levels: too many to print!\n";
        return;
    }

    cout << "\n" << header << "\n\n";
    cout << "BinomialTree with " << N << " time steps:\n\n";
    for (int i(0); i < bT.size(); ++i) {
        cout << "Stock:  ";
        for (int j(0); j < bT[i].size(); ++j) {
            cout << setw(8) << bT[i][j].stockPrice;
        }
        cout << "\n";
        cout << "Option: ";
        for (int j(0); j < bT[i].size(); ++j) {
            cout << setw(8) << bT[i][j].optionPrice;
        }
        cout << "\n\n";
    }
    cout << "\n";
}


double EuropeanCallOption::binomialPrice(int numIntervals)
{
    // time interval length
    double deltaT  = T / numIntervals;;
    // factor by which stock price might rise at each step
    double u 	   = exp(sigma * sqrt(deltaT));
    // factor by which stock price might fall at each step
    double d 	   = 1 / u;
    // risk-free interest rate factor for one time interval
    double a	   = exp(r * deltaT);
    // RN probability of an up move in stock price
    double p	   = (a - d) / (u - d);
    // RN probability of a down move in stock price
    double q	   = 1.0 - p;
    // container for the binomialTree
    vector<vector<Price>> binomialTree;

    // put_BinomialTree("Initial, empty binomialTree:", binomialTree);

    // Build the shape of the binomialTree, by pushing
    // successively longer vector<Price> values (initially
    // all elements 0.0)
    for (int i(0); i <= numIntervals; ++i) {
        vector<Price> vInterval(i+1);    // i+1 {0.0,0.0} values
        binomialTree.push_back(vInterval);
    }
    put_BinomialTree("After filled in with all 0.0:", binomialTree);

    // Fill the stockPrice component of the binomialTree
    for (int i(0); i <= numIntervals; ++i)
        for (int j(0); j <= i; ++j)
            binomialTree[i][j].stockPrice =
                    S0 * pow(u, j) * pow(d, i-j);
    put_BinomialTree("After filled in with stock prices:", binomialTree);

    // Fill the optionPrices at the terminal nodes
    for (int j(0); j <= numIntervals; ++j) {
        binomialTree[numIntervals][j].optionPrice =
                max(binomialTree[numIntervals][j].stockPrice - K,
                    0.0);
    }
    put_BinomialTree("After filled in with terminal option values:", binomialTree);

    // Now work backwards, filling optionPrices in the rest of the tree
    // Your code here

    //Code for 1 b
    //----------------------------------------------------------------------------------------------------
    for (int i = numIntervals-1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            binomialTree[i][j].optionPrice =
                    (p*binomialTree[i+1][j+1].optionPrice + q*binomialTree[i+1][j].optionPrice)*(1/a);

        }
    }
    //---------------------------------------------------------------------------------------------------



    put_BinomialTree("After filled in with all option values:", binomialTree);

    // Return the time 0 call price
    return binomialTree[0][0].optionPrice;
}

//---------------------------------------------------------------------------------------------------------
//Code for 1G
double EuropeanCallOption::BSMPrice() {

    double d_plus;
    double d_minus;
    double BSMPrice;

    d_plus = (log(S0/K) + (r + pow(sigma,2.0)/2.0)*T)/(sigma*pow(T,0.5));
    d_minus = d_plus - (sigma*pow(T,0.5));

    BSMPrice = ((1.0 + erf(d_plus / sqrt(2.0))) / 2.0)*S0 - K*exp(-r*T)*((1.0 + erf(d_minus / sqrt(2.0))) / 2.0);

    return BSMPrice;
}

//---------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// Code for 1 F

/* ---------------- EuropeanPutOption class definition ----------------- */
class EuropeanPutOption {
private:
    // Basic values of a stock option
    double S0;         // initial stock price
    double K;          // strike price
    double r;          // risk-free rate
    double sigma;      // volatility
    double T;          // expiration time
    // Inner class used by the binomial tree method
    class Price {
    public:
        double stockPrice;
        double optionPrice;
    };

    // a private helper function
    void put_BinomialTree(string header, const vector<vector<Price>>& bT);

public:
    // constructor defined inline within the class definition
    EuropeanPutOption(double s0, double k, double rfr,
                       double v, double et)
            : S0(s0), K(k), r(rfr), sigma(v), T(et)
    {}

    // Calculate the Price of the option
    // using the binomial tree method
    double binomialPrice(int numIntervals);

    // ... other pricing methods can be added here ...
    double BSMPrice();
};


/* ---------- EuropeanPutOption member function definition ----------- */

void EuropeanPutOption::put_BinomialTree(string header,
                                          const vector<vector<Price>>& bT)
{
    int N = (bT.size() == 0)
            ? 0
            : bT.size() - 1;

    if (N > 9) {  // if tree is too big, refuse to print anything
        // cout << header << "\n";
        // cout << "BinomialTree has " << N << " levels: too many to print!\n";
        return;
    }

    cout << "\n" << header << "\n\n";
    cout << "BinomialTree with " << N << " time steps:\n\n";
    for (int i(0); i < bT.size(); ++i) {
        cout << "Stock:  ";
        for (int j(0); j < bT[i].size(); ++j) {
            cout << setw(8) << bT[i][j].stockPrice;
        }
        cout << "\n";
        cout << "Option: ";
        for (int j(0); j < bT[i].size(); ++j) {
            cout << setw(8) << bT[i][j].optionPrice;
        }
        cout << "\n\n";
    }
    cout << "\n";
}


double EuropeanPutOption::binomialPrice(int numIntervals)
{
    // time interval length
    double deltaT  = T / numIntervals;;
    // factor by which stock price might rise at each step
    double u 	   = exp(sigma * sqrt(deltaT));
    // factor by which stock price might fall at each step
    double d 	   = 1 / u;
    // risk-free interest rate factor for one time interval
    double a	   = exp(r * deltaT);
    // RN probability of an up move in stock price
    double p	   = (a - d) / (u - d);
    // RN probability of a down move in stock price
    double q	   = 1.0 - p;
    // container for the binomialTree
    vector<vector<Price>> binomialTree;

    // put_BinomialTree("Initial, empty binomialTree:", binomialTree);

    // Build the shape of the binomialTree, by pushing
    // successively longer vector<Price> values (initially
    // all elements 0.0)
    for (int i(0); i <= numIntervals; ++i) {
        vector<Price> vInterval(i+1);    // i+1 {0.0,0.0} values
        binomialTree.push_back(vInterval);
    }
    put_BinomialTree("After filled in with all 0.0:", binomialTree);

    // Fill the stockPrice component of the binomialTree
    for (int i(0); i <= numIntervals; ++i)
        for (int j(0); j <= i; ++j)
            binomialTree[i][j].stockPrice =
                    S0 * pow(u, j) * pow(d, i-j);
    put_BinomialTree("After filled in with stock prices:", binomialTree);

    // Fill the optionPrices at the terminal nodes
    for (int j(0); j <= numIntervals; ++j) {
        binomialTree[numIntervals][j].optionPrice =
                max(-binomialTree[numIntervals][j].stockPrice + K,
                    0.0);
    }
    put_BinomialTree("After filled in with terminal option values:", binomialTree);

    // Now work backwards, filling optionPrices in the rest of the tree
    // Your code here

    //Code for 1 b
    //----------------------------------------------------------------------------------------------------
    for (int i = numIntervals-1; i >= 0; --i) {
        for (int j = i; j >= 0; --j) {
            binomialTree[i][j].optionPrice =
                    (p*binomialTree[i+1][j+1].optionPrice + q*binomialTree[i+1][j].optionPrice)*(1/a);

        }
    }
    //---------------------------------------------------------------------------------------------------



    put_BinomialTree("After filled in with all option values:", binomialTree);

    // Return the time 0 call price
    return binomialTree[0][0].optionPrice;
}

double EuropeanPutOption::BSMPrice() {

    double d_plus;
    double d_minus;
    double BSMPrice;

    d_plus = (log(S0/K) + (r + pow(sigma,2.0)/2.0)*T)/(sigma*pow(T,0.5));
    d_minus = d_plus - (sigma*pow(T,0.5));

    BSMPrice = -((1.0 + erf(-d_plus / sqrt(2.0))) / 2.0)*S0 + K*exp(-r*T)*((1.0 + erf(-d_minus / sqrt(2.0))) / 2.0);

    return BSMPrice;
}

//-----------------------------------------------------------------------------------------------------------


int main()
{
    EuropeanCallOption ec1(50.0,     // current stock price, S0
                           50.0,     // option strike price, K
                           0.10,     // risk-free rate
                           0.40,     // stock price volatility
                           0.4167);  // expiration time T (5 months)

    int N = 10;  // number of time intervals for Binomial Tree  ------- I changed here to 10 so it does not print the tree in the console

    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";

    //--------------------------------------------------------------------------------------
    //1 c
    //Adding with more steps to see if it converges

//    N=10;
//    cout << "Call price, with " << N << " intervals: "
//         << ec1.binomialPrice(N) << "\n";

    N=20;
    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";

    N=50;
    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";

    N=100;
    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";

    N=200;
    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";

    N=500;
    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";

    N=1000;
    cout << "Call price, with " << N << " intervals: "
         << ec1.binomialPrice(N) << "\n";



    //It does converge
    //    Call price, with 5 intervals: 6.35983
    //    Call price, with 10 intervals: 5.99123
    //    Call price, with 20 intervals: 6.05354
    //    Call price, with 50 intervals: 6.09138
    //    Call price, with 100 intervals: 6.10407
    //    Call price, with 200 intervals: 6.11042
    //    Call price, with 500 intervals: 6.11424
    //    Call price, with 1000 intervals: 6.11551

    //------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------
    //1 d

    cout << "\n \n";
    EuropeanCallOption ec12(5.0,     // current stock price, S0
                           5.0,     // option strike price, K
                           0.10,     // risk-free rate
                           0.40,     // stock price volatility
                           0.4167);  // expiration time T (5 months)

    N=1000;
    cout << "Call price, with " << N << " intervals - price 5, strike 5: "
         << ec12.binomialPrice(N) << "\n";

    EuropeanCallOption ec13(500.0,     // current stock price, S0
                            500.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.40,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    N=1000;
    cout << "Call price, with " << N << " intervals -- price 500, strike 500: "
         << ec13.binomialPrice(N) << "\n";


    //    Call price, with 1000 intervals - price 5, strike 5: 0.611551
    //    Call price, with 1000 intervals -- price 500, strike 500: 61.1551

    //The program works as expected -- if we change stock price and strike to the same number,
    // keeping all other variables we get an option price that change linearly with the stock and strike prices

    //--------------------------------------------------------------------------------------------------------
    // 1 e

    EuropeanCallOption ec14(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.05,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    N=1000;
    cout << "Call price, with " << N << " intervals and vol 0.05: "
         << ec14.binomialPrice(N) << "\n";

    EuropeanCallOption ec15(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.1,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Call price, with " << N << " intervals and vol 0.1: "
         << ec15.binomialPrice(N) << "\n";

    EuropeanCallOption ec16(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.4,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Call price, with " << N << " intervals and vol 0.4: "
         << ec16.binomialPrice(N) << "\n";

    EuropeanCallOption ec17(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.8,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Call price, with " << N << " intervals and vol 0.8: "
         << ec17.binomialPrice(N) << "\n";


    EuropeanCallOption ec18(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            1.6,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Call price, with " << N << " intervals and vol 1.6: "
         << ec18.binomialPrice(N) << "\n";


    //    Call price, with 1000 intervals and vol 0.05: 2.11384
    //    Call price, with 1000 intervals and vol 0.1: 2.53498
    //    Call price, with 1000 intervals and vol 0.4: 6.11551
    //    Call price, with 1000 intervals and vol 0.8: 11.0294
    //    Call price, with 1000 intervals and vol 1.6: 20.3493

    // We can see that option prices are not linear with the volatility as expected.

    //-------------------------------------------------------------------------------------------


    //Code for 1 F -- European Put

    EuropeanPutOption ep1(50.0,     // current stock price, S0
                           50.0,     // option strike price, K
                           0.10,     // risk-free rate
                           0.40,     // stock price volatility
                           0.4167);  // expiration time T (5 months)

    N=10;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";

    N=20;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";

    N=50;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";

    N=100;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";

    N=200;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";

    N=500;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";

    N=1000;
    cout << "Put price, with " << N << " intervals: "
         << ep1.binomialPrice(N) << "\n";
    //It does converge to the black-scholes value of the put
    //
    //    Put price, with 10 intervals: 3.95054
    //    Put price, with 20 intervals: 4.01285
    //    Put price, with 50 intervals: 4.0507
    //    Put price, with 100 intervals: 4.06338
    //    Put price, with 200 intervals: 4.06974
    //    Put price, with 500 intervals: 4.07355
    //    Put price, with 1000 intervals: 4.07483

    cout << "\n \n";
    EuropeanPutOption ep2(5.0,     // current stock price, S0
                            5.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.40,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    N=1000;
    cout << "Put price, with " << N << " intervals -- price 5, strike 5: "
         << ep2.binomialPrice(N) << "\n";

    EuropeanPutOption ep3(500.0,     // current stock price, S0
                            500.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.40,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Put price, with " << N << " intervals -- price 500, strike 500: "
         << ep3.binomialPrice(N) << "\n";

    //The program works as expected -- if we change stock price and strike to the same number,
    // keeping all other variables we get an option price that change linearly with the stock and strike prices

    //    Put price, with 1000 intervals -- price 5, strike 5: 0.407483
    //    Put price, with 1000 intervals -- price 500, strike 500: 40.7483


    EuropeanPutOption ep4(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.05,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    N=1000;
    cout << "Put price, with " << N << " intervals and vol 0.05: "
         << ep4.binomialPrice(N) << "\n";

    EuropeanPutOption ep5(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.1,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Put price, with " << N << " intervals and vol 0.1: "
         << ep5.binomialPrice(N) << "\n";

    EuropeanPutOption ep6(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.4,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Put price, with " << N << " intervals and vol 0.4: "
         << ep6.binomialPrice(N) << "\n";

    EuropeanPutOption ep7(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            0.8,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Put price, with " << N << " intervals and vol 0.8: "
         << ep7.binomialPrice(N) << "\n";


    EuropeanPutOption ep8(50.0,     // current stock price, S0
                            50.0,     // option strike price, K
                            0.10,     // risk-free rate
                            1.6,     // stock price volatility
                            0.4167);  // expiration time T (5 months)

    cout << "Put price, with " << N << " intervals and vol 1.6: "
         << ep8.binomialPrice(N) << "\n";

    //
    //    Put price, with 1000 intervals and vol 0.05: 0.07315
    //    Put price, with 1000 intervals and vol 0.1: 0.494297
    //    Put price, with 1000 intervals and vol 0.4: 4.07483
    //    Put price, with 1000 intervals and vol 0.8: 8.98873
    //    Put price, with 1000 intervals and vol 1.6: 18.3086

    // We can see that option prices are not linear with the volatility as expected.
    //------------------------------------------------------------------------------------------------------------


    //Code to test 1 G - BSMPrice
    //Price of the first call we saw in this program

    cout << "Call price, with BSM formula: "
         << ec1.BSMPrice() << "\n";

    //    Call price, with BSM formula: 6.11679

    //The price is close to the price calculated with the binomial tree.


    //------------------------------------------------------------------------------------------------------------
    //Test for 1 h
    cout << "Put price, with BSM formula: "
         << ep1.BSMPrice() << "\n";

    //    Put price, with BSM formula: 4.0761
    //The price is close to the price calculated with the binomial tree.

    //------------------------------------------------------------------------------------------------------------
    //Item 1 i
    // The prices of the binomial tree for large N converge to the ones in the online calculator.
    // The BSM price also converge to the online calculator price as expected.
    // We can see that the binomial tree is a very robust model and with a big number of steps it converges to the BSM price which has a more complex formulation
}
