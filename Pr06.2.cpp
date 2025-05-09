/*In a digital mapping application, a team of developers is working on a feature that allows objects to be repositioned dynamically on a coordinate plane. The application requires precise control over the movement of individual points representing user-defined markers. To achieve this, the team needs to design a system that allows a point’s coordinates to be adjusted efficiently while maintaining a fluid and chainable update mechanism.
To ensure seamless movement, the developers must implement a structure that allows each point to shift by specified offsets in the
x and y directions. Additionally, the solution should be designed in a way that supports method chaining, enabling multiple
transformations to be applied in a single statement. This requires careful handling of object references, utilizing this pointer
to return the updated object.
Furthermore, the implementation must be optimized for direct memory management, ensuring that objects are updated through
pass-by-reference using pointers.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output library
using namespace std;

class Coordinates//Creating class
{
//Private data-members
private:

    int X, Y;

//Making public functions for different tasks
public:

    Coordinates(int XVal = 0, int YVal = 0)//Constructor for initializing coordinate values
    {
        X = XVal;//Assigning value to X
        Y = YVal;//Assigning value to Y
    }

    Coordinates* Move(int Dx, int Dy)//Function for moving the point by specified dx and dy
    {
        X += Dx;//Incrementing X by Dx
        Y += Dy;//Incrementing Y by Dy

        return this;//Returning pointer to current object
    }


    void Display() const//Function for displaying the current coordinates
    {
        cout << "(" << X << ", " << Y << ")" << endl;//Printing coordinates
    }
};

int main()//Main function
{
    Coordinates* P = new Coordinates(5, 10);//Creating object dynamically with initial coordinates

    cout << "Initial Position: ";
    P->Display();//Displaying initial coordinates

    P->Move(3, -2)->Move(-1, 4)->Move(0, -5);//Chaining move operations

    cout << "Final Position: ";
    P->Display();//Displaying final coordinates

    delete P;//Freeing allocated memory

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

