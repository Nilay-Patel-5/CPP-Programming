/*A growing organization sought to enhance its payroll process to improve accuracy and efficiency in calculating employee salaries. The goal was to manage
details such as the employee's name, basic salary, and bonus amount. While most employees would receive a default bonus, there was a need for flexibility
to provide customized bonuses for exceptional performers or those in specialized roles.
To ensure real-time computation of each employee's total salary, the system would dynamically calculate the total salary by adding the basic salary and the
bonus. An inline function was chosen for this task, allowing the system to compute the total salary instantly during processing. The system was designed to
initialize employee records using a constructor, where the bonus could either be set to a default value or adjusted according to specific employee criteria.
As the organization expanded, managing employee records efficiently became a key consideration. The solution involved storing employee details dynamically,
ensuring the system could handle a growing number of records while maintaining scalability and flexibility. Each employee record would include their
personal details, basic salary, and bonus information, with the system displaying a breakdown of each employee’s details along with their total salary.*/

//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library

using namespace std;

class Employee//Creating class
{
    //Private data-members
    char EmployeeName[10];
    int BasicSalary,BonusAmount,TotalSalary;

    //Private members-functions
    inline void AddDefaultBonus()//Function for adding default bonus
    {
        BonusAmount = BasicSalary*0.1;//Default bonus amount
        TotalSalary = BasicSalary + BonusAmount;//Total salary
    }

    inline void AddAdditionalBonus()//Function for adding additional bonus
    {
        cout << "Enter additional bonus: ";
        cin >> BonusAmount;//Taking input of additional bonus
        TotalSalary = BasicSalary + (BasicSalary*0.1) + BonusAmount;//Total salary
    }

public:

    //Making public functions for different tasks
    void AddEmployeeData()//Function for entering data of employee
    {
        int Choice1;//Variable for another choice

        cout << "Enter employee's name: ";
        cin >> EmployeeName;//Taking input of employee's name
        cout << "Enter employee's basic salary: ";
        cin >> BasicSalary;//Taking input of basic salary
        cout << "Enter 0 to add default bonus or 1 to add additional bonus: ";
        cin >> Choice1;//Taking input of another choice

        if(Choice1 == 0)//If entered choice is 0...
        {
            AddDefaultBonus();//Calling AddDefaultBonus function
        }

        else if(Choice1 == 1)//If entered choice is 1...
        {
            AddAdditionalBonus();//Calling AddAdditionalBonus function
        }

        else//If not...
        {
            cout << "Invalid input!" << endl;//Printing error message
        }

        cout << "Employee's Data is successfully added!" << endl;//Printing message
    }

    void DisplayEmployeeData()//Function for displaying employee's data
    {
        cout << "Employee details:" << endl;
        cout << "Name: " << EmployeeName << endl;//Displaying name
        cout << "Basic salary: " << BasicSalary << endl;//Displaying basic salary
        cout << "Bonus amount: " << BonusAmount << endl;//Displaying bonus amount
        cout << "Total salary: " << TotalSalary << endl;//Displaying total salary
    }
};

int main()//Main function
{
    class Employee E[100];//Creating object

    int NumEmployee = 0;//Variable for tracking no. of employee & initializing to zero
    int Choice;//Variable for choice
    int EmployeeFind;//Variable for matching employee ID

    //Displaying menu
    cout << "Enter 1 to add employee's data." << endl;
    cout << "Enter 2 to display employee's data." << endl;
    cout << "Else to exit." << endl;
    cout << "===================================" << endl;

next ://Label
    cout << "Enter your choice which you want: ";
    cin >> Choice;//Taking input of another choice

    switch (Choice)//Switch case
    {
    case 1://Case for entering data of employee
        {
            E[NumEmployee].AddEmployeeData();//Calling AddEmployeeData function

            NumEmployee++;//Increment in no. of employee

            break;//Break statement
        }

    case 2://Case for displaying employee's data
        {
            cout << "Enter employee's ID: ";
            cin >> EmployeeFind;//Taking input of employee's ID to search

            if(EmployeeFind <= NumEmployee)//If no. of employee is greater than entered employee's ID ...
            {
                E[EmployeeFind-1].DisplayEmployeeData();//Calling DisplayEmployeeData function

                break;//Break statement
            }

            else//If not...
            {
                cout << "Employee not found!" << endl;//Printing error message

                break;//Break statement
            }
            break;//Break statement
        }

    default://Default case
        {
            cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

            return 0;//Return statement
        }
    }
    goto next;//Goto statement
}
