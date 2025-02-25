#include<iostream>
#include<math.h>
using namespace std;

class LoanAcc
{
    int LoanID;
    long LoanAmount;
    char AppName[20];
    float InterestRate,LoanTenure;
    float EMI;

    void CalculateEMI()
    {
        InterestRate=InterestRate/12/100;
        EMI =  (LoanAmount*InterestRate*pow((1+InterestRate),LoanTenure))/(pow((1+InterestRate),LoanTenure)-1);
    }

public:
    void AddAccData()
    {
        cout << "Enter loan ID: ";
        cin >> LoanID;
        cout<<"Enter applicant's name: ";
        cin>>AppName;
        cout<<"Enter total loan amount: ";
        cin>>LoanAmount;
        cout<<"Enter annual interest rate: ";
        cin>>InterestRate;
        cout<<"Enter loan tenure in months : ";
        cin>>LoanTenure;

        CalculateEMI();
    }

    void DisplayAccData()
    {
        InterestRate=InterestRate*12*100;

        cout<<"Loan ID: "<<LoanID<<endl;
        cout<<"Applicant's name: "<<AppName<<endl;
        cout<<"Total loan amount: "<<LoanAmount<<endl;
        cout<<"Annual interest rate: "<<InterestRate<<"%"<<endl;
        cout<<"Loan tenure in months : "<<LoanTenure<<endl;
        cout<<"Total EMI of loan amount: "<<EMI<<endl;
    }

    int GetAccNum()
    {
        return LoanID;
    }
};

int main()
{
    class LoanAcc L[100];
    int NumAcc=0;
    int AccFind,Choice;

    cout << "Enter 1 to add loan account." << endl;
    cout << "Enter 2 to display account data." << endl;
    cout << "Else to Exit." << endl;

    while(Choice != 0)
    {
        cout << "================================"<<endl;
        cout << "Enter the option which you want: ";
        cin >> Choice;


        switch(Choice)
        {
            case 1:
                {
                    if (NumAcc < 100)
                    {
                        L[NumAcc].AddAccData();
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
                    cout << "Enter Loan ID: ";
                    cin >> AccFind;

                    for (int i = 0; i < NumAcc; i++)
                    {
                        if (L[i].GetAccNum() == AccFind)
                        {
                            L[i].DisplayAccData();
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
                {
                    cout << "24CE089_NILAY PATEL";
                    return 0;
                }
            }
    }
}
