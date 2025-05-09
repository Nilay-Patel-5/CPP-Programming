/*A small retail business is looking for a simple yet effective inventory management system to keep track of its products. The
system needs to support essential operations such as adding new items, viewing the complete inventory, and searching for specific
products. Since the inventory data should persist across sessions, all operations must be performed using file storage. The
business also requires an efficient way to retrieve item details without unnecessary file reads.
To manage inventory, the system must allow employees to add new products by recording details such as the item name, quantity, and
price. These records should be appended to a file, ensuring that previously stored data remains intact. When viewing inventory,
the system should read the file sequentially and display all stored items. Additionally, employees should be able to search for a
product by name, retrieving its details without manually scanning the entire file.
For implementation, two approaches are considered. One method processes file operations directly, reading and searching line by
line to retrieve item information efficiently. This minimizes memory usage but requires re-reading the file for each search
operation. An alternative approach loads inventory data into a dynamically managed array, enabling faster searches and future
enhancements such as sorting and filtering without repeated file access.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream>//Standard Input/Output Library
#include <fstream>//File handling Library
#include <cstring>//String handling Library

using namespace std;

class Item//Creating class
{
    char Name[50];//Item name
    int Quantity;//Item quantity
    float Price;//Item price

public:
    void GetDetails()//Function for getting item details
    {
        cout << "Enter item name: ";
        cin >> Name;//Taking item name input
        cout << "Enter quantity: ";
        cin >> Quantity;//Taking item quantity input
        cout << "Enter price: ";
        cin >> Price;//Taking item price input
    }

    void SaveToFile()//Function for saving item details to file
    {
        ofstream File("inventory.txt", ios::app);//Opening file in append mode
        if (!File)//If file cannot be opened...
        {
            cout << "Error opening file.\n";//Error message
            return;
        }
        File << Name << " " << Quantity << " " << Price << endl;//Saving item details to file
        File.close();//Closing file
    }

    void Display()//Function for displaying item details
    {
        cout << "Name: " << Name
             << ", Quantity: " << Quantity
             << ", Price: " << Price << endl;//Displaying item details
    }

    bool Search(const char* SearchName)//Function for searching for an item by name
    {
        return strcmp(Name, SearchName) == 0;//Returning true if item names match
    }

    bool LoadFromFile(ifstream& File)//Function for loading item details from file
    {
        File >> Name >> Quantity >> Price;//Loading item details
        return File.good();//Returning true if file reading is successful
    }
};

void AddItem()//Function for adding an item
{
    Item ItemObj;
    ItemObj.GetDetails();//Getting item details
    ItemObj.SaveToFile();//Saving item details to file
    cout << "Item added successfully.\n";//Success message
}

void CheckInventory()//Function for checking inventory
{
    ifstream File("inventory.txt");//Opening file to read inventory
    if (!File)//If file is not open...
    {
        cout << "No inventory found.\n";//Error message
        return;
    }

    Item ItemObj;
    cout << "\nInventory:\n";
    while (ItemObj.LoadFromFile(File))//Loading and displaying items from file
    {
        ItemObj.Display();
    }
    File.close();//Closing file
}

void SearchItem()//Function for searching for an item
{
    char SearchName[50];
    cout << "Enter item name to search: ";
    cin >> SearchName;//Taking input of item name to search

    ifstream File("inventory.txt");//Opening file to read inventory
    if (!File)//If file cannot be opened...
    {
        cout << "No inventory found.\n";//Error message
        return;
    }

    Item ItemObj;
    bool Found = false;//Flag for indicating whether the item is found
    while (ItemObj.LoadFromFile(File))//Loading and checking items from file
    {
        if (ItemObj.Search(SearchName))//If item is found...
        {
            cout << "Found item:\n";
            ItemObj.Display();//Displaying found item details
            Found = true;
            break;//Exiting the loop as the item is found
        }
    }

    if (!Found)//If item not found...
    {
        cout << "Item not found.\n";//Error message
    }

    File.close();//Closing file
}

int main()//Main function
{
    int Choice;

    do
    {
        cout << "\n1. Add Item\n2. View Inventory\n3. Search Item\n0. Exit\n";//Menu
        cout << "Enter your Choice: ";
        cin >> Choice;//Taking input of choice

        switch (Choice)//Switch case for user choices
        {
        case 1://Adding item case
            AddItem();
            break;
        case 2://Viewing inventory case
            CheckInventory();
            break;
        case 3://Searching item case
            SearchItem();
            break;
        case 0://Exiting case
            cout << "Exiting...\n";
            break;
        default://Default case
            cout << "Invalid Choice.\n";
        }
    }
    while (Choice != 0);//Repeating until exit is chosen

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}

