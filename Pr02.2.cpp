/*A university managing academic data for its students. The administration seeks to digitize the records of student performance, including personal and 
academic details. The system must store each student's roll number, name, and marks in three subjects. Additionally, it should provide functionalities to 
calculate and display the average marks for performance analysis.
The institution's IT team proposed a solution where student records could be initialized in two ways: either with default values for testing purposes or 
by accepting specific input details for each student. Once initialized, the system would allow for viewing comprehensive student details, including their 
roll number, name, marks, and calculated average. This functionality was designed to help faculty and administrators track individual student performance 
efficiently.
To simulate real-world usage, the team decided to create multiple student records. They planned to populate the system with a mix of students initialized 
using both default and specific values. The system's ability to accurately calculate averages and display detailed student information was to be tested 
with this data.*/

//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#include<cstring>//String functions library
#include<iomanip>//Input/Output manipulation library

using namespace std;

class Student//Creating class
{
    //Private data-members
    int RollNum;
    char Name[10];
    float Marks1,Marks2,Marks3,Average;

    //Private member-function
    inline void CalculateAverage()//Function for calculating average marks of 3 subs.
    {
        Average=(Marks1+Marks2+Marks3)/3.0;//Calculating average of 3 subs.
    }

public:

    //Making public functions for different tasks
    Student()//Default constructor
    {
        RollNum = 0;//Initializing roll no. to default value 0
        strcpy(Name,"N/A");//Initializing name to default value N/A
        Marks1 = 0;//Initializing marks of sub.1 to default value 0
        Marks2 = 0;//Initializing marks of sub.2 to default value 0
        Marks3 = 0;//Initializing marks of sub.3 to default value 0
        Average = 0;//Initializing average to default value 0
    }

    Student(int StuRollNo,char StuName[],int StuMarks1,int StuMarks2,int StuMarks3)//Parameterized constructor
    {
        //Setting student's details with parameters
        RollNum = StuRollNo;
        strcpy(Name,StuName);
        Marks1 = StuMarks1;
        Marks2 = StuMarks2;
        Marks3 = StuMarks3;
    }

    void AddStuDetails()//Function for adding student's details
    {
        cout << "Enter roll number: ";
        cin >> RollNum;//Taking input of roll no.
        cout << "Enter name: ";
        cin >> Name;//Taking input of name
        cout << "Enter marks of subject 1: ";
        cin >> Marks1;//Taking input of marks of sub.1
        cout << "Enter marks of subject 2: ";
        cin >> Marks2;//Taking input of marks of sub.2
        cout << "Enter marks of subject 3: ";
        cin >> Marks3;//Taking input of marks of sub.3

        CalculateAverage();//Calling CalculateAverage function

        cout << "Student's details are successfully added!" << endl;//Printing message
    }

    void DisplayStuDetails()//Function for displaying all plot's data
    {
        cout << "Student's details:" << endl;//Displaying student's details
        cout << "Roll number: " << RollNum << endl;//Displaying roll no.
        cout << "Name: " << Name << endl;//Displaying name
        cout << "Marks of subject 1: " << Marks1 << endl;//Displaying marks of sub.1
        cout << "Marks of subject 2: " << Marks2 << endl;//Displaying marks of sub.2
        cout << "Marks of subject 3: " << Marks3 << endl;//Displaying marks of sub.3
        cout << "Average: " << setprecision(2) << Average << endl;//Displaying average of 3 subs.
    }

    inline int GetRollNo()//Function for returning value of roll no.
    {
        return RollNum;//Returning roll no.
    }
};

int main()//Main function
{
    class Student S[100];//Creating object

    int NumStu = 0;//Variable for tracking the no. of students & initializing to 0
    int Choice,StuFind;//Variable for Choice & variable for matching roll no.

    //Displaying menu
    cout << "Enter 1 to add student's details." << endl;
    cout << "Enter 2 to display student's details." << endl;
    cout << "Else to exit." << endl;
    cout << "=====================================" << endl;

next ://Label
    cout << "Enter your choice which you want: ";
    cin >> Choice;//Taking input of choice

    switch (Choice)//Switch case
    {
    case 1://Case for adding student's details
    {
        S[NumStu].AddStuDetails();//Calling AddStuDetails function

        NumStu++;//Increment in variable no. of student

        break;//Break statement
    }

    case 2://Case for displaying student's details
    {
        cout << "Enter student's roll no.: ";
        cin >> StuFind;//Taking input of roll no. to search

        bool Found = false;//boolean type variable for switching between true/false & initializing it with false

        for(int i = 0; i < NumStu; i++)//Loop for matching roll no. with entered roll no.
        {
            if(S[i].GetRollNo() == StuFind)//If roll no. matched with entered roll no. ...
            {
                S[i].DisplayStuDetails();//Calling DisplayStuDetails function

                Found = true;//If roll no. matched with entered roll no. then Found variable switches to true

                break;//Break statement
            }
        }

        if(! Found)//If Found variable doesn't switch to true...
        {
            S[StuFind].DisplayStuDetails();//Calling DisplayStuDetails function
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
