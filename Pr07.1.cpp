/*A media research team is developing a tool to analyze word frequency in large textual datasets, such as news articles and
research papers. The goal is to process a given paragraph, identify individual words, and count their occurrences while ensuring
case-insensitive matching. Since the tool is intended for both constrained environments and high-performance systems, two
different approaches are considered—one utilizing dynamic memory management and another relying on manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string. Once acquired, the text must
be split into individual words, ensuring that uppercase and lowercase variations are treated as the same. To store and process
words dynamically, the team designs a
mechanism using raw pointers and dynamic memory allocation, allowing the program to handle variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count occurrences efficiently.
The array expands as needed, ensuring that new words can be accommodated. The frequency counting is implemented manually by
searching for existing words in the array and updating counts accordingly.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output Library
#include <cctype>//Library for character handling
#include <cstring>//Library for string handling

using namespace std;

//Function for converting all characters of a word to lowercase
void ConvertToLower(char* Str)
{
    for (int i = 0; Str[i]; ++i)
        Str[i] = tolower(Str[i]);//Converting each character to lowercase
}

//Function for checking equality of two strings
bool CheckEquality(const char* A, const char* B)
{
    return strcmp(A, B) == 0;//Returning true if both strings are same
}

int main()//Main function
{
    const int MaxLen = 1000;//Constant for max input length
    char Input[MaxLen];//Character array to store input paragraph

    cout << "Enter a paragraph: ";//Prompt for entering paragraph
    cin.getline(Input, MaxLen);//Taking input from user

    char* Words[500];//Array of pointers to store unique words
    int Counts[500] = {0};//Array for frequency of each word
    int Unique = 0;//Variable for counting unique words

    char* Token = strtok(Input, " ,.-!?");//Tokening the input based on delimiters

    while (Token != NULL)//Loop until all words are tokenized
    {
        ConvertToLower(Token);//Converting token to lowercase
        bool Found = false;//Flag for indicating if word is already counted

        for (int i = 0; i < Unique; ++i)//Loop through unique words
        {
            if (CheckEquality(Words[i], Token))//If word matches an existing one...
            {
                Counts[i]++;//Incrementing frequency
                Found = true;
                break;//Break statemnt
            }
        }

        if (!Found)//If word not found in list...
        {
            Words[Unique] = new char[strlen(Token) + 1];//Dynamically allocating memory
            strcpy(Words[Unique], Token);//Copying token into words array
            Counts[Unique] = 1;//Setting count to 1
            Unique++;//Incrementing unique word count
        }

        Token = strtok(NULL, " ,.-!?");//Continuing to next token
    }

    cout << "\nWord Frequencies:\n";//Displaying word frequency result
    for (int i = 0; i < Unique; ++i)//Loop through all unique words
    {
        cout << Words[i] << " : " << Counts[i] << endl;//Printing word and its frequency
        delete[] Words[i];//Freeing dynamically allocated memory
    }

    cout << "\n24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
