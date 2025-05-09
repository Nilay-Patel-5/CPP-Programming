/*A mathematical research group aimed to create a software model for handling and performing operations on complex numbers
efficiently. To achieve this, they designed a Complex class that encapsulates the real and imaginary parts of a complex number.
The class supports essential operator overloading to enhance usability, including the addition and subtraction of complex numbers
and custom input and output functionality through the << and >> operators. These overloaded operators ensure seamless arithmetic
and user interaction with the system.
The task involves implementing this system and exploring its capabilities by performing various operations on complex numbers.
Participants are expected to overload the specified operators and use them to add and subtract complex numbers, as well as to
facilitate user-friendly input and output. Additionally, the solution encourages experimenting with managing collections of
complex numbers to perform batch operations.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream> //Standard Input/Output library
using namespace std;

class Complex//Creating class
{
//Public data members and functions
public:
    int RealPart,ImgnaryPart;//Variable declaration for real and imaginary parts

    void Input()//Function for taking input of complex number
    {
        cout << "Enter number (Real and Imaginary part): ";
        cin >> RealPart >> ImgnaryPart;//Taking input
    }

    void operator+(Complex &B)//Overloading + operator for complex addition
    {
        Complex Ans;//Temporary object to store result

        Ans.RealPart = RealPart + B.RealPart;//Addition of real parts
        Ans.ImgnaryPart = ImgnaryPart + B.ImgnaryPart;//Addition of imaginary parts

        cout << "Summation of complex numbers: " << Ans.RealPart << "+" << Ans.ImgnaryPart << "i" << endl;//Printing result
    }
};

int main()//Main function
{
    Complex A, B, X;//Creating objects of class

    A.Input();//Calling input function for first complex number
    B.Input();//Calling input function for second complex number

    A + B;//Using overloaded + operator

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
