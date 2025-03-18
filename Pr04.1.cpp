#include<iostream>
using namespace std;

class Shape
{
    float Radius;

public:
    void InputRadius()
    {
        cout << "Enter radius: ";
        cin >> Radius;
    }

    int GetRadius()
    {
        return Radius;
    }
};

class Circle : private Shape
{
     float Area;

public:
    void CalculateArea()
    {
        InputRadius();
        Area = 3.14*GetRadius()*GetRadius();
    }

    void DisplayArea()
    {
        cout << "Area of circle: " << Area << endl;
    }
};

int main()
{
    class Shape S;
    class Circle C;

    //C.InputRadius();
    C.CalculateArea();
    C.DisplayArea();

    return 0;
}
