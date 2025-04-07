/*A data analytics company was tasked with developing a unique digital signature system based on the concept of "super digits." The system required finding
a single-digit representation of a given number through recursive digit summation. The algorithm was defined as follows:
If the number has only one digit, it is its super digit. Otherwise, the super digit is the super digit of the sum of its digits, repeated recursively until
a single digit is obtained.
The challenge involved an additional complexity—constructing the number by concatenating a given string representation of an integer multiple times. For
example, if the number n was represented as a string and concatenated k times, the super digit of the resulting number needed to be calculated.
For instance:
Given n = 9875 and k = 4, the number is represented as 9875987598759875.
The sum of digits in this number is calculated recursively until a single digit remains:
9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 = 116
1 + 1 + 6 = 8
The super digit is 8.
The system was required to handle large numbers efficiently by leveraging mathematical insights rather than explicitly constructing large concatenated
strings. This case study called for implementing a recursive solution to calculate the super digit, supported by a mathematical approach to optimize the
handling of repeated sums.*/

//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

int CalculateSumOfDigits(int Number)//Function for calculating sum of digits
{
    int Sum = 0;//Variable for sum & initializing with 0

    while(Number > 0)//If no. is greater than 0...
    {
        Sum += Number % 10;//Calculating sum
        Number /= 10;//Calculating no.
    }

    return Sum;//Returning sum
}

int CalculateSuperDigit(int Number)//Function for calculating super digit
{
    if(Number < 10)//If number is less than 10
    {
        return Number;//Returning no.
    }

    int Sum = 0;//Variable for sum & initializing with 0

    while(Number > 0)//If no. is greater than 0...
    {
        Sum += Number % 10;//Calculating sum
        Number /= 10;//Calculating no.
    }

    return CalculateSuperDigit(Sum);//Returning/Recursing CalculateSuperDigit function
}

int main()//Main function
{
    int Num,NumRepeat;//Variables for no. & number of repetitions(k)

    cout << "Enter number(n): ";
    cin >> Num;//Taking input no.

    cout << "Enter the number of repetitions(k): ";
    cin >> NumRepeat;//Taking input of number of repetitions(k)

    //Variable for sum
    int Sum = CalculateSumOfDigits(Num);//Initializing with returned value from CalculateSumOfDigits function

    //Variable for total sum
    int TotalSum = Sum*NumRepeat;//Calculating total sum

    //Variable for super digit
    int SuperDigit = CalculateSuperDigit(TotalSum);//Initializing with returned value from CalculateSuperDigit function

    cout << "Super digit: " << SuperDigit << endl;//Printing super digit

    cout << "24CE089_NILAY PATEL." << endl;//Exiting message

    return 0;//Return statement
}
