/*In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors the real-world operations of various account
types. The foundation of the system is a base class representing a generic bank account, encapsulating essential details such as account number and balance.
Building on this foundation, two specialized account types were created: a savings account, which includes an interest rate as an additional feature, and a
current account, which allows an overdraft limit to accommodate specific customer needs.
To ensure proper initialization and cleanup of account objects, constructors and destructors were implemented. Essential banking operations such as deposits
and withdrawals were made available for both account types, allowing users to perform and manage their transactions effectively. The system also accounted
for the need to track and manage transaction history, enabling operations such as undoing the last transaction. This was achieved by simulating a mechanism
to store a sequence of transactions for each account type, providing insight into
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

    BankAccount()//Constructor of BankAccount class
    {
        //Initializing data members with default value
        AccNum = 0;
        Balance = 0;
    }

    virtual ~BankAccount()//Virtual destructor
    {
    }

    virtual void DisplayAccountDetails() = 0;//Virtual function

    void AddAccDetails()//Function for entering details of bank account
    {
        cout << "Enter account number: ";
        cin >> AccNum;//Taking input of account number
        cout << "Enter balance: ";
        cin >> Balance;//Taking input of balance

        cout << "Account addition successful!" << endl;//Printing message
    }

    void DepositMoney()//Function to deposit
    {
        long Amount;//Variable for amount to be deposited

        cout << "Enter the amount to be deposited: ";
        cin >> Amount;//Taking input of amount to be deposited

        Balance += Amount;//The amount to be deposit in account

        cout << "Deposit successful!" << endl;//Printing message

        cout << "Current balance: " << Balance << endl;//Printing balance
    }

    void WithdrawMoney()//Function to withdraw
    {

        long Amount;//Variable for amount to be withdrawn

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

            cout << "Current balance: " << Balance << endl;//Printing balance
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

    inline void SetBalance(double Blnc)//Function for storing value of balance
    {
        Balance = Blnc;//storing value of balance
    }
};

class SavingsAccount : public BankAccount//Creating class with parent class
{
    //Private data-member
    float InterestRate;

//Making public functions for different tasks
public:

    SavingsAccount() : BankAccount()//Constructor of Person class with a constructor of parent
    {
        //Initializing data members with default value
        InterestRate = 0;
    }

    void ApplyInterest()//Function for applying interest
    {
        double Interest;//Variable for interest

        cout << "Enter Interest Rate: ";
        cin >> InterestRate;//Talking input of interest

        Interest = GetBalance()*InterestRate/100;//Calculating interest

        cout << "Applied interest: " << Interest << endl;//Printing interest
    }

    void DisplaySAccDetails()//Function for displaying account's details
    {
        cout << "Account number: " << GetAccNum() << endl;//Printing account no.
        cout<< "Current balance: " << GetBalance() << endl;//Printing current balance of account
        cout << "Interest rate: " << InterestRate << "%" << endl;//Printing interest rate
    }

    void DisplayAccountDetails() override//Function for overriding DisplayAccountDetails function
    {
        DisplaySAccDetails();//Calling DisplaySAccDetails
    }

    ~SavingsAccount() override//Overriding destructor
    {
    }
};

class CurrentAccount : public BankAccount//Creating class with parent class
{
    //Private data-member
    long OverdraftLimit;

public:

    CurrentAccount() : BankAccount()//Constructor of Person class with a constructor of parent
    {
        //Initializing data members with default value
        OverdraftLimit = 0;
    }

    void ApplyODLimit()//Function for applying overdraft-limit
    {
        long Amount;//Variable for amount to be overdrafted

        cout << "Enter Overdraft Limit: ";
        cin >> OverdraftLimit;//Taking input of overdraft-limit

        cout << "Enter amount to be withdrawn: ";
        cin >> Amount;//Taking input of amount to be withdrawn

        if (Amount > GetBalance() + OverdraftLimit)//If
        {
            cout << "Invalid overdraft limit!"<< endl;//Printing error message
            return;//Return statement
        }

        SetBalance(GetBalance() - Amount);//Substituting Amount from Balance
        cout << "Current balance:" << GetBalance() << endl;//Printing balnce
    }

    void DisplayCAccDetails()//Function for displaying account's details
    {
        cout << "Account number: " << GetAccNum() << endl;//Printing account no.
        cout<< "Current balance: " << GetBalance() << endl;//Printing current balance of account
        cout << "Overdraft limit: " << OverdraftLimit << endl;
    }

    void DisplayAccountDetails() override//Function for overriding DisplayAccountDetails function
    {
        DisplayCAccDetails();//Calling DisplayCAccDetails function
    }

    ~CurrentAccount() override//Overriding destructor
    {
    }
};

int main()//Main function
{
    //Creating objects
    class SavingsAccount* S[100];
    class CurrentAccount* C[100];

    char Choice1;//Variables for choices
    int Choice2,Choice3;//Variables for choices
    int NumAcc1 = 0,NumAcc2 = 0;//Variables for tracking the no. of savings & current account & initializing to 0
    long AccFind;//Variable for matching account number
    bool Found;//Variable for signal if account no. matched

    //Displaying menu
    cout << "Enter S for Savings account." << endl;
    cout << "Enter C for Current account." << endl;
    cout << "Enter E to exit." << endl;
    cout << "==================================" << endl;

    while(true)//Loop for different tasks on savings account & Current current
    {
        cout << "Enter your choice: ";
        cin >> Choice1;//Taking input of Choice1

        switch(Choice1)//Switch case
        {
        case 'S'://Case for savings account
        {
            //Displaying menu
            cout << "Enter 1 to add savings account's details." << endl;
            cout << "Enter 2 to deposit money." << endl;
            cout << "Enter 3 to withdraw money." << endl;
            cout << "Enter 4 to apply interest." << endl;
            cout << "Enter 5 to display account's details." << endl;

            cout << "Enter your choice: ";
            cin >> Choice2;//Taking input of Choice2

            Found = false;//Variable for signal if account no. matched

            switch(Choice2)//Switch case
            {
            case 1://Case for adding savings account's details

                S[NumAcc1] = new SavingsAccount();//Calling AddAccDetails function

                S[NumAcc1]->AddAccDetails();//Calling AddAccDetails function

                NumAcc1++;//Increment in NumAcc Variable

                break;//Break statement


            case 2://Case for depositing money

            case 3://Case for withdrawing money

            case 4://Case for applying interest

            case 5://Case for displaying account's details

                cout << "Enter the account number: ";
                cin >> AccFind;//Taking input of Account no. to search

                for (int i = 0; i < NumAcc1; i++)//Loop for matching Account no. with entered account no.
                {
                    if (S[i]->GetAccNum() == AccFind)//If entered account no. matched with account no.
                    {
                        if (Choice2 == 2)//If Choice2 is equal to 2
                        {
                            S[i]->DepositMoney();//Calling DepositMoney function
                        }

                        else if (Choice2 == 3)//If Choice2 is equal to 3
                        {
                            S[i]->WithdrawMoney();//Calling WithdrawMoney function
                        }

                        else if (Choice2 == 4)//If Choice2 is equal to 4
                        {
                            S[i]->ApplyInterest();//Calling ApplyInterest function
                        }

                        else if (Choice2 == 5)//If Choice2 is equal to 5
                        {
                            S[i]->DisplaySAccDetails();//Calling DisplaySAccDetails function
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

                cout << "Invalid input!" << endl;//Printing error message

                break;//Break statement
            }
            break;//Break statement
        }

        case 'C'://Case for current account
        {
            //Displaying menu
            cout << "Enter 1 to add current account's details." << endl;
            cout << "Enter 2 to deposit money." << endl;
            cout << "Enter 3 to withdraw money." << endl;
            cout << "Enter 4 to display account's details." << endl;

            cout << "Enter your choice: ";
            cin >> Choice3;//Taking input of choice

            Found = false;//Variable for signal if account no. matched

            switch(Choice3)//Switch case
            {
            case 1://Case for adding current account's details

                C[NumAcc2] = new CurrentAccount();//Creating object by dynamic allocation

                C[NumAcc2]->AddAccDetails();//Calling AddAccDetails function

                NumAcc2++;//Increment in NumAcc Variable

                break;//Break statement

            case 2://Case for depositing money

            case 3://Case for withdrawing money

            case 4://Case for displaying account's details

                cout << "Enter the account number: ";
                cin >> AccFind;//Taking input of Account no. to search

                for (int i = 0; i < NumAcc2; i++)//Loop for matching Account no. with entered account no.
                {
                    if (C[i]->GetAccNum() == AccFind)//If entered account no. matched with account no.
                    {
                        if (Choice3 == 2)//If Choice3 is equal to 3
                        {
                            C[i]->DepositMoney();//Calling DepositMoney function
                        }

                        else if (Choice3 == 3)//If Choice3 is equal to 3
                        {
                            C[i]->ApplyODLimit();//Calling ApplyODLimit function
                        }

                        else if (Choice3 == 4)//If Choice3 is equal to 4
                        {
                            C[i]->DisplayCAccDetails();//Calling DisplayCAccDetails function
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


            default://Default case

                cout << "Invalid input!" << endl;//Printing error message

                break;//Break statement
            }
            break;//Break statement
        }

        case 'E'://Case for exiting
        {
            for (int i = 0; i < NumAcc1; i++)//Loop for deleting array
            {
                delete S[i];//Free up S named array of pointer
            }

            for (int i = 0; i < NumAcc2; i++)//Loop for deleting array
            {
                delete C[i];//Free up C named array of pointer
            }

            cout << "24CE089_NILAY PATEL." << endl;//Printing existing message

            return 0;//Return statement
        }

        default://Default case
        {
            cout << "Invalid input!" << endl;//Printing error message

            break;//Break statement
        }
        }
    }
}
