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

    int GetAccNum()//Function for returning the value of account number
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

        if(Amount >= Balance-1000)//If wanted amount of withdrawal is greater than balance....
        {
            cout << "Insufficient balance!" << endl;//Printing error message
        }

        else//If not....
        {
            Balance -= Amount;//The amount to be withdraw from account
            cout << "Withdrawal successful!" << endl;//Printing message
        }
    }

    void DisplayAccDetails()//Function for displaying account's details
    {
        cout << "Account holder's name: " << AccHolderName << endl;//Printing account holder's name
        cout << "Account number: " << AccNum << endl;//Printing account no.
        cout<<"Current balance: "<< Balance <<endl;//Printing current balance of account
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

next :
    cout << "Enter the option which you want: ";
    cin >> Choice;//Taking input of choice

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

        for (int i = 0; i < NumAcc; i++)//Loop for matching Account no. with entered account no.
        {
            if (Acc[i].GetAccNum() == AccFind)//If entered account no. matched with account no.
            {
                Acc[i].DepositMoney();//Calling DepositMoney function
                break;//Break statement
            }

            else//If not...
            {
                cout << "Account not found!" << endl;//Printing error message
                break;//Break statement
            }
        }
        break;//Break statement
    }

    case 3://Case for withdrawing money
    {
        cout << "Enter the account number: ";
        cin >> AccFind;//Taking input of Account no. to search

        for (int i = 0; i < NumAcc; i++)//Loop for matching Account no. with entered account no.
        {
            if (Acc[i].GetAccNum() == AccFind)//If entered account no. matched with account no.
            {
                Acc[i].WithdrawMoney();//Calling WithdrawMoney function
                break;//Break statement
            }

            else//If not...
            {
                cout << "Account not found!" << endl;//Printing error message
                break;//Break statement
            }
        }
        break;//Break statement
    }

    case 4://Case for displaying account's details
    {
        cout << "Enter the account number: ";
        cin >> AccFind;//Taking input of Account no. to search

        for (int i = 0; i < NumAcc; i++)//Loop for matching Account no. with entered account no.
        {
            if (Acc[i].GetAccNum() == AccFind)//If entered account no. matched with account no.
            {
                Acc[i].DisplayAccDetails();//Calling DisplayAccDetails function
                break;//Break statement
            }

            else//If not...
            {
                cout << "Account not found!" << endl;//Printing error message
                break;//Break statement
            }
        }
        break;//Break statement
    }

    default://Default Case
    {
        cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
        return 0;//Return statement
    }

    }
    goto next;//Goto statement
}
