// lab test 2 - s11219309 - Rudr Prasad

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

const int MAX_DESTINATIONS = 4;
const int MIN_PASSENGERS = 12;

// take option was the input and look for corresponding price in prices[] array. 
void OutPutCost(int option, double total_amount, int passenger_count, double prices[], string destination[]);

int main()
{
    string destination[] = {"Nadi", "Nausori", "Lami", "Sigatoka"};
    double prices[] = {25, 13.75, 10, 20.25};

    char master_option;
    int option;
    int passenger_count;
    double total_amout;
    bool running = true;

    while (running)
    {
        cout << "\nWelcome Coach Services Fiji." << endl 
            << "Do you wish to continue (any character) or quit (\'Q\' or \'q\')? ";
        cin >> master_option; // used to continue or quit the programme
        cout << endl;

        if (toupper(master_option) == 'Q')
        {
            running = false;
            return 0;
        }

        // display menu options
        cout << "Given below are the prices and destinations\n" << endl;
        for (int i = 0; i < MAX_DESTINATIONS; i++)
        {
            cout << (i+1) << ". " << setw(10) <<destination[i] << setw(10) << " ---> " << setw(5) << "$" << prices[i] << endl;
        }
        cout << endl;

        // takes in destination option and stores it in int option
        cout << "Where do you want to go (enter number between 1 - 4): ";
        cin >> option;
        while (cin.fail() || option > MAX_DESTINATIONS) // check to see if option is a valid character is used
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Invalid input or incorrect destination please enter option again: ";
            cin >> option;
        }

        // takes in passenger count 
        cout << "How many passengers will be travelling? ";
        cin >> passenger_count;
        while (cin.fail() || passenger_count < MIN_PASSENGERS) // check to see if number of passengers is a valid character is used
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Invalid input or minimum passenger count not met, please enter option again: ";
            cin >> passenger_count;
        }

        // calls function that will calculate cost and display outup on screen
        OutPutCost(option, total_amout, passenger_count, prices, destination);


    }
    
}

void OutPutCost(int option, double total_amount, int passenger_count, double prices[], string destination[])
{
    int array_index = option - 1; // takes into account arrays start at zero index 
    total_amount = prices[array_index] * passenger_count;
    cout << "\nYour trip total to " << destination[array_index] << " is: $" << total_amount << endl;
}
