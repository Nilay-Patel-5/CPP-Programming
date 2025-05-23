/*A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's management sought to build a system that could
keep track of individual items, including details like a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system. The envisioned solution would allow for the
initialization of item details, either with default values or specific attributes like ID, name, price, and starting quantity. This system needed to
handle operations like increasing stock levels when new shipments arrived and decreasing stock when items were sold, ensuring sufficient inventory was
available for each transaction. Additionally, the system would provide clear, detailed summaries of each item's status, aiding in decision-making and
reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items simultaneously. They planned to design an array of inventory
items and simulate common tasks such as adding stock, processing sales transactions, and displaying the current inventory details. Handling edge cases,
such as attempting to sell more items than available in stock, became a critical part of the implementation to ensure reliability.*/

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

    while(true)//Loop for doing various tasks
    {
        cout << "Enter the option which you want: ";
        cin >> Choice;//Taking input of choice

        bool Found = false;//Variable for signal if account no. matched

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

            for (int i = 0; i < NumItem; i++)//Loop for matching item ID with entered item ID
            {
                if (I[i].GetItemID() == ItemFind)//If entered item ID matched with item ID...
                {
                    I[i].IncreaseItemQuan();//Calling IncreaseItemQuan function

                    Found = true;//Account no. matched with entered account no.

                    break;//Break statement
                }
            }

            if(! Found)//If Found variable doesn't switch to true...
            {
                cout << "Item not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        case 3:
        {
            cout << "Enter item ID: ";
            cin >> ItemFind;//Taking input of item ID to search

            for (int i = 0; i < NumItem; i++)//Loop for matching item ID with entered item ID
            {
                if (I[i].GetItemID() == ItemFind)//If entered item ID matched with item ID...
                {
                    I[i].DecreaseItemQuan();//Calling DecreaseItemQuan

                    Found = true;//Account no. matched with entered account no.

                    break;//Break statement
                }
            }

            if(! Found)//If Found variable doesn't switch to true...
            {
                cout << "Item not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        case 4:
        {
            cout << "Enter item ID: ";
            cin >> ItemFind;//Taking input of item ID to search

            for (int i = 0; i < NumItem; i++)//Loop for matching item ID with entered item ID
            {
                if (I[i].GetItemID() == ItemFind)//If entered item ID matched with item ID...
                {
                    I[i].DisplayItemDetails();//Calling DisplayItemDetails

                    Found = true;//Account no. matched with entered account no.

                    break;//Break statement
                }
            }

            if(! Found)//If Found variable doesn't switch to true...
            {
                cout << "Item not found!" << endl;//Printing error message
            }

            break;//Break statement
        }

        default://Default case
        {
            cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
            return 0;//Return statement
        }
        }
    }
}
