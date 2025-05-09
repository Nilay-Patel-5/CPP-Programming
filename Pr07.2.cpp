/*A data analysis firm is developing a tool to process large text files and extract key statistics, such as the total number of
characters, words, and lines. This tool is essential for tasks like document indexing, text summarization, and data validation.
Given the varying sizes of input files, the system must handle large datasets efficiently while ensuring error detection when
files are missing or inaccessible.
To begin, the program needs to open a specified text file and process its contents line by line. If the file cannot be found or
opened due to permission issues, the system should notify the user with an appropriate error message and safely terminate
execution. Once the file is successfully accessed, the program will analyze its contents to count the total number of lines,
extract words while handling different delimiters, and compute the total number of characters, including spaces and punctuation.
For handling this data, the team explores two approaches. One approach dynamically stores the lines in a manually managed array,
processing the information without relying on built-in containers. This requires careful memory allocation and deallocation to
avoid leaks. The alternative approach uses a dynamic structure to hold the lines in memory, allowing for efficient access and
further analysis, such as searching or editing.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output Library
#include <fstream>//File handling Library
#include <cstring>//String handling Library

using namespace std;

int main()//Main function
{
    const int MaxLine = 1000;//Constant for maximum characters in a line
    char FileName[100];//Character array to store file name

    cout << "Enter file name: ";//Prompt user to enter file name
    cin >> FileName;//Taking input of file name

    ifstream File(FileName);//Opening file using ifstream

    if (!File)//If file cannot be opened...
    {
        cout << "Error: Cannot open file." << endl;//Error message
        return 1;//Exiting with error
    }

    char* Line = new char[MaxLine];//Dynamic memory for line
    int LineCount = 0;//Counter for lines
    int WordCount = 0;//Counter for words
    int CharCount = 0;//Counter for characters

    while (File.getline(Line, MaxLine))//Reading line from file
    {
        LineCount++;//Incrementing line count
        CharCount += strlen(Line);//Adding length of line to character count
        CharCount++;//Counting newline character

        char* Token = strtok(Line, " \t\n\r,.!?;:");//Tokening line to count words
        while (Token != NULL)//Loop through all tokens
        {
            WordCount++;//Incrementing word count
            Token = strtok(NULL, " \t\n\r,.!?;:");//Next token
        }
    }

    //Displaying statistics
    cout << "\nStatistics:\n";
    cout << "Lines: " << LineCount << endl;
    cout << "Words: " << WordCount << endl;
    cout << "Characters: " << CharCount << endl;

    delete[] Line;//Freeing dynamically allocated memory
    File.close();//Closing file

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
