/*A growing organization wanted to develop a system to manage its hierarchy and represent its structure in a programmatic way. To achieve this, a
multilevel approach was designed, reflecting the natural progression of roles within the organization. At the foundation, a class was created to represent
a person, capturing the basic details such as name and age. Building on this, an intermediate level was introduced to represent employees, adding a unique
identifier for each. Finally, at the topmost level, a class for managers was created, which included additional details such as the department they oversee.
The system needed to handle the initialization of all these attributes through constructors at each level, ensuring the proper propagation of information
across the hierarchy. Additionally, the functionality to display details at every level was included to provide clear insights into the organization's
structure. Two approaches were explored for managing multiple managers: one relied on an efficient method for retrieval and organization based on employee
identifiers, while the other used a straightforward and static method for storage.*/

//This program is prepared by 24CE089_NILAY PATEL.
#include<iostream>//Standard input/output library
#include<cstring>//Standard string library

using namespace std;

class Person//Creating class
{
    //Private data-members
    char Name[10];
    int Age;

//Making public functions for different tasks
public:

    Person()//Constructor of Person class
    {
        //Initializing data members with default value
        strcpy(Name," ");
        Age = 0;
    }

    void AddPersonData()//Function for Adding person's data
    {
        cout << "Enter Name: ";
        cin >> Name;//Taking input of Name
        cout << "Enter Age: ";
        cin >> Age;//Taking input of age
    }

    void DisplayPersonData()//Function for displaying person's data
    {
        cout << "Name: " << Name << endl;//Displaying Name
        cout << "Age: " << Age << endl;//Displaying Age
    }
};

class Employee : private Person//Creating class with a parent class
{
    //Private data-members
    int EmployeeID;

//Making public functions for different tasks
public:

    Employee() : Person()//Constructor of Person class with a constructor of parent
    {
        //Initializing data members with default value
        EmployeeID = 0;
    }

    void AddEmployeeData()//Function for displaying employee's data
    {
        AddPersonData();//Calling AddPersonData function internally

        cout << "Enter employee ID: ";
        cin >> EmployeeID;//Taking input of employee ID
    }

    void DisplayEmployeeData()//Function for displaying employee's data
    {
        DisplayPersonData();//Calling DisplayPersonData function internally

        cout << "Employee ID: " << EmployeeID << endl;//Displaying employee's ID
    }
};

class Manager : private Employee//Creating class with a parent class
{
    //Private data-members
    char Department[10];

//Making public functions for different tasks
public:

    Manager() : Employee()//Constructor of Person class with a constructor of parent
    {
        //Initializing data members with default value
        strcpy(Department," ");
    }

    void AddManagerData()//Function for displaying manager's data
    {
        AddEmployeeData();//Calling AddEmployeeData function internally

        cout << "Enter department: ";
        cin >> Department;//Taking input of  department
    }

    void DisplayManagerData()//Function for displaying Manager's data
    {
        cout << "Entered data:~" << endl;
        DisplayEmployeeData();//Calling DisplayEmployeeData function internally

        cout << "Department: " << Department << endl;//Displaying department
    }
};

int main()//Main function
{
    class Manager M;//Creating object

    M.AddManagerData();//Calling AddManagerData function
    M.DisplayManagerData();//Calling DisplayManagerData function

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
