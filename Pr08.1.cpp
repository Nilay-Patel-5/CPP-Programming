/*A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key requirements is to
reverse a given sequence of integers while ensuring optimized performance using modern C++ techniques. The system should allow
users to input a sequence of numbers, process the reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse() function, which
efficiently reverses elements within a dynamically managed sequence. The second approach involves manually implementing the
reversal using iterators, providing deeper insight into how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently. Iterators facilitate traversal and
modification, ensuring that elements are manipulated without direct indexing.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream> //Standard Input/Output library
#include<algorithm>//For using reverse function
#include<vector>//For using vector container

using namespace std;

int main() //Main function
{
    //Variable declaration
    int Integer, i, j, Temp;//Variables for loop and swapping
    vector<int> V1, V2;//Vectors for storing original and copied array

    cout << "Enter your integer array and press 0 to stop" << endl;

    for (i = 0; ; i++)//Loop for taking input
    {
        cin >> Integer;//Taking input of integers

        if (Integer == 0)//If input is 0, stop taking input
        {
            break;//Break statement
        }

        V1.push_back(Integer);//Storing input into V1 vector
        V2.push_back(Integer);//Storing input into V2 vector
    }

    reverse(V1.begin(), V1.end());//Reversing array using inbuilt function

    j = V2.size() - 1;//Setting end index for iterative reversal

    for (i = 0; i < V2.size() / 2; i++, j--)//Loop for reversing using swapping
    {
        Temp = V2[i];//Swapping elements
        V2[i] = V2[j];
        V2[j] = Temp;
    }

    cout << "Reversed array through reverse function: ";//Output using reverse()
    for (i = 0; i < V1.size(); i++)//Loop for displaying V1
    {
        cout << V1[i] << " ";//Printing element
    }

    cout << endl;//Line break

    cout << "Reversed array through iterative method: ";//Output using manual reversal
    for (i = 0; i < V2.size(); i++)//Loop for displaying V2
    {
        cout << V2[i] << " ";//Printing element
    }

    cout << endl;//Line break

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
