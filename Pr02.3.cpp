#include<iostream>
using namespace std;

class Account
{
    char AccHolderName[10];
    long int AccNum, Balance;

public:
    void AddAccDetails()
    {
        cout << "Enter the account holder's name: ";
        cin >> AccHolderName;

        cout << "Enter the account number: ";
        cin >> AccNum;

        Balance = 1000;
    }

    void DepositMoney()
    {
        long Amount;

        cout << "Enter the amount to deposit: ";
        cin >> Amount;

        Balance += Amount;

        cout << "Deposit successful." << endl;
    }

    void WithdrawMoney()
    {
        long Amount;

        cout << "Enter the amount to withdraw: ";
        cin >> Amount;

        if (Amount > Balance - 1000)
        {
            cout << "Insufficient balance" << endl;
        }

        else
        {
            Balance -= Amount;
            cout << "Withdrawal successful." << endl;
        }
    }

    void DisplayAccDetails()
    {
        cout << "Account holder's name: " << AccHolderName << endl;
        cout << "Account number: " << AccNum << endl;
        cout << "Current balance: " << Balance << endl;
    }

    long getAccNum()
    {
        return AccNum;
    }
};

int main()
{
    Account Acc[100];
    int NumAcc = 0;
    long AccFind
    int Choice;

    cout << "Enter 1 to add account." << endl;
    cout << "Enter 2 to deposit." << endl;
    cout << "Enter 3 to withdraw." << endl;
    cout << "Enter 4 to display details." << endl;
    cout << "Else to Exit." << endl;
    
    while (Choice != 0)
    {
        cout << "==================================" << endl;
        cout << "Enter the option which you want: ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            {
                if (NumAcc < 100)
                {
                    Acc[NumAcc].AddAccDetails();
                    NumAcc++;
                }
            
                else
                {
                    cout << "Account limit reached." << endl;
                }
                break;
            }
            
        case 2:
            {
                cout << "Enter the account number: ";
                cin >> AccFind;

                for (int i = 0; i < NumAcc; i++)
                {
                    if (Acc[i].getAccNum() == AccFind)
                    {
                        Acc[i].DepositMoney();
                        break;
                    }
                    
                    else if (i ==NumAcc-1)
                    {
                        cout << "Account not found." << endl;
                    }
                }
                break;    
            }
            

        case 3:
            {
                cout << "Enter the account number: ";
                cin >> AccFind;

                for (int i = 0; i < NumAcc; i++)
                {
                    if (Acc[i].getAccNum() == AccFind)
                    {
                        Acc[i].WithdrawMoney();
                        break;
                    }
                    
                    else if (i == NumAcc - 1)
                    {
                        cout << "Account not found." << endl;
                    }
                }
                break;
            }
            

        case 4:
            {
                cout << "Enter the account number: ";
                cin >> AccFind;

                for (int i = 0; i < NumAcc; i++)
                {
                    if (Acc[i].getAccNum() == AccFind)
                    {
                        Acc[i].DisplayAccDetails();
                        break;
                    }
                
                else if (i == NumAcc-1)
                    {
                        cout << "Account not found." << endl;
                    }
                }
                break;
            }
            
        default:
            
            cout << "24CE089_NILAY PATEL" << endl;
            return 0;
        }
    }
}
