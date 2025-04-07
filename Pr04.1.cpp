/*A team of engineers was tasked with developing a program to calculate and manage the areas of multiple circles for a design project. To achieve this,
they devised a solution using a structured, object-oriented approach. At the foundation of their solution was a base class that represented a generic
shape, responsible for storing and managing the radius of the circle. Building upon this, a specialized class for circles was created to extend
functionality by introducing a method for calculating the area of a circle based on its radius. Using this framework, the team designed a system to handle
multiple circles, ensuring that the process of storing, calculating, and displaying the areas was efficient and adaptable. They explored two different
approaches for managing the collection of circles—one focusing on flexibility and dynamic handling, while the other used a more static structure. By
implementing and comparing these methods, the engineers gained insights into the benefits of using efficient techniques for organizing and processing
geometric data, enhancing their problem-solving capabilities.*/

//This program is prepared by 24CE089_NILAY PATEL.
#include<iostream>//Standard input/output library
using namespace std;

class Shape//Creating class
{
    //Private data-members
    float Radius;

//Making public functions for different tasks
public:

    void InputRadius()//Function for taking input of radius
    {
        cout << "Enter radius: ";
        cin >> Radius;//Taking input of radius
    }

    int GetRadius()//Function for returning radius
    {
        return Radius;//Returning radius
    }
};

class Circle : private Shape//Creating class with a parent class
{
    //Private data-members
    float Area;

//Making public functions for different tasks
public:

    void CalculateArea()//Function for calculating area
    {
        InputRadius();//Calling InputRadius internally
        Area = 3.14*GetRadius()*GetRadius();//Calculating area
    }

    void DisplayArea()//Function for displaying area
    {
        cout << "Area of circle: " << Area << endl;//Printing area
    }
};

int main()//Main function
{
    class Circle C;//Creating object

    //C.InputRadius();
    C.CalculateArea();//Calling CalculateArea function
    C.DisplayArea();//Calling DisplayArea function

    cout << "24CE089_NILAY PATEL." << endl;

    return 0;//Return statement
}
