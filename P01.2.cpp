#include<iostream>
using namespace std;

class product
{
    int quantity,price;
    char name[20];

    public:
    int id;

    void AddProd();
    void UpdateQuan();
    void CalculateValue();
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

    while(1)
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
                    cout<<"Enter product ID: ";
                    cin>>ProdFind;

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

            case 3:
                {
                    for(int i=0;i<ProdCount;i++)
                    {
                        P[i].CalculateValue();
                    }
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
    cout<<"Enter quantity of product: ";
    cin>>quantity;
    cout<<"Enter price of product: ";
    cin>>price;
}

void product :: UpdateQuan()
{
    int NewQuan;

    cout<<"Enter no. of quantity to be update: ";
    cin>>NewQuan;

    quantity=NewQuan;

    cout<<"Quantity is updated successfully."<<endl;
}

void product :: CalculateValue()
{
    int TotalValue = quantity*price;

    cout<<"The total value of all products: "<<TotalValue<<endl;
}
