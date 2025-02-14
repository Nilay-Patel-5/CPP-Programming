#include<iostream>
using namespace std;

class Plot
{
    int length,width,area,perimeter;

public:
    void AddPlotData()
    {
        cout<<"Enter the length of plot: ";
        cin>>length;
        cout<<"Enter the length of plot: ";
        cin>>width;

        area = length*width;
        perimeter = 2*(length+width);
    }

    void UpdatePlotData()
    {
        cout<<"Enter the new length of plot: ";
        cin>>length;
        cout<<"Enter the new length of plot: ";
        cin>>width;

        area = length*width;
        perimeter = 2*(length+width);
    }

    void DisplayAllPlotData()
    {
        cout<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Perimeter: "<<perimeter<<endl;
    }

    void DisplayAnyPlotData()
    {
        cout<<"Plot details:"<<endl;
        cout<<"Length: "<<length<<endl;
        cout<<"Width: "<<width<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Perimeter: "<<perimeter<<endl;
    }
};

int main()
{
    class Plot P[25];
    int choice,NumPlot=0,PlotNum;

    cout<<"Enter 1 to add plot data."<<endl;
    cout<<"Enter 2 to update plot data."<<endl;
    cout<<"Enter 3 to display plot data."<<endl;
    cout<<"Else to exit."<<endl;

next : cout<<"Enter your choice: ";
       cin>>choice;

    switch(choice)
    {
    case 1:
    {
        P[NumPlot].AddPlotData();
        NumPlot++;
        break;
    }

    case 2:
    {
        cout<<"Enter plot no.: ";
        cin>>PlotNum;

        if(PlotNum<=NumPlot)
        {
            P[PlotNum-1].UpdatePlotData();
            break;
        }

        else
        {
            cout<<"No plot found!"<<endl;
            break;
        }
    }

    case 3:
    {
        int choice1;

        cout<<"Enter 1 to display all plot data & enter 2 to display any one plot data which you want: ";
        cin>>choice1;

        switch(choice1)
        {
        case 1:
        {
            for(int i=1,PlotNum=0; PlotNum<NumPlot; i++,PlotNum++)
            {
                cout<<"Plot "<<i<<" details:"<<endl;
                P[PlotNum].DisplayAllPlotData();
            }

            if(NumPlot==0)
            {
                cout<<"No plot available to display!"<<endl;
                break;
            }
            break;
        }

        case 2:
        {
            cout<<"Enter plot number: ";
            cin>>PlotNum;

            if(PlotNum<=NumPlot)
            {
                P[PlotNum-1].DisplayAnyPlotData();
                break;
            }

            else
            {
                cout<<"No plot found!"<<endl;
                break;
            }
        }

        default:
        {
            cout<<"Invalid input"<<endl;
        }
        }
        break;
    }

    default:
    {
        cout<<"Thank you."<<endl;
        return 0;
    }
    }
    goto next;
}
