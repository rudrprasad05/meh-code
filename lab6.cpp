#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    int speed, overspeed, fine;
    char intoxicated;

    cout << "speed: ";
    cin >> speed;

    while (cin.fail()) // check to see if age is a valid interger input
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error. Expected interger, entered string ";
                cout << "Enter speed again: ";
                cin >> speed;
            }

    cout << "intoxicated ('Y' / 'N'): ";
    cin >> intoxicated;

    while (toupper(intoxicated) != 'Y' && toupper(intoxicated) != 'N') // make sure that the input in only either 'M' or 'F'
            {
                cout << "Error...invalid input. Intoxicated ('Y' / 'N'):  ";
                cin >> intoxicated;
                cout << "\n";
            }

    if (speed > 70)
    {
        if (toupper(intoxicated) == 'Y')
        {
            overspeed = speed - 70;
            fine = (overspeed * 15) + (10 * 7);
            cout << "Spend the day in prision. $" << fine << "to be paid as fine";

        }
        else
        {
            overspeed = speed - 70;
            fine = (overspeed * 15) + (10 * 5);
            cout << "Spend the day in prision. $" << fine << "to be paid as fine";

        }
    }
    else if (speed > 65)
    {
        
    }
}