#include <iostream>

using namespace std;

int main(){

    bool running = true;
    int random_number = 5;
    int user_number;
    int guesses = 0;
    const int MAX_GUESSES = 5;

    while (running && guesses < MAX_GUESSES){

        cout << "Chose a number between 1 - 20 (" << (MAX_GUESSES - guesses) << " guesses left): ";
        cin >> user_number;

        if (user_number > random_number){
            cout << "try again, aim lower" << endl;
            guesses++;
        }
        else if(user_number < random_number){
            cout << "try again, aim higher" << endl;
            guesses++;
        }
        else{
            cout << "correct!" << endl;
            running = false;
        }
    };

    
    return 0;
}

