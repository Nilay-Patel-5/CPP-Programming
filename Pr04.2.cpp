#include<iostream>
#include<cstring>

using namespace std;

class Person
{
    char Name[10];
    int Age;

public:

    Person()
    {
        strcpy(Name,"");
        Age = 0;
    }

    void AddPersonData()
    {
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Age: ";
        cin >> Age;
    }

    void DisplayPersonData()
    {
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
    }
};

class Employee : private Person
{
    int EmployeeID;

public:

    Employee() : Person()
    {
        EmployeeID = 0;
    }

    void AddEmployeeData()
    {
        AddPersonData();

        cout << "Enter employee ID: ";
        cin >> EmployeeID;
    }

    void DisplayEmployeeData()
    {
        DisplayPersonData();

        cout << "Employee ID: " << EmployeeID << endl;
    }
};

class Manager : private Employee
{
    char Department[10];

public:

    Manager() : Employee()
    {
        strcpy(Department,"");
    }

    void AddManagerData()
    {
        AddEmployeeData();

        cout << "Enter department: ";
        cin >> Department;
    }

    void DisplayManagerData()
    {
        DisplayEmployeeData();

        cout << "Department: " << Department << endl;
    }
};

int main()
{
    class Manager M;

    M.AddManagerData();
    M.DisplayManagerData();

    return 0;
}
