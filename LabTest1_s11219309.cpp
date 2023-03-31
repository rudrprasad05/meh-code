/* Rudr Ravi Prasad s11219309 */

#include <iostream>

using namespace std;

int main()
{
    // variables to store user input and calculation
    int game_choice;
    int number_of_players;
    int total_cost;

    // constants for game prices
    const int PRICE_CAR_RACING = 10;
    const double PRICE_MOTOR_CYCLE = 11.5;
    const int PRICE_VR = 16;
    const int PRICE_VR_HEADSET = 5;

    // ask user for what game they will play and store in game_choice variable
    cout << "What game would you like to play?" << endl 
        << "( 1. car racing | 2. motorcycle | 3. Virtual Reality ): ";
    cin >> game_choice;

    // validate user input for game choice, ensuring it is an interger between 1-3
    while (cin.fail() || game_choice > 3 || game_choice <= 0)
    {
        cin.clear(); // clear  error flags
        cin.ignore(1000, '\n'); // ignore remaining input characters
        cout << "Error! Invalid input. Enter game choice again: ";
        cin >> game_choice;
    }

    // ask user for number of players and store in number_of_players variable
    cout << "Enter number of players ( between 1-3 ): ";
    cin >> number_of_players;

    // validate user input for number_of_players, ensuring it is an interger
    while (cin.fail() || number_of_players > 3 || number_of_players < 0) 
    {
        cin.clear(); 
        cin.ignore(1000, '\n'); 
        cout << "Error! Invalid input. Enter number of players again: ";
        cin >> number_of_players;
    }
    
    // calculation of cost
    if (game_choice == 1)
    {
        total_cost = number_of_players * PRICE_CAR_RACING;
        cout << "Your total cost is $" << total_cost << endl;
    }
    else if (game_choice == 2)
    {
        total_cost = number_of_players * PRICE_MOTOR_CYCLE;
        cout << "Your total cost is $" << total_cost << endl;
    }
    else if (game_choice == 3)
    {
        total_cost = number_of_players * PRICE_VR + number_of_players * PRICE_VR_HEADSET;
        cout << "Your total cost is $" << total_cost << endl;
    }
    else
    {
        cout << "Invalid game choice" << endl; // error statement
    }    

return 0;

}