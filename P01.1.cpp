#include<iostream>
using namespace std;

class BankAccount
{
    char HoldName[20];
    long balance;

    public:
    long AccNum;

    void AccDetails();
    void deposit();
    void withdraw();
    void display();
};

int main()
{
    class BankAccount Acc[5];
    long AccFind;

    for(int i=0;i<5;i++)
    {
        Acc[i].AccDetails();
    }

    cout<<"=================================="<<endl;

    int choice;

    cout<<"Enter 1 to deposit."<<endl;
    cout<<"Enter 2 to withdraw."<<endl;
    cout<<"Enter 3 to display the current balance."<<endl;
    cout<<"Enter 0 to Exit."<<endl;

    while(1)
    {
        cout<<"Enter the option which you want: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)
                    {
                        if(Acc[i].AccNum==AccFind)
                        {
                            Acc[i].deposit();
                            break;
                        }

                        else
                        {
                            cout<<"Account no. not found"<<endl;
                            break;
                        }
                    }
                    break;
                }

            case 2:
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)
                    {
                        if(Acc[i].AccNum==AccFind)
                        {
                            Acc[i].withdraw();
                            break;
                        }

                        else
                        {
                            cout<<"Account no. not found"<<endl;
                            break;
                        }
                    }
                    break;
                }
            case 3:
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)
                    {
                        if(Acc[i].AccNum==AccFind)
                        {
                            Acc[i].display();
                            break;
                        }

                        else
                        {
                            cout<<"Account no. not found"<<endl;
                            break;
                        }
                    }
                    break;
                    }

            case 0:
                {
                    cout<<"Thank you.";
                    return 0;
                }

            default:
                {
                    cout<<"Invalid choice"<<endl;
                }
            }
    }
}

void BankAccount :: AccDetails()
    {
        cout<<"Enter the account holder's name: ";
        cin>>HoldName;
        cout<<"Enter the account number: ";
        cin>>AccNum;
        cout<<"Enter the amount of balance: ";
        cin>>balance;
    }

void BankAccount :: deposit()
    {
        long amount;

            cout<<"Enter the amount to be deposit: ";
            cin>>amount;
            balance+=amount;
            cout<<"Deposit successful."<<endl;
    }

void BankAccount :: withdraw()
    {
        long amount;

            cout<<"Enter the amount to be withdraw: ";
            cin>>amount;

            if(amount>=balance)
            {
                cout<<"Insufficient balance"<<endl;
            }

            else
            {
                balance-=amount;
                cout<<"Withdraw successful."<<endl;
            }
    }

    void BankAccount :: display()
    {
        cout<<"Current balance: "<<balance<<endl;
    }
