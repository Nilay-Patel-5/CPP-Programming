/*A regional banking institution sought to improve its loan management process by developing a system that could efficiently handle loan details for
applicants. The system was expected to streamline the calculation of monthly EMIs (Equated Monthly Installments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent information about their loans.
To meet these requirements, the bank's technology team was tasked with designing a solution. They envisioned a system where each loan would be uniquely
identified by a loan ID, and additional details such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months would be
stored. The team also emphasized the importance of accurately calculating the EMI using a standard formula based on the loan amount, interest rate, and
tenure. The formula incorporated compound interest principles to determine the fixed monthly payment for the loan term.
                                                                        EMI= (𝑃 ∗ 𝑅 ∗ (1 + 𝑅)^𝑇)/(((1+𝑅)^𝑇) −1)
As part of the implementation, the developers planned to initialize loans either with default values for testing purposes or with actual customer data
provided at the time of application. The system needed to include a feature to display comprehensive loan details, including the calculated EMI, in a
customer-friendly format. This functionality was intended to aid both customers and bank staff in managing loan-related queries effectively.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#include<math.h>//Standard math library

using namespace std;

class LoanAcc//Creating class
{
    //Private data-members
    int LoanID;
    long LoanAmount;
    char AppName[20];
    float InterestRate,LoanTenure;
    float EMI;

    inline void CalculateEMI()//Function calculating EMI
    {
        InterestRate = InterestRate/12/100;//Calculating Interest rate
        EMI =  (LoanAmount*InterestRate*pow((1+InterestRate),LoanTenure))/(pow((1+InterestRate),LoanTenure)-1);//Calculating EMI
    }

//Making public functions for different tasks
public:

    void AddAccData()//Function for adding account data
    {
        cout << "Enter loan ID: ";
        cin >> LoanID;//Taking input of loan ID
        cout << "Enter applicant's name: ";
        cin >>  AppName;//Taking input of applicant's name
        cout << "Enter total loan amount: ";
        cin >> LoanAmount;//Taking input of loan amount
        cout << "Enter annual interest rate: ";
        cin >> InterestRate;//Taking input of interest rate
        cout << "Enter loan tenure in months : ";
        cin >> LoanTenure;//Taking input of loan period in months

        CalculateEMI();//Calling CalculateEMI function internally
    }

    void DisplayAccData()//Function for displaying account data
    {
        InterestRate = InterestRate*12*100;//Calculating interest rate

        cout << "Account's details:" << endl;
        cout << "Applicant's name: " << AppName << endl;//Displaying applicant's name
        cout << "Total loan amount: " << LoanAmount << endl;//Displaying loan amount
        cout << "Annual interest rate: " << InterestRate << "%" << endl;//Displaying interest rate
        cout << "Loan tenure in months : " << LoanTenure << endl;//Displaying loan period in months
        cout << "Total EMI of loan amount: " << EMI << endl;//Displaying Total EMI
    }

    inline int GetAccNum()//Function for returning account no.
    {
        return LoanID;//Returning loan ID
    }
};

int main()//Main function
{
    class LoanAcc L[100];//Creating object

    int NumAcc = 0;//Variable for tracking no.of account will be created & initializing to 0
    int AccFind,Choice;//Variables for matching account no. & choice

    //Displaying menu
    cout << "Enter 1 to add loan account." << endl;
    cout << "Enter 2 to display account data." << endl;
    cout << "Else to Exit." << endl;
    cout << "================================"<<endl;

    while(true)//Loop for doing various tasks
    {
        cout << "Enter the option which you want: ";
        cin >> Choice;//Taking input of choice

        switch(Choice)//Switch case
        {
        case 1://Case for adding account data
        {
            L[NumAcc].AddAccData();//Calling AddAccData function

            NumAcc++;//Increment in no. of accounts

            break;//Break statement
        }

        case 2://Case for displaying account data
        {
            cout << "Enter Loan ID: ";
            cin >> AccFind;//Taking input of account no. to search

            bool Found = false;//Variable for signal if account no. matched

            for (int i = 0; i < NumAcc; i++)//Loop for matching item ID with entered loan ID
            {
                if (L[i].GetAccNum() == AccFind)//If entered loan ID matched with loan ID...
                {
                    L[i].DisplayAccData();//Calling DisplayAccData function

                    Found = true;//Account no. matched with entered loan ID

                    break;//Break statement
                }
            }

            if(! Found)//If Found variable doesn't switch to true...
            {
                cout << "Account not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        default://Default case
        {
            cout << "24CE089_NILAY PATEL";//Printing exiting message

            return 0;//Return statement
        }
        }
    }
}
