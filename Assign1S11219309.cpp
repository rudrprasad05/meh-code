/*

Assignment 1
Rudr Ravi Prasad - S11219309

*/

// calculate age, income, tax

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    //input variables
    char entry_character, gender;
    string first_name, surname, employee_id;
    int year_of_birth, hours_worked, age, overtime_hours;
    double income, tax, annual_income;

    // programme constants
    const int NORMAL_PAY = 20;
    const double TIME_AND_HALF_RATIO = 1.5;
    const int DOUBLE_TIME_RATIO = 2;
    const int HOURS_45 = 45;
    const int HOURS_40 = 40;
    const int CURRENT_YEAR = 2023;
    const int WEEKS_IN_YEAR = 52;

    // tax percent constants
    const double TEN_PERCENT = 0.1;
    const double TWENTY_PERCENT = 0.2;
    const double THIRTY_PERCENT = 0.3;

    // main loop
    while (true)
    {
        cout << "\nWelcome to The Income Tax Calculator 5000" << endl
            << "Press 'C' to CONTINUE or 'Q' to QUIT" << endl;
        cin >> entry_character;

        if (toupper(entry_character) == 'Q') // quits proggrame if input is "Q"
        {
            cout << "Have a nice day...Quiting Programme" << endl;
            break;
        }

        else if (toupper(entry_character) == 'C')
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

            cout << "enter your gender (M -> male, F -> female): ";
            cin >> gender;
            cout << "\n";


            cout << "enter year of birth: ";
            cin >> year_of_birth;
            age = CURRENT_YEAR - year_of_birth; // calculates age using current year as 2023
            cout << "\n";

            cout << "Enter number of hours worked in this week: ";
            cin >> hours_worked;
            cout << "\n";

            //calculations
            if (hours_worked > HOURS_45) // checks to see if hours worked is more than 45. Gives double time to hours above 45. 
            {
                overtime_hours = hours_worked - HOURS_45;
                income = (HOURS_40 * NORMAL_PAY) + (5 * NORMAL_PAY * TIME_AND_HALF_RATIO) + (overtime_hours * NORMAL_PAY * DOUBLE_TIME_RATIO);
            }
            else if (hours_worked > HOURS_40) // checks to see if hours worked is more than 40 and less than 45. gives time and half
            {
                overtime_hours = hours_worked - HOURS_40;
                income = (HOURS_40 * NORMAL_PAY) + (overtime_hours * NORMAL_PAY * TIME_AND_HALF_RATIO);
            }
            else // hours is less than 40 so only normal pay is given
            {
                income = hours_worked * NORMAL_PAY;
            }

            annual_income = income * WEEKS_IN_YEAR;

             
            if (age < 55 && toupper(gender) == 'M') // sees the persons age and their corresponding income tax.
            {
                if (annual_income < 10000)
                {
                    tax = 0;
                }
                else if (annual_income <= 30000)
                {
                    tax = TEN_PERCENT;
                }
                else if (annual_income <= 100000)
                {
                    tax = TWENTY_PERCENT;
                }
                else
                {
                    tax = THIRTY_PERCENT;
                }
            }
            else if (age < 55 && toupper(gender) == 'F')
            {
                if (annual_income < 12000)
                {
                    tax = 0;
                }
                else if (annual_income <= 35000)
                {
                    tax = TEN_PERCENT;
                }
                else if (annual_income <= 100000)
                {
                    tax = TWENTY_PERCENT;
                }
                else
                {
                    tax = THIRTY_PERCENT;
                }
            }
            else if (age <= 80)
            {
                if (annual_income < 50000)
                {
                    tax = 0;
                }
                else if (annual_income <= 70000)
                {
                    tax = TEN_PERCENT;
                }
                else if (annual_income <= 150000)
                {
                    tax = TWENTY_PERCENT;
                }
                else
                {
                    tax = THIRTY_PERCENT;
                }
            }
            else
            {
                tax = 0;
            }

            //outputs

            cout << "<------- INCOME TAXT CALCULATOR ------->     " << endl;
            cout << "Name:                " << first_name << " " << surname << endl;
            cout << "Employee ID:         #"<< employee_id << endl; 
            cout << "Age:                 "<< age << endl; 
            cout << "Gross Pay per week:  $"<< income << endl; 
            cout << "Gross Annual Salary: $"<< annual_income<< endl; 
            cout << "Net Annual Salary:   $"<< annual_income - (annual_income * tax) << endl; 
            cout << "Annual Tax:          $"<< annual_income * tax << endl; 
        }

        else // checking for an input other than 'C' and 'Q'
        {
            cout << "Invalid Input...Retry" << endl;
            continue;
        }
    
    }
}