/*A software development team aimed to design a versatile utility that could perform basic arithmetic operations while
demonstrating the concept of function overloading. This effort resulted in a class-based calculator system capable of handling
various combinations of input types, such as integers and floating-point numbers. The system includes multiple overloaded add
functions, each tailored to accept distinct input types and perform addition operations accordingly. This approach ensures the
calculator is adaptable and provides consistent functionality regardless of the input types.
The case revolves around testing and validating the versatility of this calculator. Participants are expected to create instances
of the calculator, invoke the appropriate overloaded functions for various input scenarios, and store the resulting values for
further analysis. To organize and display these results, the system incorporates methods to sequentially process and present the
outcomes.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output Library
using namespace std;

class Calculator//Creating class
{
//Public functions for performing operations
public:

    int AddNumbers(int Num1, int Num2)//Function for adding two integers
    {
        return Num1 + Num2;//Returning the sum of two integers
    }

    float AddNumbers(float Fnum1, float Fnum2)//Function for adding two floating-point numbers
    {
        return Fnum1 + Fnum2;//Returning the sum of two floats
    }
};

int main()//Main function
{
    Calculator Cal;//Creating object of Calculator class

    int Choice, Number1, Number2, Answer;//Variable declaration for integer operation
    float Fnumber1, Fnumber2, Fanswer;//Variable declaration for float operation

    //Printing menu
    cout << "Enter 1 to add integers" << endl;
    cout << "Enter 2 to add floating-point numbers" << endl;
    cout << "Enter your Choice : ";
    cin >> Choice;//Taking input from user

    switch (Choice)//Switch case for choice selection
    {
        case 1://Case for adding integers
        {
            cout << "Enter 1st number : ";
            cin >> Number1;//Taking input of first integer
            cout << "Enter 2nd number : ";
            cin >> Number2;//Taking input of second integer

            Answer = Cal.AddNumbers(Number1, Number2);//Calling AddNumbers function for integers

            cout << "Summation of 2 integer numbers is " << Answer << endl;//Printing result

            break;//Break statement
        }

        case 2://Case for adding floating-point numbers
        {
            cout << "Enter 1st number : ";
            cin >> Fnumber1;//Taking input of first float
            cout << "Enter 2nd number : ";
            cin >> Fnumber2;//Taking input of second float

            Fanswer = Cal.AddNumbers(Fnumber1, Fnumber2);//Calling AddNumbers function for floats

            cout << "Summation of 2 floating-point numbers is " << Fanswer << endl;//Printing result

            break;//Break statement
        }

        default://Default case for invalid choice
        {
            cout << "INVALID CHOICE" << endl;//Printing error message
        }
    }

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

