/*A software development team is working on an advanced simulation system that involves hierarchical object management. The
system includes a base class that defines general behavior and derived classes that introduce specialized functionality, including
dynamic resource allocation. During testing, the team encounters unexpected memory leaks when deleting objects through base class
pointers, raising concerns about proper resource management.
To investigate the issue, the team examines how object destruction works in an inheritance hierarchy. They create a base class
that serves as a foundation for derived classes, but they notice that when a Base* pointer is used to delete a Derived object, the
destructor of the derived class is not invoked. This results in dynamically allocated resources remaining in memory, causing
resource leakage.
To resolve this problem, the team explores the concept of virtual destructor. By marking the base class destructor as virtual,
they ensure that the destructor of the derived class is correctly called when deleting an object through a base class pointer.
This guarantees proper deallocation of dynamically allocated resources, preventing memory leaks.
Since the project requires manual memory management, the team uses raw pointers and the new and delete operators to allocate and
release resources.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output library
using namespace std;

class Base//Base class definition
{
public:

    virtual ~Base()//Virtual destructor for Base class
    {
        cout << "Base class destructor\n";//Printing message
    }

    virtual void Show()//Virtual function for showing behavior
    {
        cout << "Base class behavior\n";//Printing message
    }
};

class Derived : public Base//Derived class inheriting Base
{
public:

    Derived()//Constructor of Derived class
    {
        cout << "Derived class constructor\n";//Printing message
    }

    ~Derived()//Destructor of Derived class
    {
        cout << "Derived class destructor\n";//Printing message
    }

    void Show() override//Override function for showing behavior
    {
        cout << "Derived class behavior\n";//Printing message
    }
};

int main()//Main function
{
    Base* Obj = new Derived();//Creating object of Derived class using Base pointer

    Obj->Show();//Calling Show function

    delete Obj;//Deleting object to invoke destructor

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
