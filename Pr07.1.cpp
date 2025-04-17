/*A media research team is developing a tool to analyze word frequency in large textual datasets, such as news articles and research papers. The goal is to process a given
paragraph, identify individual words, and count their occurrences while ensuring case-insensitive matching. Since the tool is intended for both constrained environments and
high-performance systems, two different approaches are considered—one utilizing dynamic memory management and another relying on manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string. Once acquired, the text must be split into individual words, ensuring that
uppercase and lowercase variations are treated as the same. To store and process words dynamically, the team designs a
mechanism using raw pointers and dynamic memory allocation, allowing the program to handle variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count occurrences efficiently. The array expands as needed, ensuring that new
words can be accommodated. The frequency counting is implemented manually by searching for existing words in the array and updating counts accordingly.*/

//This program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output library
#include <cstring>//Function based on string library

using namespace std;

void ConvertToLowercase(string &Word)//Function for converting every character in a word to lowercase
{
    for (int i = 0; i < Word.length(); i++)//Loop for converting every character in a word to lowercase
    {
        if (Word[i] >= 'A' && Word[i] <= 'Z')//If character is between A to Z...
        {
            Word[i] = Word[i] + 32;//converting character in lowercase
        }
        else//If not...
        {
            Word[i] = Word[i];//Remaining word as same as it is
        }
    }
}

void BreakParagraph(const string &Str,string Words[], int &WordCount)//Function for breaking paragraph into individual words
{
    int WordStart = -1;//Variable for starting point of word & initializing with -1
    WordCount = 0;//Variable for tracking no. of word & initializing with 0

    for (int i = 0; i < Str.length(); i++)//Loop for breaking paragraph into individual words
    {
        if (Str[i] != ' ' && WordStart == -1)//If there is a space or haven't found starting point of word
        {
            WordStart = i;
        }
        if ((Str[i] == ' ' || i == Str.length() -1) && WordStart != -1)
        {
            if (i == Str.length() && Str[i] != ' ')
            {
                i++;
            }
            Words[WordCount] = Str.substr(WordStart, i - WordStart);

            ConvertToLowercase(Words[WordCount]);

            WordCount++;

            WordStart = -1;
        }
    }
}

int main()//Main function
{
    string String;//String for paragraph
    string UniqueWords[50];//Variable for unique words
    string Words[50];//Variable for individual lowercase words

    int Count[50] = {0};//Array for count of individual word & initializing with 0
    int TotalWords = 0;//Variable for tracking no. of total words & initializing with 0
    int WordCount = 0;//Variable for no. of words which is found uppercase & initializing with 0

    cout << "Enter the paragraph: ";
    getline(cin,String);//Taking input of S named string

    BreakParagraph(String,Words,WordCount);//Calling BreakParagraph function

    for (int i = 0; i < WordCount; i++)//Loop for counting frequency of individual word
    {
        bool Exist = false;//boolean type variable for switching between true/false & initializing it with false

        for (int j = 0; j < TotalWords ; j++)//
        {
            if (UniqueWords[j] == Words[i])//If the word already exists...
            {
                Count[j]++;//Increment in Count variable

                Exist = true;//Re-initializing Exist with true

                break;//Break statement
            }
        }

        if (!Exist)//If not Exist...
        {
            UniqueWords[TotalWords] = Words[i];//

            Count[TotalWords] = 1;//

            TotalWords++;//Increment in TotalWords variable
        }
    }

    cout << "\nWords counts:" << endl;

    for (int i = 0; i < TotalWords; i++)//Loop for Printing words of string with count
    {
        cout << UniqueWords[i] << ": " << Count[i] << endl;//Printing words of string with count
    }

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
