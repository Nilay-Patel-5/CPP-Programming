//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class Product//Creating class
{
    //Private data-members
    int ProdID,Quantity;
    float Price;
    char ProdName[20];

    //Making public functions for different tasks
public:

    void AddProd()//Function for adding new product
    {
        cout << "Enter product ID: ";
        cin >> ProdID;//Taking input of product ID
        cout << "Enter name of product: ";
        cin >> ProdName;//Taking input of product's name
        cout << "Enter price of product: ";
        cin >> Price;//Taking input of product's price

        Quantity = 1;//Initializing product's quantity to 1

        cout << "Product is added successfully!" << endl;//Printing message
    }

    inline int GetID()//Function for returning product ID
    {
        return ProdID;//Returning product ID
    }

    void UpdateQuan()//Function for updating quantity
    {
        cout << "Enter no. of quantity to be update: ";
        cin >> Quantity;//Taking input of product's quantity
        cout << "Quantity is updated successfully!" << endl;//Printing message
    }

    inline int CalculateValue()//Function for returning total price of product
    {
        return Quantity*Price;//Returning product of quantity & price
    }

    void DisplayBill()//Function for displaying bill
    {
        cout << ProdName << "\t";
        cout << Quantity << "\t\t";
        cout << Price << "\t" << CalculateValue() << endl;
    }
};

int main()//Main function
{
    class Product P[100];//Creating object

    int Choice;//Variable for choice
    int ProdFind;//Variable for matching product ID
    int ProdCount=0;//Initializing variable for no. of product to 1

    //Printing menu
    cout << "Enter 1 to add new product." << endl;
    cout << "Enter 2 to update quantity of product." << endl;
    cout << "Enter 3 to display bill & exit." << endl;
    cout << "======================================" << endl;

    while(true)
    {
        cout << "Enter the option which you want: ";
        cin >> Choice;//Taking input of choice

        bool Found = false;//Variable for signal if account no. matched

        switch (Choice)//Switch case
        {
        case 1://Case for adding new product
        {
            P[ProdCount].AddProd();//Calling AddProd function
            ProdCount++;//Increment of ProductCount

            break;//Break statement
        }

        case 2://Case for updating product's quantity
        {
            int ProdFind;//Variable for matching product ID

            cout << "Enter product ID: ";
            cin >> ProdFind;//Taking input of product id to search

            for(int i=0; i < ProdCount; i++)//Loop for matching product id with entered product id
            {
                if(P[i].GetID() == ProdFind)//If product id is matched with entered product id...
                {
                    P[i].UpdateQuan();//Calling UpdateQuan function

                    Found = true;//Product ID no. matched with entered product ID

                    break;//Break statement
                }
            }

            if(! Found)//If not...
                {
                    cout << "Product not found!" << endl;//Printing error message
                }

            break;//Break statement
        }

        case 3://Case for displaying bill
        {
            int TotalValue=0;//Initializing TotalValue variable to 0

            cout << "--------------------------------------" << endl;
            cout << "Name\tQuantity\tPrice\tTotal" << endl;
            cout << "--------------------------------------" << endl;

            for(int i=0; i < ProdCount ; i++) //Loop for calling displayBill function
            {
                P[i].DisplayBill();//Calling DisplayBill function

                TotalValue += P[i].CalculateValue();
            }

            cout << "--------------------------------------" << endl;
            cout << "Total Bill: " << TotalValue << endl;//Printing total bill
            cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

            return 0;//Return statement
        }

        default://Default case
        {
            cout << "Invalid input!" << endl;//Printing error message
            break;
        }
        }
    }
}
