/*A team of developers is tasked with building a temperature conversion system for a weather application. To achieve this, the
team creates two classes: Celsius and Fahrenheit. These classes handle the conversion between temperature units, with the ability
to convert from Celsius to Fahrenheit and vice versa using type conversion. The team utilizes operator overloading to define the
conversion operators for both classes, enabling seamless conversions between the two units.
The system also requires the ability to compare two temperature objects to check if they are equal. This is achieved by overloading the equality operator ==, which compares the values of the temperatures in their respective units.
To ensure smooth processing of temperature conversions, the team needs to manage and store multiple converted temperature objects.
Two approaches are considered for handling this task. The first approach involves using a dynamic data structure, a queue, to
process the conversions in a first-in-first-out (FIFO) manner. Alternatively, a basic array is used to store the converted objects
in a static manner.*/

//This Program is prepared by 24CE089_NILAY PATEL
#include <iostream> //Standard Input/Output library
using namespace std;

class Fahrenheit;//Forward declaration

class Celsius//Creating Celsius class
{
    float Temperature;//Temperature in Celsius

public:
    Celsius() : Temperature(0) {}//Default constructor

    Celsius(float Temp) : Temperature(Temp) {}//Parameterized constructor

    float ReturnTemp()//Function for returning temperature
    {
        return Temperature;//Returning temperature
    }

    void operator=(Fahrenheit);//Overloading assignment operator

    bool operator==(Fahrenheit);//Overloading equality operator
};

class Fahrenheit//Creating Fahrenheit class
{
    float Temperature;//Temperature in Fahrenheit

public:
    Fahrenheit() : Temperature(0) {}//Default constructor

    Fahrenheit(float Temp) : Temperature(Temp) {}//Parameterized constructor

    float ReturnTemp()//Function for returning temperature
    {
        return Temperature;//Returning temperature
    }

    void operator=(Celsius);//Overloading assignment operator

    bool operator==(Celsius);//Overloading equality operator
};

bool Celsius::operator==(Fahrenheit F)//Definition of Celsius == Fahrenheit
{
    float Temp = F.ReturnTemp();
    Temp = (Temp - 32) * 5 / 9;//Converting Fahrenheit to Celsius

    if (Temp == Temperature)//Check if converted temperature equals Celsius temperature
        return true;
    else
        return false;
}

void Celsius::operator=(Fahrenheit F)//Definition of Celsius = Fahrenheit
{
    Temperature = F.ReturnTemp();
    Temperature = (Temperature - 32) * 5 / 9;//Converting Fahrenheit to Celsius
}

bool Fahrenheit::operator==(Celsius C)//Definition of Fahrenheit == Celsius
{
    float Temp = C.ReturnTemp();
    Temp = (Temp * 9 / 5) + 32;//Converting Celsius to Fahrenheit

    if (Temp == Temperature)//Check if converted temperature equals Fahrenheit temperature
        return true;
    else
        return false;
}

void Fahrenheit::operator=(Celsius C)//Definition of Fahrenheit = Celsius
{
    Temperature = C.ReturnTemp();
    Temperature = (Temperature * 9 / 5) + 32;//Converting Celsius to Fahrenheit
}

int main()//Main function
{
    int Choice = 1;//Variable for repeating the loop
    float Temperature;//Variable to take input

    while (Choice == 1)//Loop for repeated comparison
    {
        //Taking Celsius input
        cout << "\n\n~-Temperature Comparator-~\n\nEnter Temperature in Celsius: ";
        cin >> Temperature;//Taking input of temperature in Celsius
        Celsius C(Temperature);//Creating Celsius object with entered temperature

        //Taking Fahrenheit input
        cout << "\nEnter Temperature in Fahrenheit: ";
        cin >> Temperature;//Taking input of temperature in Fahrenheit
        Fahrenheit F(Temperature);//Creating Fahrenheit object with entered temperature

        //Assignment conversion
        Celsius Cel;
        Cel = F;//Fahrenheit to Celsius conversion

        Fahrenheit Fah;
        Fah = C;//Celsius to Fahrenheit conversion

        //Displaying results
        cout << endl << fixed << C.ReturnTemp() << " ^C in Fahrenheit is " << Fah.ReturnTemp() << " ^F";
        cout << endl << endl << F.ReturnTemp() << " ^F in Celsius is " << Cel.ReturnTemp() << " ^C\n\nSo, ";

        //Comparing temperatures
        if (C == F && F == C)
            cout << "Celsius temperature is the same as Fahrenheit temperature" << endl;//If equal...
        else
            cout << "Celsius temperature is not the same as Fahrenheit temperature" << endl; //If not equal...

        //Asking for another operation
        cout << "Do you want to perform operations again with different Temperatures?" << endl;
        cout << "Enter 1 for yes and 0 for no: ";
        cin >> Choice;//Taking input for repeating the operation
    }

    cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message

    return 0;//Return statement
}
