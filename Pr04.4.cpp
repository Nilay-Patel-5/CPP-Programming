/*In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors the real-world operations of
various account types. The foundation of the system is a base class representing a generic bank account, encapsulating essential details
such as account number and balance. Building on this foundation, two specialized account types were created: a savings account, which includes an interest rate as an additional feature, and a current account, which allows an overdraft limit to accommodate specific customer needs.
To ensure proper initialization and cleanup of account objects, constructors and destructors were implemented. Essential banking operations
such as deposits and withdrawals were made available for both account types, allowing users to perform and manage their transactions
effectively. The system also accounted for the need to track and manage transaction history, enabling operations such as undoing the last
transaction. This was achieved by simulating a mechanism to store a sequence of transactions for each account type, providing insight into
different ways of managing and organizing data.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class BankAccount//Creating class
{
protected:
    //Protected data-members
    long AccNum;
    long Balance;

//Making public functions for different tasks
public:

    BankAccount()
    {
        AccNum = 0;
        Balance = 0;
    }

    void AddAccDetails()//Function for entering details of bank account
    {
        cout << "Enter account number: ";
        cin >> AccNum;//Taking input of account number
        cout << "Enter balance: ";
        cin >> Balance;

        cout << "Account addition successful!" << endl;//Printing message
    }

    void DepositMoney()//Function to deposit
    {
        //Variable declaration
        long Amount;

        cout << "Enter the amount to be deposited: ";
        cin >> Amount;//Taking input of amount to be deposited

        Balance += Amount;//The amount to be deposit in account

        cout << "Deposit successful!" << endl;//Printing message

        cout << "Current balance: " << Balance << endl;
    }

    void WithdrawMoney()//Function to withdraw
    {
        //Variable declaration
        long Amount;

        cout << "Enter the amount to be withdrawn: ";
        cin >> Amount;//Taking input of amount to be withdrawn

        if(Amount >= Balance)//If wanted amount of withdrawal is greater than balance....
        {
            cout << "Insufficient balance!" << endl;//Printing error message
        }

        else//If not....
        {
            Balance -= Amount;//The amount to be withdraw from account

            cout << "Withdrawal successful!" << endl;//Printing message

            cout << "Current balance: " << Balance << endl;
        }
    }

    inline long GetAccNum()//Function for returning the value of account number
    {
        return AccNum;//Return statement
    }

    inline long GetBalance()//Function for returning the value of account number
    {
        return Balance;//Return statement
    }

    inline void SetBalance(double Blnc)
    {
        Balance = Blnc;
    }
};

class SavingsAccount : public BankAccount//Creating class with parent class
{
    //Private data-member
    float InterestRate;

//Making public functions for different tasks
public:

    SavingsAccount() : BankAccount()
    {
        InterestRate = 0;
    }

    void ApplyInterest()
    {
        double Interest;

        cout << "Enter Interest Rate: ";
        cin >> InterestRate;

        Interest = GetBalance()*InterestRate/100;

        cout << "Applied interest: " << Interest << endl;
    }

    void DisplaySAccDetails()//Function for displaying account's details
    {
        cout << "Account number: " << GetAccNum() << endl;//Printing account no.
        cout<< "Current balance: " << GetBalance() << endl;//Printing current balance of account
        cout << "Interest rate: " << InterestRate << "%" << endl;
    }
};

class CurrentAccount : public BankAccount//Creating class with parent class
{
    //Private data-member
    long OverdraftLimit;

public:

    CurrentAccount() : BankAccount()
    {
        OverdraftLimit = 0;
    }

    void ApplyODLimit()
    {
        long Amount;

        cout << "Enter Overdraft Limit: ";
        cin >> OverdraftLimit;

        cout << "Enter amount to be withdrawn: ";
        cin >> Amount;

        if (Amount > GetBalance() + OverdraftLimit)
        {
            cout << "Invalid overdraft limit!"<< endl;
            return;
        }

        SetBalance(GetBalance() - Amount);
        cout << "Current balance:" << GetBalance() << endl;
    }

    void DisplayCAccDetails()//Function for displaying account's details
    {
        cout << "Account number: " << GetAccNum() << endl;//Printing account no.
        cout<< "Current balance: " << GetBalance() << endl;//Printing current balance of account
        cout << "Overdraft limit: " << OverdraftLimit << endl;
    }
};

int main()//Main function
{
    class SavingsAccount S[100];
    class CurrentAccount C[100];

    char Choice1;
    int Choice2,Choice3;
    int NumAcc1 = 0,NumAcc2 = 0;//Variables for tracking the no. of savings & current account & initializing to 0
    long AccFind;//Variable for matching account number
    bool Found;//Variable for signal if account no. matched

    cout << "Enter S to create Savings account." << endl;
    cout << "Enter C to create Current account." << endl;
    cout << "Enter E to exit." << endl;
    cout << "==================================" << endl;

    while(true)
    {
        cout << "Enter your choice: ";
        cin >> Choice1;

        switch(Choice1)
        {
        case 'S':
        {
            cout << "Enter 1 to add savings account's details." << endl;
            cout << "Enter 2 to deposit money." << endl;
            cout << "Enter 3 to withdraw money." << endl;
            cout << "Enter 4 to apply interest." << endl;
            cout << "Enter 5 to display account's details." << endl;

            cout << "Enter your choice: ";
            cin >> Choice2;

            Found = false;

            switch(Choice2)
            {
            case 1:

                S[NumAcc1].AddAccDetails();//Calling AddAccDetails function

                NumAcc1++;//Increment in NumAcc Variable

                break;//Break statement


            case 2:

            case 3:

            case 4:

            case 5:

                cout << "Enter the account number: ";
                cin >> AccFind;//Taking input of Account no. to search

                for (int i = 0; i < NumAcc1; i++)//Loop for matching Account no. with entered account no.
                {
                    if (S[i].GetAccNum() == AccFind)//If entered account no. matched with account no.
                    {
                        if (Choice2 == 2)
                        {
                            S[i].DepositMoney();
                        }

                        else if (Choice2 == 3)
                        {
                            S[i].WithdrawMoney();
                        }

                        else if (Choice2 == 4)
                        {
                            S[i].ApplyInterest();
                        }

                        else if (Choice2 == 5)
                        {
                            S[i].DisplaySAccDetails();
                        }

                        Found = true;//Account no. matched with entered account no.

                        break;//Break statement
                    }
                }

                if(! Found)//If Found variable doesn't switch to true...
                {
                    cout << "Account not found!" << endl;//Printing error message
                }

                break;

            default:

                cout << "Invalid input!" << endl;

                break;//Break statement
            }
            break;//Break statement
        }

        case 'C':
        {
            cout << "Enter 1 to add current account's details." << endl;
            cout << "Enter 2 to deposit money." << endl;
            cout << "Enter 3 to withdraw money." << endl;
            cout << "Enter 4 to display account's details." << endl;

            cout << "Enter your choice: ";
            cin >> Choice3;

            Found = false;

            switch(Choice3)
            {
            case 1:

                C[NumAcc2].AddAccDetails();//Calling AddAccDetails function

                NumAcc2++;//Increment in NumAcc Variable

                break;//Break statement

            case 2:

            case 3:

            case 4:

                cout << "Enter the account number: ";
                cin >> AccFind;//Taking input of Account no. to search

                for (int i = 0; i < NumAcc2; i++)//Loop for matching Account no. with entered account no.
                {
                    if (C[i].GetAccNum() == AccFind)//If entered account no. matched with account no.
                    {
                        if (Choice3 == 2)
                        {
                            C[i].DepositMoney();
                        }

                        else if (Choice3 == 3)
                        {
                            C[i].ApplyODLimit();
                        }

                        else if (Choice3 == 4)
                        {
                            C[i].DisplayCAccDetails();
                        }

                        Found = true;//Account no. matched with entered account no.

                        break;//Break statement
                    }
                }

                if(! Found)//If Found variable doesn't switch to true...
                {
                    cout << "Account not found!" << endl;//Printing error message
                }

                break;//Break statement


            default:

                cout << "Invalid input!" << endl;

                break;//Break statement
            }
            break;//Break statement
        }

            case 'E':
                {
                    cout << "24CE089_NILAY PATEL." << endl;

                    return 0;
                }

        default:
            {
                cout << "Invalid input!" << endl;

                break;//Break statement
            }
        }
    }
}
