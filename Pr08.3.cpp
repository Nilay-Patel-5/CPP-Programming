/*A financial analytics firm is designing a data processing system to filter out duplicate transaction IDs from large datasets.
The system must take an input list of integers, efficiently remove duplicates, and display the unique values in an ordered manner.
Given the need for high performance in handling large datasets, the implementation must leverage efficient data structures that
automatically eliminate redundancy.
To achieve this, the system employs an associative container that inherently ensures uniqueness while maintaining a sorted order.
As integers are added, duplicate entries are automatically discarded, eliminating the need for explicit duplicate-checking logic.
Once the unique values are identified, they are either displayed directly using iterators or converted back into a dynamically
managed sequence for further processing.
By utilizing iterators, the system efficiently traverses the filtered dataset, ensuring that unique elements are accessed and
displayed without additional computational overhead.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#include<set>//Set library for storing unique values

using namespace std;

int main()//Main function
{
    int N,Num;//Variable declarations

    cout << "Enter the number of transaction IDs: ";
    cin >> N;//Taking input of number of transaction IDs

    set<int> UniqueIDs;//Creating set to store unique transaction IDs

    cout << "Enter the transaction IDs: ";
    for (int i = 0; i < N; ++i)//Loop for taking transaction ID input
    {
        cin >> Num;//Taking transaction ID
        UniqueIDs.insert(Num);//Inserting into set (duplicates are ignored)
    }

    cout << "\nUnique Transaction IDs (sorted):\n";
    for (int Id : UniqueIDs)//Loop for displaying unique transaction IDs
    {
        cout << Id << " ";//Printing transaction ID
    }
    cout << endl;//New line statement

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

