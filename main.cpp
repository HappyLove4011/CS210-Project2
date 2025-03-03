#include <iostream>
#include "BankAccount.h"
using namespace std;



int main() {
    // create an instance of bank account object
    BankAccount myAccount;

    double initialInvestment, monthlyDeposit, annualInterest;
    int numYears;

    // Get validated user input data
    initialInvestment = myAccount.getValidDouble("Enter your initial investment amount: ");
    monthlyDeposit = myAccount.getValidDouble("Enter your monthly deposit: ");
    annualInterest = myAccount.getValidPercentage("Enter the annual interest rate (0-100): ");
    numYears = myAccount.getValidInt("Enter the number of years: ");


    // Set data in the BankAccount object
    myAccount.SetData(initialInvestment, monthlyDeposit, annualInterest, numYears);

    // Display the input data
    myAccount.DisplayReport();

    // Calculate and display reports
    myAccount.CalculateWithoutDeposits();
    myAccount.CalculateWithDeposits();

    cout << "\nThank you for using the Airgead Banking App!\n";

    return 0;

}