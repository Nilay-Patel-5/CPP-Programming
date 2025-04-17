/*In an educational setting, an advanced grading system was conceptualized to accommodate the diverse evaluation criteria for students at different academic
levels. At the heart of the system is an abstract base class that defines the grading framework. This class includes a protected member to store marks and
declares a pure virtual function for computing grades, ensuring that specific grading logic is implemented by derived classes.
Two distinct derived classes were introduced to handle the unique grading needs of undergraduate and postgraduate students. Each class defines its own
implementation of the grade computation method, reflecting the varying academic expectations for these groups. The system enables users to input student
data, compute grades based on the respective criteria, and manage a collection of student records.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#include<cstring> //String library
#include<iomanip>//Input/Output manipulation library

using namespace std;

class GradingFramework//Creating class
{
protected:
    //Protected data-members
    char Name[20];
    float Marks1, Marks2, Marks3;

//Making public functions for different tasks
public:
    //Pure virtual function
    virtual void AddStuDetails() = 0;//For adding student's details

    virtual void CalculateAverage() = 0;//For calculating average

    virtual void DisplayStuDetails() = 0;//For displaying student's details
};

class UGStudent : public GradingFramework//Creating class with parent class
{
//Making public functions for different tasks
public:

    void AddStuDetails() override//Overriding function for adding student's details
    {
        cout << "Enter student's name: ";
        cin >> Name;//Taking input of student's name
        cout << "Enter marks of subject 1: ";
        cin >> Marks1;//Taking input of marks of sub.1
        cout << "Enter marks of subject 2: ";
        cin >> Marks2;//Taking input of marks of sub.2
        cout << "Enter marks of subject 3: ";
        cin >> Marks3;//Taking input of marks of sub.3
        cout << "===========================" << endl;
    }

    void CalculateAverage() override//Overriding function for calculating average marks
    {
        cout << "The average marks of 3 subjects: " << fixed << setprecision(2)  << (Marks1 + Marks2 + Marks3) / 3.0 << endl;//Printing average marks of three sub.s
        cout << "======================================" << endl;
    }

    void DisplayStuDetails() override//Overriding function for displaying student's details
    {
        cout << "The student's details: " << endl;
        cout << "Name: " << Name << endl;//Printing student's name
        cout << "Marks of subject 1: " << Marks1 << endl;//Printing marks of sub.1
        cout << "Marks of subject 2: " << Marks2 << endl;//Printing marks of sub.2
        cout << "Marks of subject 3: " << Marks3 << endl;//Printing marks of sub.3

        if (((Marks1 + Marks2 + Marks3)) / 3 >= 40)//If average marks of 3 sub.s is greater than or equal to 40...
        {
            cout << "The student is Pass" << endl;//Printing pass
        }
        else//If not...
        {
            cout << "The student is Fail" << endl;//Printing fail
        }
    }
};

class PGStudent : public GradingFramework//Creating class with parent class
{
//Making public functions for different tasks
public:

    void AddStuDetails() override //Overriding function for adding student's details
    {
        cout << "Enter name of student: ";
        cin >> Name;//Taking input of student's name
        cout << "Enter marks of subject 1: ";
        cin >> Marks1;//Taking input of marks of sub.1
        cout << "Enter marks of subject 2: ";
        cin >> Marks2;//Taking input of marks of sub.2
        cout << "Enter marks of subject 3: ";
        cin >> Marks3;//Taking input of marks of sub.3
        cout << "==========================" << endl;
    }

    void CalculateAverage() override//Overriding function for calculating average marks
    {
        cout << "The average marks of 3 subjects: " << fixed << setprecision(2) << (Marks1 + Marks2 + Marks3) / 3.0 << endl;//Printing average marks of three sub.s
        cout << "======================================" << endl;
    }

    void DisplayStuDetails() override//Overriding function to display result and marks
    {
        cout << "The student's details: " << endl;
        cout << "Name: " << Name << endl;//Printing student's name
        cout << "Marks of subject 1: " << Marks1 << endl;//Printing marks of sub.1
        cout << "Marks of subject 2: " << Marks2 << endl;//Printing marks of sub.2
        cout << "Marks of subject 3: " << Marks3 << endl;//Printing marks of sub.3

        if ((Marks1 + Marks2 + Marks3) / 3.0 >= 50)//If average marks of 3 sub.s is greater than or equal to 40...
        {
            cout << "The student is Pass" << endl;//Printing pass
        }
        else//If not...
        {
            cout << "The student is Fail" << endl;//Printing fail
        }
    }
};

int main() //Main function
{
    //Creating objects
    UGStudent UGS;
    PGStudent PGS;

    //Declaring pointers of base class
    GradingFramework *GF1,*GF2;

    //Assigning objects to base class pointers
    GF1 = &UGS;
    GF2 = &PGS;

    int Choice;//Variable for choice

    //Displaying menu
    cout << "Enter 1 for UG student." << endl;
    cout << "Enter 2 for PG student." << endl;
    cout << "Else to exit." << endl;
    cout << "=======================" << endl;

Label://Label
    cout << "Enter your choice: ";
    cin >> Choice;//Taking input of choice

    if (Choice == 1)//If choice is equal to 1...
    {
        GF1->AddStuDetails();//Calling AddStuDetails function for UG
        GF1->DisplayStuDetails();//Calling DisplayStuDetails function for UG
        GF1->CalculateAverage();//Calling CalculateAverage function for UG
        goto Label;//Goto statement
    }
    else if (Choice == 2)//If choice is equal to 2...
    {K
        GF2->DisplayStuDetails();//Calling DisplayStuDetails function for PG
        GF2->CalculateAverage();//Calling CalculateAverage function for PG
        goto Label;//Goto statement
    }
    else//If not...
    {
        cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
        return 0;//Return statement
    }
}
