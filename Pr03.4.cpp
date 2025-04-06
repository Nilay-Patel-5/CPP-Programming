/*A technology firm aimed to develop a flexible and reusable solution for managing collections of various data types, including integers, floating-point
numbers, and characters. The system was intended to perform fundamental operations on these collections, such as finding the maximum value, reversing the
collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the solution was designed to use function templates, allowing
the same logic to be applied seamlessly to different data types.
The team recognized the importance of using dynamic arrays to store the collections, enabling efficient management of varying collection sizes. The design
emphasized scalability and flexibility, ensuring that the system could handle different data types and their associated operations with minimal changes to
the core logic.
In practice, the system allowed for the creation of collections for various data types, such as integers, floating-point numbers, and characters. The
operations on these collections included determining the maximum value, reversing the order of elements, and printing the collection contents.*/

//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

template<typename T>//Template declaration
void InputData(T* Data,int Size)//Function for entering data elements
{
    for (int i = 0; i < Size; ++i)//Loop for taking data elements
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> Data[i];//Taking input of data elements
    }
}

template<typename T>//Template declaration
T GetElements(int Size,T* Data)//Function for returning/handling entered data elements
{
    int Count;//Number of elements

    if(Count >= 0 && Count < Size)//If Count variable is greater or equal to 0 & less than size of data elements...
    {
        return Data[Count];//Returning data elements
    }
}

template<typename T>//Template declaration
T FindMax(int Size,T* Data)//Function for finding max value from set of data elements
{
    T MaxValue = Data[0];//Initializing first data entry to max value

    for(int i = 1; i < Size; ++i)//Loop for searching max value
    {
        if(Data[i] > MaxValue)//If any data entry is greater than max value
        {
            MaxValue = Data[i];//Giving value to max value
        }
    }

    return MaxValue;//Returning max value
}

template<typename T>//Template declaration
void ReverseData(int Size,T* Data)//Function for reversing data elements
{
    for(int Start = 0,End = Size-1; Start < End ; ++Start, --End)//Loop for replacing data elements with each-other
    {
        //Replacing data elements with each-other
        T Temp = Data[Start];
        Data[Start] = Data[End];
        Data[End] = Temp;
    }
}

template<typename T>//Template declaration
void DisplayData(int Size,T* Data)//Function for displaying data elements
{
    for (int i = 0; i < Size; ++i)//Loop for displaying all data elements
    {
        cout << Data[i] << " ";//Printing data elements
    }
    cout << endl;//End statement
}

template<typename T>//Template declaration
void PerformOperations(int Size)//Function for performing all operations/calling function
{
    T* Data;//Pointer variable declaration
    Data = new T[Size];//Dynamic allocation by new

    InputData(Data,Size);//Calling InputData function

    cout << "Entered data: ";
    DisplayData(Size,Data);//Calling DisplayData function

    T MaxValue = FindMax(Size,Data);//Assigning value, returned from function
    cout << "Max Value: " << MaxValue << endl;//Printing max value from set of data elements

    cout << "Reversed Data: ";
    ReverseData(Size,Data);//Calling ReverseData function
    DisplayData(Size,Data);//Calling DisplayData function

    delete[] Data;//Free up Data named array of pointer
}

int main()//Main function
{
    int Size;//Variable for no. of data elements
    cout << "Enter the no. of elements: ";
    cin >> Size;//Taking input of no. of data elements

    char DataType;//Character variable for data-type
    cout << "Enter the data type (i = int, f = float, c = char): ";
Next ://Label
    cin >> DataType;//Taking input for data-type

    if (DataType == 'i')//If entered character in i...
    {
        PerformOperations<int>(Size);//Calling PerformOperations function for int value
    }
    else if (DataType == 'f')//If entered character in f...
    {
        PerformOperations<float>(Size);//Calling PerformOperations function for float value
    }
    else if (DataType == 'c')//If entered character in c...
    {
        PerformOperations<char>(Size);//Calling PerformOperations function for character value
    }
    else//If not...
    {
        cout << "Invalid data type! re-enter data type: ";//Printing error message
        goto Next;//Goto statement
    }

    cout << "24CE089_NILAY PATEL." << endl;//Exiting message

    return 0;//Return statement
}
