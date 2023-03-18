#include <iostream>
using namespace std;
int main()
{
    char category;
    int hours, overtime_hours;
    double wages;
    const double M_RATE = 10.6;
    const double F_RATE = 8.3;
    const double M_TAX = 0.35;
    const double F_TAX = 0.2;
    const int MAX_HOURS = 40;
    const double TIME_AND_HALF = 1.5;
    cout << "*****************************" << endl;
    cout << "*      Wage Calculator      *" << endl;
    cout << "*****************************" << endl;
    cout << "enter catergory ('F' for Floor worker and 'M' for manegment): ";
    cin >> category;
    cout << "Enter number of hours worked: ";
    cin >> hours;
    if(category=='F' || category=='f')
    {
        if (hours > MAX_HOURS)
        {
            overtime_hours = hours - MAX_HOURS;
            wages = (MAX_HOURS * F_RATE) + (overtime_hours * F_RATE * TIME_AND_HALF);
            wages = wages - (wages * F_TAX);
        }
        else
        {
            wages = hours * F_RATE;
            wages = wages - (wages * F_TAX);
        }
    } 
    if(category=='M' || category=='m')
    {
        if (hours > MAX_HOURS)
        {
            overtime_hours = hours - MAX_HOURS;
            wages = (MAX_HOURS * M_RATE) + (overtime_hours * M_RATE * TIME_AND_HALF);
            wages = wages - (wages * M_TAX);
        }
        else
        {
            wages = hours * M_RATE;
            wages = wages - (wages * M_TAX);
        }
        
    } 
    cout << "Summary"
        << "_________" << endl << endl;
    cout << "staff catergory: "<< category << endl;
    cout << "hours worked: " << hours << endl;
    cout << "net wages: $" << wages << endl;
}