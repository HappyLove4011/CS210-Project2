#pragma once
#include <string> // Include the string library for using std::string

class BankAccount {
private:
    // Private member variables to store investment details
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

public:
    // Constructor to initialize member variables
    BankAccount();

    // Input validation functions
    int getValidInt(const std::string& prompt);
    double getValidPercentage(const std::string& prompt);
    double getValidDouble(const std::string& prompt);

    // Setter function for input data
    void SetData(double initInvest, double monthDep, double annInterest, int years);

    // Functions to calculate and display reports
    void CalculateWithoutDeposits();
    void CalculateWithDeposits();
    void DisplayReport();
};