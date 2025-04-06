/*A community bank sought to enhance its account management system with a digital solution to improve efficiency and provide better customer service. The
system was required to manage the essential details of each account, including the account number, account holder’s name, and balance. Additionally, the
bank wanted to provide a secure mechanism for transferring money between accounts, allowing customers to easily manage their funds.
The bank also needed a way to track the total number of accounts created, which would be important for generating reports and understanding the growth of
their customer base. This feature was aimed at helping the bank maintain an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store account information in a way that would allow easy access and updates. When new
accounts were created, they would be added to the system dynamically. The management team planned for future scalability and performance improvements by
considering more efficient storage and retrieval methods after the initial system was built, ensuring that the bank could easily accommodate more accounts
and transactions as the customer base grew.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class BankAccount//Creating class
{
    //Private data-members
    char AccHolderName[20];
    long long Balance;
    long AccNum;

//Making public functions for different tasks
public:

    void AddAccDetails()//Function for entering details of bank account
    {
        cout << "Enter the account number: ";
        cin >> AccNum;//Taking input of account number
        cout << "Enter the account holder's name: ";
        cin >> AccHolderName;//Taking input of account holder's name
        cout << "Enter the account balance: ";//Taking input of balance
        cin >> Balance;//Taking input of balance

        cout << "Account addition successful!" << endl;//Printing message
    }

    void DisplayAccDetails()//Function for displaying account's details
    {
        cout << "Account's details:" << endl;
        cout << "Account no. : " << AccNum << endl;//Printing account no.
        cout << "Account holder's name: " << AccHolderName << endl;//Printing account holder's name
        cout << "Current balance: "<< Balance << endl;//Printing current balance of account
    }

    inline long GetAccNum()//Function for returning the value of account number
    {
        return AccNum;//Return statement
    }

    inline long long GetBalance()//Function for returning the value of account number
    {
        return Balance;//Return statement
    }

    inline void WithdrawMoney(long long Amount)//Function to withdraw
    {
        Balance -= Amount;//The amount to be withdrew from account
    }

    inline void DepositMoney(long long Amount)//Function to deposit
    {
        Balance += Amount;//The amount to be deposited in account
    }
};

int FindAccount(long AccNum,BankAccount Acc[], int NumAcc)//Function for finding account
{
    for (int i = 0; i < NumAcc; i++)//Loop for matching Account no. with entered account no.
    {
        if (Acc[i].GetAccNum() == AccNum)//If entered account matched with account no.
        {
            return i;//Returning index of matched account
        }
    }
    return -1;//Returning false as 1
}

int main()//Main function
{
    //Creating object
    class BankAccount Acc[100];

    int NumAcc = 0;//Variable for tracking the no. of account & initializing to 0
    int Choice;//Variable for choice
    long long Amount;//Variable for amount

    //Printing menu
    cout << "Enter 1 to add account details." << endl;
    cout << "Enter 2 to transfer money." << endl;
    cout << "Enter 3 to display no. of accounts." << endl;
    cout << "Else to exit." << endl;
    cout << "===================================" << endl;

    while (true)//Loop for doing various tasks
    {
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

        case 2://Case for transferring money
        {
            long AccFindW,AccFindD;//Variable for matching account number
            int ResultD,ResultW;//Variables for taking values from FindAccount function

            cout << "Enter the account no. for withdrawal: ";
            cin >> AccFindW;//Taking input of Account no. to search

            //Initializing ResultW with returned from FindAccount function
            ResultW = FindAccount(AccFindW,Acc,NumAcc);//Calling FindAccount function

            if(ResultW == -1)//If returned value is -1
            {
                cout << "Account not found!" << endl;//Printing error message

                break;//Break statement
            }

            cout << "Enter the account no. for deposit: ";
            cin >> AccFindD;//Taking input of Account no. to search

            //Initializing ResultD with returned from FindAccount function
            ResultD = FindAccount(AccFindD,Acc,NumAcc);//Calling FindAccount function

            if(ResultD == -1)//If returned value is -1
            {
                cout << "Account not found!" << endl;//Printing error mesasage

                break;//Break statement
            }

            cout << "Enter the amount be transfered: ";
            cin >> Amount;//Taking input of amount

            if(Amount > Acc[AccFindW].GetBalance())//If entered amount is greater that account balance
            {
                cout << "Insufficient balance!" << endl;//Printing error message

                break;//Break statement
            }

            Acc[ResultW].WithdrawMoney(Amount);//Calling WithdrawMoney
            Acc[ResultD].DepositMoney(Amount);//Calling DepositMoney

            cout << "Amount is successfully transfered!" << endl;//Printing message

            cout << "Transaction summary:" << endl;

            Acc[ResultW].DisplayAccDetails();//Printing withdrawal account's details
            Acc[ResultD].DisplayAccDetails();//Printing deposit account's details

            break;//Break statement
        }

        case 3://Case for displaying no. of accounts
        {
            cout << "The no. of account created: " << NumAcc << endl;//Printing no. of accounts

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
