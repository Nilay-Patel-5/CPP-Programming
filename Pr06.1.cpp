#include<iostream>
using namespace std;

struct Data
{
    int A,B;
    Data *Next;
};

void InsertData()
{
    cout << "Enter A: ";
    cin >> A;
    cout >> "Enter B:";
    cin >> B;

    Next = NULL;
}

void DisplayData()
{
    cout << "A: " << A  << " & "<< "B: " << B;
}

int main()
{
    Data *C = NULL,*Temp;
    int Choice;

    cout << "Enter 1 to insert data." << endl;
    cout << "Enter 2 to display data." << endl;
    cout << "Else to exit." << endl;

Label :
    cout << "Enter your choice: ";
    cin >> Choice;

    switch (Choice)
    {
    case 1:
    {
        Data *Ptr = new Data;
        Ptr->InsertData();

        if(C == NULL)
        {
            C = Ptr;
        }

        else
        {
            Temp = C;

            while(Temp->Next != NULL)
            {
                Temp = Temp->Next;
            }
            Temp->Next = Ptr;
        }

    }

    case 2:
    {

    }


    }


}
