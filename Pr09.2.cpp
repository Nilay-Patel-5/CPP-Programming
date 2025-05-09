/*Imagine you are tasked with developing a simple banking system for a local financial institution. The bank has observed an
increase in customer complaints regarding unclear transaction records and not handled errors during operations. They want a robust
software module to manage bank accounts efficiently while maintaining a log of transactions.
As a software developer, your job is to create a banking system with the following features:
1. A way to represent individual bank accounts, including the ability to manage their balances.
2. Secure methods to deposit and withdraw funds.
3. An error-handling mechanism to address invalid operations, such as attempting to withdraw more than the account's current
balance.
4. A feature that logs every function call when an error occurs to provide insights into the issue.
The bank also insists on maintaining a history of transactions using basic data structures without relying on advanced libraries
or containers. Design and implement a banking system that fulfills the above requirements.*/

//This Program is prepared by 24CE089_NILAY PATEL

#include <iostream>//Standard Input/Output stream
#include <string>//String class for using string data-type
#include <stdexcept>//For using standard exceptions

using namespace std;

class BankAccount//Creating class
{
    //Private data-members
    string Name;
    double Balance;
    string* History;
    int Capacity;
    int Count;

    //Private function for logging each transaction
    void LogTransaction(const string& Entry)
    {
        if (Count == Capacity)//If the array is full, increasing its size
        {
            int NewCapacity = Capacity * 2;//Double the capacity
            string* NewHistory = new string[NewCapacity];//Creating new array

            for (int i = 0; i < Count; ++i)//Copying old entries
            {
                NewHistory[i] = History[i];
            }

            delete[] History;//Deleting old history array
            History = NewHistory;//Pointing to new array
            Capacity = NewCapacity;//Updating capacity
        }

        History[Count++] = Entry;//Adding new entry and increase count
    }
//Making public functions for different tasks
public:

    //Constructor to initialize account with name and optional balance
    BankAccount(string AccName, double InitialBalance = 0)
    {
        Name = AccName;//Assigning account holder's name
        Balance = InitialBalance;//Assigning initial balance
        Capacity = 10;//Initializing capacity of history array
        Count = 0; //Initializing count of history entries
        History = new string[Capacity];//Allocating memory

        LogTransaction("Account created with Balance: " + to_string(Balance));//Logging account creation
    }

    ~BankAccount()//Destructor to free memory
    {
        delete[] History;//Freeing allocated memory
    }

    void Deposit(double Amount)//Function for depositing money into the account
    {
        if (Amount <= 0)//If entered amount is invalid...
        {
            LogTransaction("Invalid Deposit attempt: " + to_string(Amount));//Logging invalid attempt
            throw invalid_argument("Deposit amount must be positive.");//Throwing error
        }

        Balance += Amount;//Adding amount to balance
        LogTransaction("Deposited: " + to_string(Amount));//Logging deposit
    }

    void Withdraw(double Amount)//Function for withdrawing money from the account
    {
        if (Amount <= 0)//If entered amount is invalid...
        {
            LogTransaction("Invalid Withdrawal attempt: " + to_string(Amount));//Logging invalid attempt
            throw invalid_argument("Withdrawal amount must be positive.");//Throwing error
        }

        if (Amount > Balance)//If balance is insufficient...
        {
            LogTransaction("Failed Withdrawal (insufficient funds): " + to_string(Amount));//Logging failure
            throw runtime_error("Insufficient funds.");//Throwing error
        }

        Balance -= Amount;//Deducting amount from balance
        LogTransaction("Withdrawn: " + to_string(Amount));//Logging withdrawal
    }


    void DisplayBalance() const//Function for displaying current balance
    {
        cout << "Current Balance: Rs." << Balance << endl;//Displaying current balance
    }


    void DisplayHistory() const//Function for displaying transaction history
    {
        cout << "\nTransaction History for " << Name << ":\n";//Displaying transaction history title

        for (int i = 0; i < Count; ++i)//Looping through transaction records
        {
            cout << i + 1 << ". " << History[i] << endl;//Displaying each entry
        }
    }
};

int main()//Main function
{
    BankAccount Acc("NILAY PATEL", 5555);//Creating object with initial balance

    try//Try block for performing transactions
    {
        Acc.Deposit(500);//Depositing money
        Acc.Withdraw(200);//Withdrawing money
        Acc.Withdraw(2000);//Attempting to withdraw more than balance
    }
    catch (const exception& E)//Catch block to handle exceptions
    {
        cout << "Error: " << E.what() << endl;//Displaying error message
    }

    Acc.DisplayBalance();//Calling function to display balance
    Acc.DisplayHistory();//Calling function to display transaction history

    cout << "\n24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
