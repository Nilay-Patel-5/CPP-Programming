/*A software development team is tasked with designing a system that can handle various geometric shapes and compute their areas
in a flexible way. The challenge is to create a system that can easily extend to accommodate new types of shapes without altering
the core functionality for each shape. To accomplish this, the system is designed with a base class called Shape, which includes a
virtual function Area(). This function is meant to be overridden by each specific shape class to provide the correct formula for
calculating the area.
The derived classes, Rectangle and Circle, each implement the Area() function with their own formulas: the Rectangle calculates
the area using its length and width, while the Circle uses its radius. This structure allows the system to treat all shapes
uniformly through a common interface, enabling easy extensibility. The goal is to use a single reference to the base class
(Shape*) to calculate the area of any shape, regardless of its type. This approach makes the system more adaptable, as new shapes
can be added later without disrupting existing code.
In managing a collection of shapes, there are two primary approaches: one method involves dynamically managing a collection of
shapes, allowing for easy addition and removal of shapes, while the other relies on a static method that requires manually managing the size of the collection. Both approaches aim to store and manage the shapes effectively, with one allowing automatic resizing as needed while the other requires more manual handling.
Through this case study, the team will implement the base class Shape and the derived classes Rectangle and Circle, each with
their own Area() function. The students will gain a deeper understanding of polymorphism, inheritance, and memory management while
working with different methods to store and manage the collection of shapes.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#define _USE_MATH_DEFINES // <-- This line must come first
#include <cmath>          // For M_PI and other math functions
#include <iostream>       // For input/output
using namespace std;

using namespace std;

class Shape//Creating class Shape
{
//Protected data-member for storing area
protected:

    double Area;

    virtual void CalculateArea() = 0;//Pure virtual function to calculate area

    void Display()//Function for displaying area
    {
        cout << "\nArea: " << Area << " sq. units";//Displaying the calculated area
    }
};

class Rectangle : public Shape//Rectangle class derived from Shape
{
    double Length, Width;//Private data-members for length and width

    void CalculateArea() override//Overriding the pure virtual function to calculate area
    {
        Area = Length * Width;//Calculating the area of the rectangle
    }

public:
    Rectangle(double L, double W) : Length(L), Width(W)//Constructor for Rectangle, initializing length and width
    {
        CalculateArea();//Calling the CalculateArea function to calculate the area
        Display();//Calling Display function to show the area
    }
};

class Circle : public Shape//Circle class derived from Shape
{
    double Radius;//Private data-member for radius

    void CalculateArea() override//Overriding the pure virtual function to calculate area
    {
        Area = M_PI * Radius * Radius;//Calculating the area of the circle using πr^2
    }

public:
    Circle(double R) : Radius(R)//Constructor for Circle, initializing radius
    {
        CalculateArea();//Calling the CalculateArea function to calculate the area
        Display();//Calling Display function to show the area
    }
};

int main()//Main function
{
    int Choice = 1;//Variable for menu choice
    double A, B;//Variables for storing input values

    while (Choice != 0)//Loop for menu-driven program
    {
        cout << "\n\n-~Area Calculator~-"
             << "\nEnter 1 for area of Circle, 2 for area of Rectangle and 0 to Exit\n\nEnter Choice: ";
        cin >> Choice;//Taking input for menu choice

        if (Choice == 1)//If choice is 1, for Circle
        {
            cout << "\nEnter Circle Radius: ";
            cin >> A;//Taking input for Circle radius
            Shape* TempShape = new Circle(A);//Creating a Circle object dynamically
            delete TempShape;//Deleting the dynamically created Circle object to avoid memory leak
        }
        else if (Choice == 2)//If choice is 2, for Rectangle
        {
            cout << "\nEnter Rectangle Length: ";
            cin >> A;//Taking input for Rectangle length
            cout << "Enter Rectangle Width: ";
            cin >> B;//Taking input for Rectangle width
            Shape* TempShape = new Rectangle(A, B);//Creating a Rectangle object dynamically
            delete TempShape;//Deleting the dynamically created Rectangle object to avoid memory leak
        }
        else if (Choice == 0) //If choice is 0, exit the program
        {
            cout << "\nExiting System\n\n";
            cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
            break;//Breaking statement
        }
    }

    return 0;//Returning statement
}
