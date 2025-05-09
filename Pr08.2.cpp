/*A digital publishing company is developing a tool to analyze text content for word frequency distribution. This tool aims to
help writers and editors understand the prominence of specific words in an article, enabling them to refine their content for
clarity and impact. The system should process an input sentence, count occurrences of each unique word, and display the results
in an organized manner.
To achieve this, the system utilizes an associative container that maps words to their corresponding frequencies. As the text is
processed, each word is extracted and stored as a key, while its occurrence count is maintained as the associated value. By
leveraging iterators, the system efficiently traverses the data structure, displaying each word along with its computed frequency.
The use of a dynamic mapping approach ensures that words are stored in an ordered manner, allowing for fast retrieval and
structured output.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#include<map>//For using map to store word frequencies
#include<sstream>//For string stream processing
#include<algorithm>//For using transform function

using namespace std;

string ConvertToLowercase(string Word)//Function for converting word to lowercase
{
    transform(Word.begin(), Word.end(), Word.begin(), ::tolower);//Converting all characters to lowercase
    return Word;//Returning the lowercase word
}

int main()//Main function
{
    string Sentence;//Variable to hold user input sentence
    cout << "Enter a sentence: ";
    getline(cin, Sentence);//Taking full line input from user

    map<string, int> Frequency;//Map to store word and its frequency
    string Word;//Variable to hold each word while parsing
    istringstream Stream(Sentence);//Creating input stream from sentence

    while (Stream >> Word)//Loop to extract each word from the sentence
    {
        Word = ConvertToLowercase(Word);//Converting word to lowercase
        Frequency[Word]++;//Incrementing frequency of word
    }

    cout << "\nWord Frequencies:\n";//Displaying header message

    for (auto Pair : Frequency)//Loop to display each word and its frequency
    {
        cout << Pair.first << ": " << Pair.second << endl;//Printing word and frequency
    }

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

