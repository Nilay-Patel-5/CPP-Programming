//This Program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class Inventory//Creating class
{
    //Private data-members
    int ItemID;
    char ItemName[20];
    float Price;
    int Quantity;

    //Making public functions for different tasks
public:

    void AddItemDetails()//Function for adding item's details
    {
        cout << "Enter item ID: ";
        cin >> ItemID;//Taking input of item ID
        cout << "Enter item's name: ";
        cin >> ItemName;//Taking input of item's name
        cout << "Enter price of item: ";
        cin >> Price;//Taking input of price

        Quantity = 1;//Initializing quantity to 1
    }

    int GetItemID()//Function for returning item ID
    {
        return ItemID;//Returning item ID
    }

    void IncreaseItemQuan()//Function for increasing item's quantity
    {
        //Variable declaration
        int NewQuantity;//Variable for increasing quantity

        cout << "Enter quantity to be increased: ";
        cin >> NewQuantity;//Taking input of increasing quantity

        Quantity += NewQuantity;//Addition of present quantity & increasing quantity

        cout << "Item's Quantity is successfully increased!" << endl;//Printing message
    }

    void DecreaseItemQuan()//Function for decreasing item's quantity
    {
        //Variable declaration
        int NewQuantity;//Variable for decreasing quantity
        cout << "Enter quantity to be decreased: ";
        cin >> NewQuantity;//Taking input of decreasing quantity

        if(Quantity >= NewQuantity)//If present quantity is greater than decreasing quantity...
        {
            Quantity -= NewQuantity;//Subtraction of present quantity & decreasing quantity

            cout << "Item's Quantity is successfully decreased!" << endl;//Printing message
        }

        else//If not...
        {
            cout << "Insufficient quantity for decreament!" << endl;//Printing error message
        }
    }

    void DisplayItemDetails()//Function for displaying item's details
    {
        cout << "Item's details:" << endl;
        cout << "ID: " << ItemID << endl;//Displaying item ID
        cout << "Name: " << ItemName << endl;//Displaying item's name
        cout << "Price: " << Price << endl;//Displaying price
        cout << "Quantity: " << Quantity << endl;//Displaying present quantity
    }
};

int main()//Main function
{
    class Inventory I[100];//Creating object
    int NumItem = 0;//Variable for tracking no. of items & initializing to 0
    int ItemFind,Choice;//Variables for matching item ID & choice

    //Displaying menu
    cout << "Enter 1 to add item." << endl;
    cout << "Enter 2 to increase quantity." << endl;
    cout << "Enter 3 to decrease quantity." << endl;
    cout << "Enter 4 to display item's details." << endl;
    cout << "Else to Exit." << endl;
    cout << "==================================" << endl;

next ://Label
    cout << "Enter the option which you want: ";
    cin >> Choice;//Taking input of choice

    switch(Choice)//Switch case
    {
    case 1://Case for adding items
    {
        I[NumItem].AddItemDetails();//Calling AddItemDetails function
        NumItem++;//Increment in no. of items

        break;//Break statement
    }

    case 2://Case for increasing quantity
    {
        cout << "Enter item ID: ";
        cin >> ItemFind;//Taking input of item ID to search

        for (int i = 0; i <= NumItem; i++)//Loop for matching item ID with entered item ID
        {
            if (I[i].GetItemID() == ItemFind)//If entered item ID matched with item ID...
            {
                I[i].IncreaseItemQuan();//Calling IncreaseItemQuan function
                break;//Break statement
            }

            else//If not...
            {
                cout << "Item not found!" << endl;//Printing error message
                break;//Break statement
            }
        }
        break;//Break statement
    }

    case 3:
    {
        cout << "Enter item ID: ";
        cin >> ItemFind;//Taking input of item ID to search

        for (int i = 0; i <= NumItem; i++)//Loop for matching item ID with entered item ID
        {
            if (I[i].GetItemID() == ItemFind)//If entered item ID matched with item ID...
            {
                I[i].DecreaseItemQuan();//Calling DecreaseItemQuan
                break;//Break statement
            }

            else//If not...
            {
                cout << "Item not found!" << endl;//Printing error message
                break;//Break statement
            }
        }
        break;//Break statement
    }

    case 4:
    {
        cout << "Enter item ID: ";
        cin >> ItemFind;//Taking input of item ID to search

        for (int i = 0; i <= NumItem; i++)//Loop for matching item ID with entered item ID
        {
            if (I[i].GetItemID() == ItemFind)//If entered item ID matched with item ID...
            {
                I[i].DisplayItemDetails();//Calling DisplayItemDetails
                break;//Break statement
            }

            else//If not...
            {
                cout << "Item not found!" << endl;//Printing error message
                break;//Break statement
            }
        }
        break;//Break statement
    }

    default://Default case
    {
        cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
        return 0;//Return statement
    }
    }
    goto next;//Goto statement
}
