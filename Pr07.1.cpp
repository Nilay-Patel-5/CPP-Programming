/*A media research team is developing a tool to analyze word frequency in large textual datasets, such
as news articles and research papers. The goal is to process a given paragraph, identify individual
words, and count their occurrences while ensuring case-insensitive matching. Since the tool is
intended for both constrained environments and high-performance systems, two different
approaches are considered—one utilizing dynamic memory management and another relying on
manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string.
Once acquired, the text must be split into individual words, ensuring that uppercase and lowercase
variations are treated as the same. To store and process words dynamically, the team designs a
mechanism using raw pointers and dynamic memory allocation, allowing the program to handle
variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count
occurrences efficiently. The array expands as needed, ensuring that new words can be
accommodated. The frequency counting is implemented manually by searching for existing words in
the array and updating counts accordingly.*/

//This program is prepared by 24CE089_NILAY PATEL
#include <iostream>
#include <cstring>

using namespace std;

void ConvertToLowercase(string &Word)
{
    for (int i = 0; i < Word.length(); i++)
    {
        Word[i] = (Word[i] >= 'A' && Word[i] <= 'Z') ? Word[i] + 32 : Word[i];
    }
}

void BreakParagraph(const string &Str,string Words[], int &WordCount)
{
    int WordStart = -1;
    WordCount = 0;

    for (int i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && WordStart == -1)
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

int main()
{
    string S[50];
    string U[50];

    int C[50] = {0};
    int WordCount = 0;

    cout << "Enter the paragraph: ";
    getline(cin, S[0]);

    string Words[50];

    int TotalWords = 0;

    BreakParagraph(S[0], Words, TotalWords);

    for (int i = 0; i < TotalWords; i++)
    {
        bool Found = false;

        for (int j = 0; j < WordCount; j++)
        {
            if (U[j] == Words[i])
            {
                C[j]++;

                Found = true;

                break;
            }
        }

        if (!Found)
        {
            U[WordCount] = Words[i];

            C[WordCount] = 1;

            WordCount++;
        }
    }

    cout << "\nWords counts:" << endl;

    for (int i = 0; i < WordCount; i++)
    {
        cout << U[i] << ": " << C[i] << endl;
    }

    cout << "24CE089_NILAY PATEL." << endl;

    return 0;
}
