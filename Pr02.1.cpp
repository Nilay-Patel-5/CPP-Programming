/*A local construction company frequently deals with rectangular plots and structures of varying dimensions. To streamline their planning and estimation 
processes, the company requires a simple system to manage and analyze rectangular shapes efficiently.
The system must be able to handle multiple rectangles, each with distinct dimensions. For each rectangle, the length and width need to be defined and 
stored securely. Additionally, the company needs the ability to calculate two key metrics for any given rectangle:
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths or material requirements for edges. To make this 
system functional, there should be a way to define or update the dimensions of any rectangle as required. The system should be capable of creating and 
managing multiple rectangle records, performing calculations for each, and displaying the results clearly for analysis and planning purposes.*/

//This program is prepared by 24CE089_NILAY PATEL
#include<iostream>//Standard Input/Output library
using namespace std;

class Plot//Creating class
{
    //Private data-members
    int Length,Width,Area,Perimeter;

public:

    //Making public functions for different tasks
    void AddPlotData()//Function for entering plot's details
    {
        cout << "Enter length of plot: ";
        cin >> Length;//Taking input of length of plot
        cout  << "Enter width of plot: ";
        cin >> Width;//Taking input of width of plot
        cout << "Plot's data is successfully added!" << endl;//Printing message

        Area = Length*Width;//Calculating area of plot
        Perimeter = 2*(Length+Width);//Calculating perimeter of plot
    }

    void UpdatePlotData()//Function for updating plot's data
    {
        cout << "Enter new length of plot: ";
        cin >> Length;//Taking input of new length of plot
        cout << "Enter new width of plot: ";
        cin >> Width;//Taking input of new width of plot
        cout << "Plot's data is successfully updated!" << endl;//Printing message

        Area = Length*Width;//Again calculating area for updated data of plot
        Perimeter = 2*(Length+Width);//Again calculating perimeter for updated data of plot
    }

    void DisplayAllPlotData()//Function for displaying all plot's data
    {
        cout << "Length: " << Length << endl;//Displaying length of plot
        cout << "Width: "<< Width<< endl;//Displaying width of plot
        cout << "Area: "<< Area << endl;//Displaying area of plot
        cout << "Perimeter: " << Perimeter << endl;//Displaying perimeter of plot
    }

    void DisplayAnyPlotData()//Function for displaying any one plot's data
    {
        cout << "Plot details:" << endl;
        cout << "Length: "<< Length << endl;//Displaying length of plot
        cout << "Width: "<< Width << endl;//Displaying width of plot
        cout << "Area: "<< Area << endl;//Displaying area of plot
        cout << "Perimeter: " << Perimeter << endl;//Displaying perimeter of plot
    }
};

int main()//Main function
{
    class Plot P[100];//Creating object
    int Choice,PlotFind;//Variables for Choice & variable for matching plot no.
    int NumPlot = 0;//Variable for tracking the no. of plot & initializing to 0

    //Displaying menu
    cout << "Enter 1 to add plot data." << endl;
    cout << "Enter 2 to update plot data." << endl;
    cout << "Enter 3 to display plot data." << endl;
    cout << "Else to exit." << endl;
    cout << "=============================" << endl;

next :
    cout << "Enter your choice: ";
    cin >> Choice;//Taking input of choice

    switch (Choice)//Switch case
    {
    case 1://Case for adding plot's data
    {
        P[NumPlot].AddPlotData();//Calling AddPlotData
        NumPlot++;//Increment in variable no. of plot
        break;//Break statement
    }

    case 2://Case for updating plot's data
    {
        cout << "Enter plot no.: ";
        cin >> PlotFind;//Taking input of plot no. to search

        if(PlotFind <= NumPlot)//If no. of plot is greater than or equal to entered plot no. ...
        {
            P[PlotFind-1].UpdatePlotData();//Calling UpdatePlotData function
            break;//Break statement
        }

        else//If not...
        {
            cout << "No plot found!" << endl;//Printing error message
            break;//Break statement
        }
    }

    case 3://Case for displaying plot's data
    {
        int Choice1;//Variable for another choice

        cout << "Enter 1 to display all plot data & enter 2 to display any one plot data which you want: ";
        cin >> Choice1;//Taking input for another choice

        switch (Choice1)//Switch case
        {
        case 1://Case for displaying entered all plot's data
        {
            for(int i = 1, PlotNum = 0; PlotNum < NumPlot; i++, PlotNum++)//Loop for displaying entered all plot's data
            {
                cout << "Plot " << i << " details:" << endl;
                P[PlotNum].DisplayAllPlotData();//Calling DisplayAllPlotData function
            }

            if(NumPlot == 0)//If no. of plot is equal to 0...
            {
                cout << "No plot available to display!" << endl;//Printing error message
                break;//Break statement
            }
            break;//Break statement
        }

        case 2://Case for displaying any one plot's data
        {
            cout << "Enter plot number: ";
            cin >> PlotFind;//Taking input of plot no.

            if(PlotFind <= NumPlot)//If no. of plot is greater than or equal to entered plot no. ...
            {
                P[PlotFind-1].DisplayAnyPlotData();//Calling DisplayAnyPlotData function
                break;//Break statement
            }

            else//If not...
            {
                cout << "No plot found!" << endl;//Printing error message
                break;//Break statement
            }
        }

        default://Default case
        {
            cout << "Invalid input!" << endl;//Printing error message
            break;//Break statement
        }
        }
        break;//Break statement
    }

    default://Default case
    {
        cout << "24CE089_NILAY PATEL." << endl;//Printing exiting message
        return 0;//Return statement
    }
    }
    goto next;//Goto statement
}
