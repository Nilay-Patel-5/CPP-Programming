/*A university administration is developing a system to display student marks in a structured and visually appealing format. The
goal is to ensure clarity in academic reports by properly aligning names and scores while also demonstrating the use of currency
formatting for tuition fees or other financial data. To achieve this, built-in stream manipulators such as endl, setw, setfill,
and setprecision must be used to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned in tabular form. Proper
spacing between columns enhances readability, preventing misalignment issues caused by varying name lengths or mark values.
Additionally, numerical values must be displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in a standardized manner. To
achieve this, the system includes a user-defined manipulator, currency(), which prepends a specified currency symbol (₹, $, etc.)
before displaying monetary values. This custom formatting ensures that financial data is both readable and professionally
presented.*/

//This program is prepared by 24CE089_NILAY PATEL.
#include <iostream>//Standard Input/Output Library
#include <iomanip>//Formatting Library

using namespace std;

ostream& Currency(ostream& Os) //Function for formating currency output
{
    return Os << "  Rs.";//Returning currency prefix
}

int main()//Main function
{
    const int NumStudents = 4;//Number of students
    string Names[NumStudents] = {"DIPAK", "RAJESH", "DINESH", "RAKESH"};//Array of student names
    double Marks[NumStudents] = {90.5, 78.0, 85.75, 65.3};//Array of student marks
    double TuitionFees[NumStudents] = {25000.50, 18000.75, 22000.00, 20000.00};//Array of tuition fees

    cout << setw(15) << left << "Name" << setw(10) << "Marks" << setw(15) << "\tTuition Fees" << endl;//Printing headers
    cout << "-----------------------------------------------" << endl;//Printing separator

    for (int i = 0; i < NumStudents; ++i)//Loop through students
    {
        cout << setw(15) << left << Names[i]//Printing name
             << setw(15) << fixed << setprecision(2) << Marks[i]//Printing marks
             << setw(6) << Currency << TuitionFees[i] << endl;//Printing formatted tuition fee
    }

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

