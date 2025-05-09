/*In a rapidly growing software development firm, a team of engineers is tasked with building a lightweight, custom memory
management system for handling dynamic datasets. The existing framework lacks flexibility in managing arrays, often leading to
inefficient memory usage and performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at the end of the dataset and
removing specific elements based on their position. Since the system operates in a resource-constrained environment, using
standard template libraries is not an option, and direct dynamic memory management must be implemented using pointers. The
solution should ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary overhead.
The development team must carefully decide on the structure of their implementation, defining how data will be stored, accessed,
and modified efficiently. They need to outline the appropriate class design, determine essential data members, and define
necessary member functions to handle the operations effectively.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class DynamicArray//Creating class
{
    //Private data-members
    int* Data;//Pointer to store dynamic array
    int Size;//Stores current number of elements
    int Capacity;//Stores maximum capacity of array

    //Private member function to resize the array when full
    void Resize()//Function for doubling the capacity
    {
        Capacity *= 2;//Doubling the capacity

        int* NewData = new int[Capacity];//Creating new array with updated capacity

        for (int i = 0; i < Size; ++i)//Copying elements to new array
            NewData[i] = Data[i];

        delete[] Data;//Deleting old array to free memory

        Data = NewData;//Pointing to new array
    }

public:
    DynamicArray(int InitCapacity = 4)//Constructor to initialize the array with default capacity
    {
        Capacity = InitCapacity;//Setting initial capacity
        Size = 0;//Initializing size
        Data = new int[Capacity];//Allocating memory for array
    }

   ~DynamicArray() //Destructor to free allocated memory
    {
        delete[] Data;//Freeing dynamically allocated memory
    }

    void Insert(int Value)//Function for inserting a new value into the array
    {
        if (Size == Capacity)//Checking if array is full
            Resize();//Calling Resize function

        Data[Size++] = Value;//Inserting value and incrementing size
    }

    void Delete(int Index)//Function for deleting an element at a specific index
    {
        if (Index < 0 || Index >= Size)//If index is invalid...
        {
            cout << "Invalid index.\n";//Printing error message
            return;//Returning from function
        }

        for (int i = Index; i < Size - 1; ++i)//Shifting elements to left
            Data[i] = Data[i + 1];

        --Size;//Decreasing the size
    }

    void Display() const//Function for displaying all elements of the array
    {
        cout << "Array: ";//Printing label

        for (int i = 0; i < Size; ++i)//Loop for printing elements
            cout << Data[i] << " ";

        cout << endl;//Printing new line
    }
};

int main()//Main function
{
    DynamicArray Arr;//Creating object of class DynamicArray

    Arr.Insert(10);//Inserting element 10
    Arr.Insert(20);//Inserting element 20
    Arr.Insert(30);//Inserting element 30
    Arr.Insert(40);//Inserting element 40
    Arr.Display();//Displaying array

    Arr.Delete(1);//Deleting element at index 1
    Arr.Display();//Displaying updated array

    Arr.Insert(50);//Inserting element 50
    Arr.Display();//Displaying final array

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
