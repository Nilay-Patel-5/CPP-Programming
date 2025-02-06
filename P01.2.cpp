#include<iostream>
using namespace std;

class product
{
    int id,quantity,price;
    char name[20];

    public:
    void AddProd();
    int GetID();
    void UpdateQuan();
    int CalculateValue();
    void displayBill();
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
                    cin>>ProdFind;

                    for(int i=0;i<=ProdCount;i++)
                    {
                        if(P[i].GetID()==ProdFind)
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
                    break;
                }

            case 3:
                {
                    int TotalValue=0;

                    cout<<"--------------------------------------"<<endl;
                    cout<<"Name\tQuantity\tPrice\tTotal"<<endl;
                    cout<<"--------------------------------------"<<endl;

                    for(int i=0;i<ProdCount;i++)
                    {
                        P[i].displayBill();
                        TotalValue+=P[i].CalculateValue();
                    }

                    cout<<"--------------------------------------"<<endl;

                    cout<<"Total Bill: "<<TotalValue<<endl;
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

    quantity=1;
}

void product :: UpdateQuan()
{
    cout<<"Enter no. of quantity to be update: ";
    cin>>quantity;
    cout<<"Quantity is updated successfully."<<endl;
}

int product :: GetID()
{
    return id;
}

int product :: CalculateValue()
{
    return quantity*price;
}

void product :: displayBill()
{
    cout<<name<<"\t";
    cout<<quantity<<"\t\t";
    cout<<price<<"\t"<<CalculateValue()<<endl;
}
