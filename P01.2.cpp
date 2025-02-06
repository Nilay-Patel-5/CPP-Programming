#include<iostream>
using namespace std;

class product
{
    int quantity,price;
    char name[20];
    int id;

    public:
    void AddProd();
    void UpdateQuan();
    void CheckID();
    int CalculateValue();
};

int main()
{
    class product P[50];
    int choice;
    int ProdFind;
    int ProdCount=0;

    cout<<"Enter 1 to add new product"<<endl;
    cout<<"Enter 2 to update quantity of product"<<endl;
    cout<<"Enter 3 to calculate total value of all products"<<endl;
    cout<<"Enter 0 to exit"<<endl;

    while(choice != 0)
    {
        cout<<"Enter the option which you want: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                {
                    P[ProdCount].AddProd();
                    ProdCount++;
                    break;
                }

            case 2:
                {
                    int ProdFind;
                    
                    cout<<"Enter product ID: ";
                    cin<<ProdFind;
                    
                    for(int i=0;i<Prodfind;i++)
                    {
                        
                    }
                    
                }

            case 3:
                {
                    int TotalValue=0;

                    for(int i=0;i<ProdCount;i++)
                    {
                        TotalValue+=P[i].CalculateValue();
                    }

                    cout<<"The total value of all products: "<<TotalValue<<endl;
                    break;
                }

            case 0:
                {
                    cout<<"Thank you.";
                    return 0;
                }

            default:
                {
                    cout<<"Invalid input."<<endl;
                    break;
                }
        }
    }
}

void product :: AddProd()
{

    cout<<"Enter product ID: ";
    cin>>id;
    cout<<"Enter name of product: ";
    cin>>name;
    cout<<"Enter price of product: ";
    cin>>price;
}

void product :: UpdateQuan()
{
    cout<<"Enter no. of quantity to be update: ";
    cin>>quantity;
    cout<<"Quantity is updated successfully."<<endl;
}

void product :: CheckID()
{
    for(int i=0;i<ProdCount;i++)
    {
        if(P[i].id==ProdFind)
        {
            P[i].UpdateQuan();
            break;
        }

        else
        {
            cout<<"Product not found!"<<endl;
            break;
        }
    }
}

int product :: CalculateValue()
{
    return quantity*price;
}
