#include<iostream>//Standard Input/Output library
using namespace std;

class BankAccount//Creating class
{
    //Private data-members
    string HoldName;
    long balance;
    long AccNum;

    //Making public functions for different tasks
    public:
    void AccDetails()//Function for entering details of bank account
    {
        cout<<"Enter the account holder's name: ";
        cin>>HoldName;//Taking input of account holder's name
        cout<<"Enter the account number: ";
        cin>>AccNum;//Taking input of account number
        cout<<"Enter the amount of balance: ";
        cin>>balance;//Taking input of account balance
    }

    int GetAccNum()//Function for returning the value of account number
    {
        return AccNum;//Return statement
    }

    void deposit()//Function to deposite
    {
        //Variable declaration
        long amount;

        cout<<"Enter the amount to be deposit: ";
        cin>>amount;
        balance+=amount;//The amount to be deposit in account
        cout<<"Deposit successful."<<endl;//Printing message
    }

    void withdraw()//Function to withdraw
    {
        //Variable declaration
        long amount;

        cout<<"Enter the amount to be withdraw: ";
        cin>>amount;

        if(amount>=balance)//If wanted amount of withdraw is greater than balance....
        {
                cout<<"Insufficient balance"<<endl;//Printing error message
        }

        else//If not....
        {
            balance-=amount;//The amount to be withdraw from account
            cout<<"Withdraw successful."<<endl;//Printing message
        }
    }

    void display()//Function for displaying balance
    {
         cout<<"Current balance: "<<balance<<endl;//Printing current balance
    }
};

int main()//Main function
{
    class BankAccount Acc[5];//Creating object
    long AccFind;//Variable for matching account number

    for(int i=0;i<5;i++)//Loop for calling AccDetails function
    {
        Acc[i].AccDetails();
    }

    cout<<"=================================="<<endl;

    int choice;//Variable for choice

    //Printing menu
    cout<<"Enter 1 to deposit."<<endl;
    cout<<"Enter 2 to withdraw."<<endl;
    cout<<"Enter 3 to display the current balance."<<endl;
    cout<<"Enter 0 to Exit."<<endl;

    while(choice != 0)
    {
        cout<<"Enter the option which you want: ";
        cin>>choice;//Taking input of choice

        switch(choice)//Switch case
        {
            case 1://Case to deposite
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)//Loop for calling deposit function
                    {
                        if(Acc[i].GetAccNum()==AccFind)//If Account number is matched....
                        {
                            Acc[i].deposit();
                            break;//Break statement
                        }

                        else//If not....
                        {
                            cout<<"Account no. not found"<<endl;//Printing error message
                            break;//Break statement
                        }
                    }
                    break;//Break statement
                }

                case 2://Case to withdraw
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)//Loop for calling withdraw function
                    {
                        if(Acc[i].GetAccNum()==AccFind)//If account number is matched....
                        {
                            Acc[i].withdraw();
                            break;//Break statement
                        }

                        else//If not....
                        {
                            cout<<"Account no. not found"<<endl;
                            break;//Break statement
                        }
                    }
                    break;//Break statement
                }
            case 3://case for displaying balance
                {
                    cout<<"Enter the account no.: ";
                    cin>>AccFind;

                    for(int i=0;i<5;i++)//Loop for calling display function
                    {
                        if(Acc[i].GetAccNum()==AccFind)//If account number is matched....
                        {
                            Acc[i].display();
                            break;//Break statement
                        }

                        else//If not....
                        {
                            cout<<"Account no. not found"<<endl;//Printing error message
                            break;//Break statement
                        }
                    }
                    break;//Break statement
                    }

            case 0://Case for exiting the program
                {
                    cout<<"24CE089_NILAY PATEL";//Printing message
                    return 0;//Return statement
                }

            default://Default Case
                {
                    cout<<"Invalid choice"<<endl;//Printing error message
                }
            }
    }
}
