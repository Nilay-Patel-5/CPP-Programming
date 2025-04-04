/*A bank wants to create a simple system to manage customer bank accounts. The system should allow customers to perform basic banking operations such as
depositing money, withdrawing money, and checking their account balance. Each bank account will need to have an account holder's name, a unique account
number, and a balance.
Deposits should increase the account balance, while withdrawals should only be allowed if there are sufficient funds in the account. If an attempt is made
to withdraw more money than is available, an error message should be displayed. Customers should also have the ability to view their account balance
whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on creating a simple and efficient solution to manage the accounts
effectively. The system should ensure that all account details are secure and accessible only through authorized methods.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class BankAccount//Creating class
{
    //Private data-members
    char AccHolderName[10];
    long Balance;
    long AccNum;

//Making public functions for different tasks
public:

    void AddAccDetails()//Function for entering details of bank account
    {
        cout << "Enter the account holder's name: ";
        cin >> AccHolderName;//Taking input of account holder's name
        cout << "Enter the account number: ";
        cin >> AccNum;//Taking input of account number

        Balance = 1000;

        cout << "Account addition successful!" << endl;//Printing message
    }

    inline int GetAccNum()//Function for returning the value of account number
    {
        return AccNum;//Return statement
    }

    void DepositMoney()//Function to deposit
    {
        //Variable declaration
        long Amount;

        cout << "Enter the amount to be deposited: ";
        cin >> Amount;//Taking input of amount to be deposited

        Balance += Amount;//The amount to be deposit in account

        cout << "Deposit successful!" << endl;//Printing message
    }

    void WithdrawMoney()//Function to withdraw
    {
        //Variable declaration
        long Amount;

        cout << "Enter the amount to be withdrawn: ";
        cin >> Amount;//Taking input of amount to be withdrawn

        if(Amount > Balance-1000)//If wanted amount of withdrawal is greater than balance....
        {
            cout << "Insufficient balance!" << endl;//Printing error message
        }

        else//If not....
        {
            Balance -= Amount;//The amount to be withdraw from account

            cout << "Withdrawal successful!" << endl;//Printing message
        }
    }

    void DisplayAccBalance()//Function for displaying balance
    {
        cout<< "Current balance: " << Balance << endl;//Printing current balance
    }
};

int main()//Main function
{
    class BankAccount Acc[100];//Creating object

    long AccFind;//Variable for matching account number
    int Choice;//Variable for choice
    int NumAcc = 0;//Variable for tracking the no. of account & initializing to 0

    //Printing menu
    cout << "Enter 1 to add account details." << endl;
    cout << "Enter 2 to deposit." << endl;
    cout << "Enter 3 to withdraw." << endl;
    cout << "Enter 4 to display current balance." << endl;
    cout << "Else to Exit." << endl;
    cout << "===================================" << endl;

    while(true)//Loop for doing various tasks
    {
        cout << "Enter the option which you want: ";
        cin >> Choice;//Taking input of choice

        bool Found = false;//Variable for signal if account no. matched

        switch (Choice)//Switch case
        {
        case 1://Case for adding account details
        {
            Acc[NumAcc].AddAccDetails();//Calling AddAccDetails function
            NumAcc++;//Increment in NumAcc Variable

            break;//Break statement
        }

        case 2://Case for depositing money
        {
            cout << "Enter the account number: ";
            cin >> AccFind;//Taking input of Account no. to search

            for (int i = 0; i < NumAcc; i++)//Loop for matching account no. with entered account no.
            {
                if (Acc[i].GetAccNum() == AccFind)//If entered account matched with account no.
                {
                    Acc[i].DepositMoney();//Calling DepositMoney function

                    Found = true;//Account no. matched with entered account no.

                    break;//Break statement
                }
            }

            if(! Found)//If not...
            {
                cout << "Account not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        case 3://Case for withdrawing money
        {
            cout << "Enter the account number: ";
            cin >> AccFind;//Taking input of Account no. to search

            for (int i = 0; i < NumAcc; i++)//Loop for matching Account no. with entered account no.
            {
                if (Acc[i].GetAccNum() == AccFind)//If entered account matched with account no.
                {
                    Acc[i].WithdrawMoney();//Calling WithdrawMoney function

                    Found = true;//Account no. matched with entered account no.

                    break;//Break statement
                }
            }

            if(! Found)//If not...
            {
                cout << "Account not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        case 4://Case for displaying current balance
        {
            cout << "Enter the account number: ";
            cin >> AccFind;//Taking input of Account no. to search

            for (int i = 0; i < NumAcc; i++)//Loop for matching Account no. with entered account no.
            {
                if (Acc[i].GetAccNum() == AccFind)//If entered account matched with account no.
                {
                    Acc[i].DisplayAccBalance();//Calling DisplayAccBalance function

                    Found = true;//Account no. matched with entered account no.

                    break;//Break statement
                }
            }

            if(! Found)//If not...
            {
                cout << "Account not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        default://Default Case
        {
            cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

            return 0;//Return statement
        }
        }
    }
}
