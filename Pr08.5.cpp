/*A software development team requires a lightweight directory management system to efficiently organize project files. The system
should allow users to create folders, add files to specific folders, and display the directory structure in an organized manner.
Each folder serves as a unique entry, mapping to a list of associated files, ensuring structured storage and easy retrieval. A
hierarchical mapping approach is used, where folder names act as keys, and dynamically resizable sequences store the corresponding
filenames.
The system provides essential functionalities, including adding new folders, appending files to existing folders, and displaying
the complete directory structure. To enhance accessibility, folder names are sorted alphabetically, allowing users to quickly
locate specific folders and their contents. Iterators are used for efficient traversal and structured display of data. This
approach ensures optimized performance, even for large datasets, while maintaining a logical and organized hierarchy.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
#include<map>//STL map library
#include<vector>//STL vector library
#include<string>//String handling library
using namespace std;

int main()//Main function
{
    map<string, vector<string>> Directory;//Map to store folders and corresponding files
    int Choice;//Variable for storing user choice
    string Folder, File;//Variables for storing folder and file names

    //Printing menu
    cout << "Enter 1 to add folder." << endl;
    cout << "Enter 2 to add file to folder." << endl;
    cout << "Enter 3 to display directory structure." << endl;
    cout << "Enter 4 to exit." << endl;
    cout << "===================================" << endl;

    while (true)//Loop for continuous menu-driven execution
    {
        cout << "Enter the option which you want: ";
        cin >> Choice;//Taking input of user choice

        if (Choice == 1)//Case for adding folder
        {
            cout << "Enter folder name: ";
            cin >> Folder;//Taking input of folder name

            Directory[Folder];//Adding new folder to map

            cout << "Folder added." << endl;//Printing success message
        }
        else if (Choice == 2)//Case for adding file to folder
        {
            cout << "Enter folder name: ";
            cin >> Folder;//Taking input of folder name

            if (Directory.find(Folder) != Directory.end())//If folder exists...
            {
                cout << "Enter file name: ";
                cin >> File;//Taking input of file name

                Directory[Folder].push_back(File);//Adding file to folder

                cout << "File added." << endl;//Printing success message
            }
            else//If folder does not exist...
            {
                cout << "Folder not found." << endl;//Printing error message
            }
        }
        else if (Choice == 3)//Case for displaying directory structure
        {
            cout << "Directory Structure:" << endl;//Printing directory heading

            for (auto it = Directory.begin(); it != Directory.end(); ++it)//Loop through map
            {
                cout << it->first << ":" << endl;//Printing folder name

                for (string f : it->second)//Loop through file list in folder
                {
                    cout << "  - " << f << endl;//Printing file name
                }
            }
        }
        else if (Choice == 4)//Case for exiting
        {
            cout << "24CE089_NILAY PATEL." << endl;//Printing exit message
            return 0;//Return statement
        }
        else//Default case if invalid input
        {
            cout << "Invalid option." << endl;//Printing error message
        }
    }
}
