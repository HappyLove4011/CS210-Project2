#include <iostream> // For input/output operations
#include <string>   // For formatting output (e.g., setw, setprecision)
#include <cstdlib>  // For exit()
#include <iomanip>  // For formatting output
using namespace std;

#include "BankAccount.h" // Include the header file for the BankAccount class

// Constructor: Initialize member variables to default values
BankAccount::BankAccount() {
    initialInvestment = 0;
    monthlyDeposit = 0;
    annualInterest = 0;
    numYears = 0;
}

// Function to validate and return a positive double input
// use const and & to pass a reference to the original string rather than making a copy, saving memory
double BankAccount::getValidDouble(const string& prompt) {
    double value;
    cout << prompt;
    cin >> value;

    // Check for invalid input or non-positive numbers
    if (cin.fail() || value < 0) {
        cout << "Invalid input. Program will now exit.\n";
        exit(EXIT_FAILURE);  // Exit the program if input is invalid
    }

    return value;
}

// Function to validate and return a percentage input (0-100)
// use const and & to pass a reference to the original string rather than making a copy, saving memory
double BankAccount::getValidPercentage(const string& prompt) {
    double value;
    cout << prompt;
    cin >> value;

    // Check for invalid input or percentage out of range
    if (cin.fail() || value < 0 || value > 100) {
        cout << "Invalid input. Program will now exit.\n";
        exit(EXIT_FAILURE);
    }

    return value;
}

// Function to validate and return a positive integer input
// use const and & to pass a reference to the original string rather than making a copy, saving memory
int BankAccount::getValidInt(const string& prompt) {
    int value;
    cout << prompt;
    cin >> value;

    // Check for invalid input or non-positive integers
    if (cin.fail() || value < 0) {
        cout << "Invalid input. Program will now exit.\n";
        exit(EXIT_FAILURE); // Exit the program if input is invalid
    }

    return value;
}


// Function to set user input values in the object (used in main.cpp)
void BankAccount::SetData(double initInvest, double monthDep, double annInterest, int years) {
    initialInvestment = initInvest;  // Set initial investment amount
    monthlyDeposit = monthDep;       // Set monthly deposit amount
    annualInterest = annInterest;    // Set annual interest rate
    numYears = years;                // Set the number of years for the investment
}

// Function to calculate and display investment growth without monthly deposits
void BankAccount::CalculateWithoutDeposits() {
    double balance = initialInvestment;  // Start with the initial investment
    double monthlyInterestRate = annualInterest / 100 / 12;  // Convert annual interest to monthly rate

    // Display the report header
    cout << "\nBalance without additional monthly deposits:\n";
    cout << "==============================================\n";
    cout << setw(5) << "Year" << setw(20) << "Year End Balance" << setw(20) << "Year End Interest" << "\n";
    cout << "----------------------------------------------\n";

    // Loop through each year
    for (int year = 1; year <= numYears; year++) {
        double yearlyInterest = 0;  // Reset yearly interest for each year

        // Loop through each month
        for (int month = 1; month <= 12; month++) {
            double monthlyInterest = balance * monthlyInterestRate;  // Calculate monthly interest
            balance += monthlyInterest;  // Add interest to the balance
            yearlyInterest += monthlyInterest;  // Accumulate yearly interest
        }

        // Display the year-end balance and interest
        cout << setw(5) << year << setw(20) << "$" << fixed << setprecision(2) << balance << setw(20) << "$" << yearlyInterest << "\n";
    }
}

// Function to calculate and display investment growth with monthly deposits
void BankAccount::CalculateWithDeposits() {
    double balance = initialInvestment;  // Start with the initial investment
    double monthlyInterestRate = annualInterest / 100 / 12;  // Convert annual interest to monthly rate

    // Display the report header
    cout << "\nBalance with additional monthly deposits:\n";
    cout << "==============================================\n";
    cout << setw(5) << "Year" << setw(20) << "Year End Balance" << setw(20) << "Year End Interest" << "\n";
    cout << "----------------------------------------------\n";

    // Loop through each year
    for (int year = 1; year <= numYears; year++) {
        double yearlyInterest = 0;  // Reset yearly interest for each year

        // Loop through each month
        for (int month = 1; month <= 12; month++) {
            balance += monthlyDeposit;  // Add monthly deposit to the balance
            double monthlyInterest = balance * monthlyInterestRate;  // Calculate monthly interest
            balance += monthlyInterest;  // Add interest to the balance
            yearlyInterest += monthlyInterest;  // Accumulate yearly interest
        }

        // Display the year-end balance and interest
        cout << setw(5) << year << setw(20) << "$" << fixed << setprecision(2) << balance << setw(20) << "$" << yearlyInterest << "\n";
    }
}

// Function to display the user's input data
void BankAccount::DisplayReport() {
    cout << "\nInvestment Report:\n";
    cout << "==============================================\n";
    cout << "Initial Investment: $" << fixed << setprecision(2) << initialInvestment << "\n";
    cout << "Monthly Deposit: $" << monthlyDeposit << "\n";
    cout << "Annual Interest Rate: " << annualInterest << "%\n";
    cout << "Number of Years: " << numYears << "\n";
    cout << "==============================================\n";
}