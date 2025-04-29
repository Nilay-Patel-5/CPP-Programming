/*Practical 07.4 : An educational institution requires a system to generate well-structured student performance reports from raw data stored in a file. The system should read student records,
including their name, marks, and grade, and present the information in a neatly formatted tabular format. Since the institution
handles large datasets, the report generation must be efficient, ensuring clear alignment and readability while allowing for future enhancements such as sorting and filtering.
To achieve this, the system must first handle file input operations, reading student data while ensuring error handling if the file is missing or inaccessible. The program should then format and
display the information in a structured manner, making use of a user-defined manipulator to align columns properly. This ensures that names, marks, and grades are clearly visible in the report,
regardless of data length variations.
For implementation, two approaches are explored. The first method processes the data directly from the file, formatting and displaying each entry without storing it in memory. This minimizes memory
usage but limits additional processing, such as sorting or filtering. The alternative approach dynamically stores student records using a manually managed data structure, allowing further
modifications, such as sorting by marks or filtering based on grades, before presenting the final formatted report.

Practical 07.5 : A university administration is developing a system to display student marks in a structured and visually appealing format. The goal is to ensure clarity in academic reports by
properly aligning names and scores while also demonstrating the use of currency formatting for tuition fees or other financial data. To achieve this, built-in stream manipulators such as endl, setw,
setfill, and setprecision must be used to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned in tabular form. Proper spacing between columns enhances readability, preventing misalignment
issues caused by varying name lengths or mark values. Additionally, numerical values must be displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in a standardized manner. To achieve this, the system includes a user-defined manipulator,
currency(), which prepends a specified currency symbol (₹, $, etc.) before displaying monetary values. This custom formatting ensures that financial data is both readable and professionally
presented.*/

// This program is prepared by 24CE089_NILAY PATEL.
// This program is prepared by 24CE089_NILAY PATEL.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    string Name;
    int Marks1, Marks2, Marks3;
    char Grade1, Grade2, Grade3;
    double TuitionFee;

    char GetGrade(int Marks) const {
        if (Marks >= 90) return 'A';
        if (Marks >= 75) return 'B';
        if (Marks >= 60) return 'C';
        if (Marks >= 50) return 'D';
        return 'F';
    }

public:
    void Input() {
        cout << "Enter student name: ";
        getline(cin >> ws, Name);  // ws consumes any leading whitespace

        cout << "Enter marks for subject 1: ";
        cin >> Marks1;
        Grade1 = GetGrade(Marks1);

        cout << "Enter marks for subject 2: ";
        cin >> Marks2;
        Grade2 = GetGrade(Marks2);

        cout << "Enter marks for subject 3: ";
        cin >> Marks3;
        Grade3 = GetGrade(Marks3);

        cout << "Enter tuition fee: ";
        cin >> TuitionFee;
    }

    void WriteToFile(ofstream& OutFile) const {
        OutFile << Name << "\n"
                << Marks1 << " " << Marks2 << " " << Marks3 << " " << TuitionFee << "\n";
    }

    bool ReadFromFile(ifstream& InFile) {
        if (!getline(InFile, Name)) return false;
        InFile >> Marks1 >> Marks2 >> Marks3 >> TuitionFee;
        InFile.ignore(); // consume the newline

        Grade1 = GetGrade(Marks1);
        Grade2 = GetGrade(Marks2);
        Grade3 = GetGrade(Marks3);
        return true;
    }

    void Display(ofstream& OutFile) const {
        OutFile << left << setw(20) << Name
                << setw(10) << Grade1
                << setw(10) << Grade2
                << setw(10) << Grade3
                << fixed << setw(14) << setprecision(2) << TuitionFee << endl;
    }

    static void PrintHeader(ofstream& OutFile) {
        OutFile << "\n\n"
                << setw(50) << right << "=== Student Performance Report ===\n\n";
        OutFile << left << setw(20) << "Name"
                << setw(10) << "Grade1"
                << setw(10) << "Grade2"
                << setw(10) << "Grade3"
                << setw(15) << "Tuition Fee" << endl;
        OutFile << string(65, '-') << endl;
    }
};

int main() {
    ofstream DataOut("students.txt");
    if (!DataOut) {
        cerr << "Could not open students.txt for writing.\n";
        return 1;
    }

    char More;
    do {
        Student S;
        S.Input();
        S.WriteToFile(DataOut);

        cout << "\nDo you want to enter another student? (y/n): ";
        cin >> More;
        cin.ignore();
    } while (tolower(More) == 'y');
    DataOut.close();

    ifstream DataIn("students.txt");
    ofstream Report("report.txt");
    if (!DataIn || !Report) {
        cerr << "Error opening file for reading/writing.\n";
        return 1;
    }

    Student::PrintHeader(Report);
    Student S;
    while (S.ReadFromFile(DataIn)) {
        S.Display(Report);
    }

    cout << "Report generated successfully in 'report.txt'.\n";
    return 0;
}
