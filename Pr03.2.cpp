/*A software development company was tasked with conducting a performance analysis of recursive algorithms versus their iterative counterparts. The
specific focus was on calculating the sum of integers in an array, where the array's size and elements were to be provided dynamically by the user. To
facilitate memory management and enable dynamic resizing of the array, the team decided to use a flexible container for storing the array elements.
The system was designed to first prompt users for the array's size and then request the input of individual elements. A recursive function was to be
implemented to compute the sum by dividing the problem into smaller sub-problems, recursively summing subsets of the array until reaching the base
case. In addition to the recursive implementation, an iterative version of the function would be created for comparison.
The main objective of the study was to assess and compare the computational performance and implementation complexity of both recursive and non-recursive
approaches. By evaluating execution times, memory usage, and code complexity, the team hoped to gain insights into the trade-offs between recursion and
iteration, particularly in terms of efficiency and applicability to real-world problems.*/

//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard input/output library
using namespace std;

int SumRecursive(int Array[],int n)//Function for recursive sum
{
    if(n == 0)//If array size equals to 0
    {
        return 0;//Return statement
    }

    return Array[n-1] + SumRecursive(Array,n-1);//Returning addition of entered two numbers
}

int SumIterative(int Array[],int n)//Function for recursive sum
{
    int Total = 0;//Variable for total & initializing to to 0

    for(int i = 0; i < n; ++i)//Loop for addition of entered numbers
    {
        Total += Array[i];//Adding entered numbers to total
    }

    return Total;//Returning total
}

int main()//Main function
{
    int n;//Variable for array size

    cout << "Enter the size of the array: ";
    cin >> n;//Taking input of array size

    int* Array = new int[n];//Initializing new size to Array variable

    for (int i = 0; i < n; ++i)//Loop for taking input of Array elements
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> Array[i];//Taking input of Array elements
    }

    int RecursiveSum = SumRecursive(Array,n);//Variable for recursive sum & calling SumRecursive function

    cout << "Sum using recursion: " << RecursiveSum << endl;//Printing recursive sum

    int IterativeSum = SumIterative(Array,n);//Variable for iterative sum & calling SumIterative function

    cout << "Sum using iteration: " << IterativeSum << endl;//Printing iterative sum

    delete[] Array;//Releasing size of Array variable

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
