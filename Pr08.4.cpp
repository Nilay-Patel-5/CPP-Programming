/*An educational institution is developing a system to rank students based on their scores in an examination. The goal is to
efficiently store student names along with their respective scores, sort the records in descending order based on scores, and
display the ranked list. The system should be flexible enough to handle varying numbers of students dynamically.
To achieve this, the system associates each student’s name with their score using a structured data representation. A dynamically
re-sizable sequence is chosen to store student records, allowing efficient insertion and retrieval of entries. Each entry
consists
of a name-score pair, ensuring logical grouping of related information.
Once the data is collected, a sorting operation is performed using a custom comparison function. By leveraging an efficient
sorting algorithm, the system ensures that students with the highest scores appear at the top of the list. Iterators are then
used to traverse and display the sorted data in a structured format, highlighting rank-based ordering.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output library
#include <vector>//Library for using vector container
#include <algorithm>//Library for using sort function

using namespace std;

struct Student//Creating structure
{
    string Name;//Variable for name of the student
    int Score;//Variable for score of the student
};

//Function for comparing scores of students
bool CompareByScore(const Student& A, const Student& B)
{
    return A.Score > B.Score;//Comparison to sort in descending order
}

int main()//Main function
{
    int N;//Variable to store number of students

    cout << "Enter the number of students: ";
    cin >> N;//Taking input of number of students

    vector<Student> Students;//Creating vector to store student records
    Student Temp;//Temporary student variable for input

    cout << "Enter student name and score:\n";
    for (int i = 0; i < N; ++i)//Loop to input student data
    {
        cin >> Temp.Name >> Temp.Score;//Taking input of name and score
        Students.push_back(Temp);//Storing student data into vector
    }

    //Sorting student records based on score in descending order
    sort(Students.begin(), Students.end(), CompareByScore);

    //Displaying ranked list of students
    cout << "\nRanked Student List:\n";
    for (int i = 0; i < Students.size(); ++i)//Loop for displaying student data
    {
        cout << i + 1 << ". " << Students[i].Name << " - " << Students[i].Score << endl;//Printing name and score
    }

    cout << "\n24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
