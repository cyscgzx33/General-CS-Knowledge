#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


const double inflation = 1.03;
const double interest = 1.07;

double calInterest(double fund_per_year, int start_year, int end_year) {
    double funds = 0.0;
    for (int i = start_year; i <= end_year; i++) {
        funds *= interest;
        funds += fund_per_year;
        fund_per_year *= inflation;
        cout << "@year: " << i << ", funds = " << funds << endl; 
    }
    cout << "total funds between year " << start_year << " and year " << end_year << ": " << funds;
    cout << "\n---\n";
    return funds;
}


int main() {
    int year_0 = 2000;
    int year_1 = 2010;
    int year_2 = 2040;

    double fund_0 = 1000;
    double fund_1 = 1000 * pow(inflation, 10);

    double interest_0 = calInterest(fund_0, year_0, year_1);
    cout << "@year: " << year_2 << ", funds = " << interest_0 * pow(interest, 30) << endl;
    cout << "---\n";

    double interest_1 = calInterest(fund_1, year_1, year_2);

    return 0;
}

