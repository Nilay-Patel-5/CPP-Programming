/*A financial analytics company is working on a system that processes large volumes of sorted numerical data from different
sources. The challenge is to efficiently combine two independently sorted datasets into a single, fully sorted dataset while
ensuring optimal memory management. Since the size of the datasets varies dynamically based on incoming data streams, the solution
must be flexible and manage memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two sorted arrays of different sizes and merges
them into a new dynamically allocated array while maintaining the sorted order. The system should read input values specifying the
sizes of both datasets, followed by the elements of each array. After merging, the final sorted array should be displayed as
output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete operators for dynamic allocation
and deallocation of memory.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output library
using namespace std;

void MergeSortedArrays(int* Arr1, int Size1, int* Arr2, int Size2)//Creating function
{
    int* MergedArr = new int[Size1 + Size2];//Dynamic array to store merged result
    int i = 0, j = 0, k = 0;//Variable declarations

    while (i < Size1 && j < Size2)//Loop for merging elements in sorted order
    {
        if (Arr1[i] < Arr2[j])//If element of Arr1 is smaller...
        {
            MergedArr[k++] = Arr1[i++];//Storing Arr1 element and increment indexes
        }
        else//If not...
        {
            MergedArr[k++] = Arr2[j++];//Storing Arr2 element and increment indexes
        }
    }

    while (i < Size1)//Loop for remaining elements of Arr1
    {
        MergedArr[k++] = Arr1[i++];//Storing remaining Arr1 elements
    }

    while (j < Size2)//Loop for remaining elements of Arr2
    {
        MergedArr[k++] = Arr2[j++];//Storing remaining Arr2 elements
    }

    cout << "Merged Sorted Array: ";//Printing message
    for (int l = 0; l < Size1 + Size2; ++l)//Loop for displaying merged array
    {
        cout << MergedArr[l] << " ";//Printing merged elements
    }
    cout << endl;//New line

    delete[] MergedArr;//Deallocating memory
}

int main()//Main function
{
    int Size1, Size2;//Variable declarations

    cout << "Enter size of first sorted array: ";
    cin >> Size1;//Taking input of size

    int* Arr1 = new int[Size1];//Dynamic memory allocation

    cout << "Enter elements of first sorted array: ";
    for (int i = 0; i < Size1; ++i)//Loop for input
    {
        cin >> Arr1[i]; //Taking input of elements
    }

    cout << "Enter size of second sorted array: ";
    cin >> Size2;//Taking input of size

    int* Arr2 = new int[Size2];//Dynamic memory allocation

    cout << "Enter elements of second sorted array: ";
    for (int i = 0; i < Size2; ++i)//Loop for input
    {
        cin >> Arr2[i];//Taking input of elements
    }

    MergeSortedArrays(Arr1, Size1, Arr2, Size2);//Calling function

    delete[] Arr1;//Deallocating memory
    delete[] Arr2;//Deallocating memory

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
