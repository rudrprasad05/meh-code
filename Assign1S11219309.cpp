/*

Assignment 1 - Income Tax Calculator
Rudr Ravi Prasad - S11219309

*/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    //input variables
    char entry_character, gender;
    string first_name, surname, employee_id;
    int year_of_birth, hours_worked;

    // temp var
    int overtime_hours, age;
    double income, tax, annual_income;
    string sex;

    // programme constants
    const int NORMAL_PAY = 20;
    const double TIME_AND_HALF_RATIO = 1.5;
    const int DOUBLE_TIME_RATIO = 2;
    const int HOURS_45 = 45;
    const int HOURS_40 = 40;
    const int CURRENT_YEAR = 2023;
    const int WEEKS_IN_YEAR = 52;
    const int AGE_80 = 80;
    const int AGE_55 = 55;

    // tax percent constants
    const double TEN_PERCENT = 0.1;
    const double TWENTY_PERCENT = 0.2;
    const double THIRTY_PERCENT = 0.3;

    // money constants
    const int TEN_THOUSAND_DOLLARS = 10000;
    const int TWELVE_THOUSAND_DOLLARS = 12000;
    const int THIRTY_THOUSAND_DOLLARS = 30000;
    const int THRITY_FIVE_THOUSAND_DOLLARS = 35000;
    const int FIFTY_THOUSAND_DOLLARS = 50000;
    const int SEVENTY_THOUSAND_DOLLARS = 70000;
    const int HUNDERED_THOUSAND_DOLLARS = 100000;
    const int HUNDRED_FIFTY_THOUSAND_DOLLARS = 150000;


    //main loop condition
    bool running = true;

    cout << "\nWelcome to The Income Tax Calculator 5000" << endl;

    // main loop
    while (running)
    {
        
        cout << "Press 'C' to CONTINUE or 'Q' to QUIT" << endl;
        cin >> entry_character;
        // change the character to uppercase inorder to prevent error and allow for users to enter uppercase or lowercase input
        entry_character = toupper(entry_character); 

        if (entry_character == 'Q') // quits proggrame if input is "Q"
        {
            cout << "Have a nice day...Quiting Programme" << endl;
            running = false;
        }

        else if (entry_character == 'C')
        {
            //asking for inputs

    
            cout << "Enter your first name: ";
            cin >> first_name;
            cout << "\n";

            cout << "Enter surname: ";
            cin >> surname;
            cout << "\n";

            cout << "Enter employee ID: ";
            cin >> employee_id;
            cout << "\n";

            cout << "Enter your gender (M -> male, F -> female): ";
            cin >> gender;
            // change the character to uppercase inorder to prevent error and allow for users to enter uppercase or lowercase input
            gender = toupper(gender); 

            while (gender != 'M' && gender != 'F') // make sure that the input in only either 'M' or 'F'
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error! Invalid input, please enter your gender again (M -> male, F -> female): ";
                cin >> gender;
                gender = toupper(gender);   
            }
            cout << "\n";

            cout << "enter year of birth: ";
            cin >> year_of_birth;

            while (cin.fail() || year_of_birth < 0) // check to see if age is a valid positive interger input
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error! Invalid input, please enter birth year again: ";
                cin >> year_of_birth;
            }

            age = CURRENT_YEAR - year_of_birth; // calculates age using current year as 2023
            cout << "\n";

            cout << "Enter number of hours worked in a week: ";
            cin >> hours_worked;

            while (cin.fail() || hours_worked < 0) // check to see if hours_worked is a valid positive interger input
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error! Invalid input, please enter hours worked again: ";
                cin >> hours_worked;
            }
            cout << "\n";


            //calculations
            if (hours_worked > HOURS_45) // checks to see if hours worked is more than 45. Gives double time to hours above 45. 
            {
                overtime_hours = hours_worked - HOURS_45;
                income = (HOURS_40 * NORMAL_PAY) + ((HOURS_45-HOURS_40) * NORMAL_PAY * TIME_AND_HALF_RATIO) + (overtime_hours * NORMAL_PAY * DOUBLE_TIME_RATIO);
            }
            else if (hours_worked > HOURS_40 && hours_worked <= HOURS_40) // checks to see if hours worked is more than 40 and less than or equal to 45. gives time and half
            {
                overtime_hours = hours_worked - HOURS_40;
                income = (HOURS_40 * NORMAL_PAY) + (overtime_hours * NORMAL_PAY * TIME_AND_HALF_RATIO);
            }
            else // hours is less than 40 so only normal pay is given
            {
                income = hours_worked * NORMAL_PAY;
            }

            annual_income = income * WEEKS_IN_YEAR;

            
            // calculates appropriate tax for male under age of 55.
            if (age < AGE_55 && gender == 'M') 
            {
                if (annual_income < TEN_THOUSAND_DOLLARS)
                {
                    tax = 0;
                }
                else if (annual_income <= THIRTY_THOUSAND_DOLLARS)
                {
                    tax = TEN_PERCENT;
                }
                else if (annual_income <= HUNDERED_THOUSAND_DOLLARS)
                {
                    tax = TWENTY_PERCENT;
                }
                else
                {
                    tax = THIRTY_PERCENT;
                }
            }

            // calculates appropriate tax for female under age of 55.
            else if (age < AGE_55 && gender == 'F') 
            {
                if (annual_income < TWELVE_THOUSAND_DOLLARS)
                {
                    tax = 0;
                }
                else if (annual_income <= THRITY_FIVE_THOUSAND_DOLLARS)
                {
                    tax = TEN_PERCENT;
                }
                else if (annual_income <= HUNDERED_THOUSAND_DOLLARS)
                {
                    tax = TWENTY_PERCENT;
                }
                else
                {
                    tax = THIRTY_PERCENT;
                }
            }

            // calculates appropriate tax for all genders under age or equal to 80 years but over 55.
            else if (age <= AGE_80) 
            {
                if (annual_income < FIFTY_THOUSAND_DOLLARS)
                {
                    tax = 0;
                }
                else if (annual_income <= SEVENTY_THOUSAND_DOLLARS)
                {
                    tax = TEN_PERCENT;
                }
                else if (annual_income <= HUNDRED_FIFTY_THOUSAND_DOLLARS)
                {
                    tax = TWENTY_PERCENT;
                }
                else
                {
                    tax = THIRTY_PERCENT;
                }
            }

            // calculates appropriate tax for all genders over age of 80.
            else if (age > AGE_80) 
            {
                tax = 0;
            }
            else
                cout << "error, try again" << endl;
        
            //outputs
            cout << "<------- INCOME TAXT CALCULATOR ------->     " << endl;
            cout << "Name:                " << first_name + " " + surname << endl;
            cout << "Employee ID:         "<< employee_id << endl; 
            cout << "Age:                 "<< age << endl;
            cout << "Gender               " << (gender == 'M' ? "Male" : "Female") << endl; // ternary operator that validates sex as Male if 'M' and Female if 'F'
            cout << "Gross Pay per week:  $"<< income << endl; 
            cout << "Gross Annual Salary: $"<< annual_income<< endl; 
            cout << "Net Annual Salary:   $"<< annual_income - (annual_income * tax) << endl; 
            cout << "Annual Tax:          $"<< annual_income * tax << endl;
            cout << "\n"; 
        }

        // checking for an input other than 'C' and 'Q'
        else 
            cout << "Invalid Input...Retry" << endl;
        
    
    }

    return 0;
}