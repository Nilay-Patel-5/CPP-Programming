#include<iostream>
using namespace std;

template<typename T>
void InputData(T* Data,int Size)
{
    cout << "Enter " << Size << " elements: ";
    for (int i = 0; i < Size; ++i)
    {
        cin >> Data[i];
    }
}

template<typename T>
T GetElements(int Size,T* Data)
{
    int Count;

    if(Count >= 0 && Count < Size)
    {
        return Data[Count];
    }
}

template<typename T>
T FindMax(int Size,T* Data)
{
    T MaxValue = Data[0];

    for(int i = 1; i < Size; ++i)
    {
        if(Data[i] > MaxValue)
        {
            MaxValue = Data[i];
        }
    }

    return MaxValue;
}

template<typename T>
void ReverseData(int Size,T* Data)
{
    for(int Start = 0,End = Size-1; Start < End ; ++Start, --End)
    {
        T Temp = Data[Start];
        Data[Start] = Data[End];
        Data[End] = Temp;
    }
}

template<typename T>
void DisplayData(int Size,T* Data)
{
    for (int i = 0; i < Size; ++i)
    {
        cout << Data[i] << " ";
    }
    cout << endl;
}

template<typename T>
void PerformOperations(int Size)
{
    T* Data;
    Data = new T[Size];

    InputData(Data,Size);

    cout << "Entered data: ";
    DisplayData(Size,Data);

    T MaxValue = FindMax(Size,Data);
    cout << "Max Value: " << MaxValue << endl;

    cout << "Reversed Data: ";
    ReverseData(Size,Data);
    DisplayData(Size,Data);

    delete[] Data;
}

int main()
{
    int Size;
    cout << "Enter the no. of elements: ";
    cin >> Size;

    char DataType;
    cout << "Enter the data type (i = int, f = float, c = char): ";
Next :
    cin >> DataType;

    if (DataType == 'i')
    {
        PerformOperations<int>(Size);
    }
    else if (DataType == 'f')
    {
        PerformOperations<float>(Size);
    }
    else if (DataType == 'c')
    {
        PerformOperations<char>(Size);
    }
    else
    {
        cout << "Invalid data type! re-enter data type: ";
        goto Next;
    }

    cout << "24CE089_NILAY PATEL" << endl;

    return 0;
}
