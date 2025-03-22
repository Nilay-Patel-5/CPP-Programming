#include<iostream>
#include<cstring>

using namespace std;

enum FuelType {Diesel = 'D', Petrol = 'P', Hybrid = 'H', CNG = 'C'};

class Fuel
{
    FuelType FType;

public:

    Fuel()
    {
        FType = Petrol;
    }

    void AddFuelType()
    {
        char FChoice;

        cout << "Enter fuel type(D for diesel,P for petrol,C for CNG & H for hybrid or petrol/CNG both): ";

        while(true)
        {
            cin >> FChoice;

                switch(FChoice)
                {
                case 'D':
                    FType = Diesel;
                    break;

                case 'P':
                    FType = Petrol;
                    break;

                case 'H':
                    FType = Hybrid;
                    break;

                case 'C':
                    FType = CNG;
                    break;

                default:
                    cout << "Invalid input! Please enter a valid fuel type (D, P, H, C): ";
                    continue;
                }
                break;
        }
    }

    void DisplayFuelType() const
    {
        switch(FType)
        {
            case Diesel:
                cout << "Fuel type: Diesel" << endl;
                break;
            case Petrol:
                cout << "Fuel type: Petrol" << endl;
                break;
            case CNG:
                cout << "Fuel type: CNG" << endl;
                break;
            case Hybrid:
                cout << "Fuel type: Hybrid" << endl;
                break;
        }
    }
};

class Brand
{
    char BrandName[10];

public:

    Brand()
    {
        strcpy(BrandName," ");
    }

    void AddBrandDetails()
    {
        cout << "Enter brand's name: ";
        cin >> BrandName;
    }

    void DisplayBrandDetails()
    {
        cout << "Brand's name: " << BrandName << endl;
    }

};

class Car : private Fuel,Brand
{
    char CarName[10];

public:

    Car() : Fuel(),Brand()
    {
        strcpy(CarName,"");
    }

    void AddCarDetails()
    {
        cout << "Enter car name: ";
        cin >> CarName;

        AddBrandDetails();
        AddFuelType();
    }

    void DisplayCarDetails()
    {
        cout << "Car name: " << CarName << endl;

        DisplayBrandDetails();
        DisplayFuelType();
    }
};

int main()
{
    class Car C;

    C.AddCarDetails();
    C.DisplayCarDetails();

    cout << "24CE089_NILAY PATEL" << endl;

    return 0;
}
