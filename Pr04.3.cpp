/*A vehicle manufacturing company sought to create a robust system to organize and manage the details of various cars produced under its brand. To
accomplish this, a hierarchical structure was conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was designed to
represent the type of fuel a vehicle uses. Another class was created to capture the brand name of the vehicle. These two foundational elements were then
combined into a derived class specifically representing cars, integrating both fuel type and brand information.
Constructors were used at each level to ensure proper initialization of attributes, allowing seamless integration of all details. Additionally, the ability
to display complete information about a car, including its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as
a service queue, multiple cars were organized and processed sequentially using a structured approach. This not only streamlined the handling of cars but
also provided an opportunity to compare different methods of managing the collection and processing of vehicle data.*/

//This program is prepared by 24CE089_NILAY PATEL.
#include<iostream>//Standard input/output library
#include<cstring>//Standard string library

using namespace std;

enum FuelType {Diesel = 'D', Petrol = 'P', Hybrid = 'H', CNG = 'C'};//Fixing input for fuel-type

class Fuel//Creating class
{
    //Private data-members
    FuelType FType;

//Making public functions for different tasks
public:

    Fuel()//Constructor of Fuel class
    {
        //Putting values in parameter
        FType = Petrol;
    }

    void AddFuelType()//Function for adding fuel type
    {
        char FChoice;//Variable for choice

        cout << "Enter fuel type(D for diesel,P for petrol,C for CNG & H for hybrid or petrol/CNG both): ";

        while(true)//Loop for taking input & Initializing FType variable
        {
            cin >> FChoice;//Taking input of choice

            switch(FChoice)//Switch case
            {
            case 'D'://Case for diesel
                FType = Diesel;//Initializing Ftype variable with diesel
                break;//Break statement

            case 'P'://Case for petrol
                FType = Petrol;//Initializing Ftype variable with petrol
                break;//Break statement

            case 'H'://Case for hybrid or petrol/CNG both
                FType = Hybrid;//Initializing Ftype variable with hybrid
                break;//Break statement

            case 'C'://Case for CNG
                FType = CNG;//Initializing Ftype variable with CNG
                break;//Break statement

            default://Default case
                cout << "Invalid input! Please enter a valid fuel type (D, P, H, C): ";//Printing error message & re-taking input of fuel-type
                continue;//Continue statement
            }
            break;//Break statement
        }
    }

    void DisplayFuelType() const//Function for displaying fuel fuel-type
    {
        switch(FType)//Switch case
        {
        case Diesel://Case for diesel
            cout << "Fuel type: Diesel" << endl;//Printing fuel type : diesel
            break;//Break statement

        case Petrol://Case for petrol
            cout << "Fuel type: Petrol" << endl;//Printing fuel type : petrol
            break;//Break statement

        case CNG://Case for CNG
            cout << "Fuel type: CNG" << endl;//Printing fuel type : CNG
            break;//Break statement

        case Hybrid://Case for hybrid or petrol/CNG both
            cout << "Fuel type: Hybrid" << endl;//Printing fuel type : hybrid
            break;//Break statement
        }
    }
};

class Brand//Creating class
{
    //Private data-member
    char BrandName[10];

//Making public functions for different tasks
public:

    Brand()//Constructor of Brand class
    {
        //Initializing data members with default value
        strcpy(BrandName," ");
    }

    void AddBrandDetails()//Function for adding brand details
    {
        cout << "Enter brand's name: ";
        cin >> BrandName;//Talking input of brand name

    }

    void DisplayBrandDetails()//Function for displaying brand details
    {
        cout << "Brand's name: " << BrandName << endl;//Printing brand name
    }

};

class Car : private Fuel,Brand//Creating class with a parent class
{
    //Private data-member
    char CarName[10];

//Making public functions for different tasks
public:

    Car() : Fuel(),Brand()//Constructor of Car class with a constructor of parent classes
    {
        //Initializing data members with default value
        strcpy(CarName,"");
    }

    void AddCarDetails()//Function for adding car details
    {
        cout << "Enter car name: ";
        cin >> CarName;//Talking input of car name

        AddBrandDetails();//Calling AddBrandDetails internally
        AddFuelType();//Calling  AddFuelType function internally
    }

    void DisplayCarDetails()//Function for displaying car details
    {
        cout << "Entered car details:~" << endl;
        cout << "Car name: " << CarName << endl;//Printing car name

        DisplayBrandDetails();//Calling DisplayBrandDetails function internally
        DisplayFuelType();//Calling DisplayFuelType function internally
    }
};

int main()//Main function
{
    class Car C;//Creating object

    C.AddCarDetails();//Calling AddCarDetails function
    C.DisplayCarDetails();//Calling DisplayCarDetails function

    cout << "24CE089_NILAY PATEL" << endl;//Printing exiting message

    return 0;//Return statement
}
