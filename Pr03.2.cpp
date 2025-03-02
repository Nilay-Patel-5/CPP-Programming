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

int main()//Mainfunction
{
    int n;//Variable for array size

    cout << "Enter the size of the array: ";
    cin >> n;//Taking input of array size

    int* Array = new int[n];//Initializing new size to Array variable

    cout << "Enter " << n << " elements of the array: ";

    for (int i = 0; i < n; ++i)//Loop for taking input of Array elements
    {
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
