
#include<iostream>
using namespace std;

class Account
{
   
    string AccHolderName;
    long int AccNum,Balance;
   
    public:
    void AddAccDetails()
    {
        cout<<"Enter the account holder's name: ";
        cin>>AccHolderName;
        cout<<"Enter the account number: ";
        cin>>AccNum;
        Balance=1000;
    }

    int GetAccNum()
    {
        return AccNum;
    }

    void DepositMoney()
    {
        
        long Amount;

        cout<<"Enter the amount to be deposit: ";
        cin>>Amount;
        Balance+=Amount;
        cout<<"Deposit successful."<<endl;
    }

    void WithdrawMoney()
    {
        long Amount;

        cout<<"Enter the amount to be withdraw: ";
        cin>>Amount;

        if(Amount>=Balance)
        {
                cout<<"Insufficient balance"<<endl;
        }

        else
        {
            Balance-=Amount;
            cout<<"Withdraw successful."<<endl;
        }
    }

    void DisplayAccDetails()
    {
        cout<<"Account holder's name: "<<AccHolderName<<endl;
        cout<<"Account number: "<<AccNum<<endl;
        cout<<"Current balance: "<<Balance<<endl;
    }
};

int main()
{
    class Account Acc[100];
    long NumAcc=0,AccFind;
    int Choice;
    
    cout<<"Enter 1 to add account."<<endl;
    cout<<"Enter 2 to deposit."<<endl;
    cout<<"Enter 3 to withdraw."<<endl;
    cout<<"Enter 4 to display the current balance."<<endl;
    cout<<"Else to Exit."<<endl;
    
    next : cout<<"Enter the option which you want: ";
           cin>>Choice;

    for(int i=0;i<5;i++)
    {
        Acc[i].AddAccDetails();
    }

    cout<<"=================================="<<endl;
    
    while(Choice != 0)
    {
       switch(Choice)
        {
            case 1:
            {
                for(int i=0;i<=NumAcc;i++)
                {
                    Acc[NumAcc].AddAccDetails();
                    NumAcc++;
                    break;
                }
            }
            break;
            
            case 2:
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<NumAcc;i++)
                    {
                        if(AccFind<=NumAcc)
                        {
                            Acc[NumAcc-1].DepositMoney();
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

                    for(int i=0;i<NumAcc;i++)
                    {
                        if(AccFind<=NumAcc)
                        {
                            Acc[NumAcc-1].WithdrawMoney();
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
            case 4:
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)
                    {
                        if(AccFind<=NumAcc)
                        {
                            Acc[NumAcc-1].DisplayAccDetails();
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

            default:
                {
                    cout<<"24CE089_NILAY PATEL";
                    return 0;
                }
            }
            goto next;
    }
}

