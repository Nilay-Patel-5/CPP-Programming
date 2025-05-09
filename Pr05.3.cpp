/*A team of software developers was tasked with creating a graphical simulation where operations on 2D points play a crucial role.
To facilitate this, they designed a class Point that encapsulates the coordinates 𝑥 and 𝑦. The class provides flexibility through
overloaded operators to manipulate points efficiently. The unary operator - is overloaded to negate the coordinates of a point,
while the binary operator + enables the addition of two points. Additionally, the equality operator == is overloaded to compare
whether two points have identical coordinates.
The development process required performing various operations between multiple points. To manage these operations effectively, a
mechanism was needed to track and potentially undo them. This challenge prompted two approaches: using a ready-made dynamic stack
structure or building a custom stack implementation. By managing a sequence of operations in reverse, the stack-based design
allowed for a systematic undo capability, crucial for simulations involving iterative adjustments.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output library
using namespace std;

class Cordinates//Creating class
{
//Public data members and functions
public:
    int X, Y;//Variables for coordinates

    void GetCordinates()//Function for taking input of coordinates
    {
        cout << "Enter X and Y coordinates e.g (X Y): ";
        cin >> X >> Y;//Taking input
    }

    void operator+(Cordinates &C1)//Overloading + operator for coordinate addition
    {
        Cordinates C;//Temporary object

        C.X = X + C1.X;//Adding X coordinates
        C.Y = Y + C1.Y;//Adding Y coordinates

        cout << "X Coordinate after addition: " << C.X << endl;
        cout << "Y Coordinate after addition: " << C.Y << endl;
    }

    void operator-(Cordinates &C1)//Overloading - operator for coordinate subtraction
    {
        Cordinates C;//Temporary object

        C.X = X - C1.X;//Subtracting X coordinates
        C.Y = Y - C1.Y;//Subtracting Y coordinates

        cout << "X Coordinate after subtraction: " << C.X << endl;
        cout << "Y Coordinate after subtraction: " << C.Y << endl;
    }

    void operator==(Cordinates &C1)//Overloading == operator for coordinate comparison
    {
        if (X == C1.X && Y == C1.Y)//Checking if coordinates are equal
            cout << "The coordinates are equal" << endl;
        else
            cout << "The coordinates are not equal" << endl;
    }
};

int main()//Main function
{
    Cordinates N1, N2;//Creating objects

    N1.GetCordinates();//Calling GetCordinates function for N1
    N2.GetCordinates();//Calling GetCordinates function for N2

    N1 + N2;//Using overloaded + operator
    N1 - N2;//Using overloaded - operator
    N1 == N2;//Using overloaded == operator

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

