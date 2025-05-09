/*Imagine you're developing a financial calculator for a bank's system that allows users to calculate the ratio of two monetary
values they input. This tool must be reliable, as it's part of a crucial decision-making process for loan eligibility.
A bank customer is required to enter two values directly into the system:
1. The first value represents the total loan amount they wish to apply for.
2. The second value represents their annual income.
The system will compute and display the ratio of the loan amount to the income, which helps the bank assess the customer's
loan-to-income ratio.
Major challenges that developer will face while developing the system would be, if the customer mistakenly enters non-numerical
characters (e.g., "abc"), the system should handle the situation gracefully and prompt the user to correct their input. If the
customer enters 0 as their annual income, the system must identify this issue and avoid performing a division that would lead to
an invalid result.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream> //Standard Input/Output library
#include <string>//For using string type
#include <stdexcept>//For exception handling
#include <sstream>//For string stream to convert string to double

using namespace std;

double ConvertToDouble(const string& InputString)//Function for converting string to double
{
    stringstream SS(InputString);//Creating string stream object

    double Value;//Variable for storing the converted double
    SS >> Value;//Converting input string to double

    if (SS.fail() || !SS.eof())//If conversion failed or extra characters remain...
    {
        throw invalid_argument("Invalid numerical input.");//Throwing exception
    }
    return Value;//Returning the converted value
}

int main()//Main function
{
    //Variable declaration
    string LoanAmountStr, AnnualIncomeStr;//String variables to take input
    double LoanAmount, AnnualIncome;//Double variables for calculation

    try//Try block for exception handling
    {
        cout << "Enter the loan amount: ";
        getline(cin, LoanAmountStr);//Taking input of loan amount
        LoanAmount = ConvertToDouble(LoanAmountStr);//Converting to double

        cout << "Enter the annual income: ";
        getline(cin, AnnualIncomeStr);//Taking input of annual income
        AnnualIncome = ConvertToDouble(AnnualIncomeStr);//Converting to double

        if (AnnualIncome == 0)//Checking for zero income
        {
            throw runtime_error("Error: Annual income cannot be zero.");//Throwing exception
        }

        double Ratio = LoanAmount / AnnualIncome;//Calculating loan-to-income ratio

        cout << "The loan-to-income ratio is: " << Ratio << endl;//Displaying ratio
    }
    catch (const invalid_argument& E)//Catch block for invalid input
    {
        cout << "Error: " << E.what() << endl;//Displaying error message
    }
    catch (const runtime_error& E)//Catch block for runtime error
    {
        cout << "Error: " << E.what() << endl;//Displaying error message
    }
    catch (...)//Catch-all block for unexpected errors
    {
        cout << "An unexpected error occurred." << endl;//Displaying generic error
    }

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

