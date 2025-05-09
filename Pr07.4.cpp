/*An educational institution requires a system to generate well-structured student performance reports from raw data stored in a
file. The system should read student records, including their name, marks, and grade, and present the information in a neatly
formatted tabular format. Since the institution
handles large datasets, the report generation must be efficient, ensuring clear alignment and readability while allowing for
future enhancements such as sorting and filtering.
To achieve this, the system must first handle file input operations, reading student data while ensuring error handling if the
file is missing or inaccessible. The program should then format and display the information in a structured manner, making use of
a user-defined manipulator to align columns properly. This ensures that names, marks, and grades are clearly visible in the
report, regardless of data length variations.
For implementation, two approaches are explored. The first method processes the data directly from the file, formatting and
displaying each entry without storing it in memory. This minimizes memory usage but limits additional processing, such as sorting
or filtering. The alternative approach dynamically stores student records using a manually managed data structure, allowing
further modifications, such as sorting by marks or filtering based on grades, before presenting the final formatted report.*/

//This program is prepared by 24CE089_NILAY PATEL.
#include <iostream>//Standard Input/Output Library
#include <fstream>//File handling Library
#include <iomanip>//Formatting Library

using namespace std;

ostream& Tab(ostream& Os)//Function for formating output using setw
{
    return Os << setw(15) << left;//Returning formatted output
}

int main()//Main function
{
    ifstream File("students.txt");//Opening file for reading

    if (!File)//If file cannot be opened...
    {
        cout << "Error: Could not open file.\n";//Displaying error message
        return 1;//Exiting program with error
    }

    char Name[50];//Variable for student name
    int Marks;//Variable for student marks
    char Grade;//Variable for student grade

    cout << Tab << "Name" << Tab << "Marks" << Tab << "Grade" << endl;//Printing table headers
    cout << "-------------------------------------------" << endl;//Printing separator line

    while (File >> Name >> Marks >> Grade)//Reading file until end
    {
        cout << Tab << Name << Tab << Marks << Tab << Grade << endl;//Displaying student details
    }

    File.close();//Closing the file

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
    return 0;//Return statement
}
