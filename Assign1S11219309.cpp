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
    const int MAX_HOURS = 40;
    const string SPACER = "_______________________________________________\n\n";

    // main loop
    while (true)
    {
        cout << "\nWelcome to The Income Tax Calculator 5000" << endl
            << "Press 'C' to CONTINUE or 'Q' to QUIT" << endl;
        cin >> entry_character;

        if (toupper(entry_character) == 'Q')
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
            age = 2023 - year_of_birth;
            cout << "\n";

            cout << "Enter number of hours worked in this week: ";
            cin >> hours_worked;
            cout << "\n";

            //calculations
            if (hours_worked > (MAX_HOURS + 5))
            {
                overtime_hours = hours_worked - 45;
                income = (MAX_HOURS * NORMAL_PAY) + (5 * NORMAL_PAY * TIME_AND_HALF_RATIO) + (overtime_hours * NORMAL_PAY * DOUBLE_TIME_RATIO);
            }
            else if (hours_worked > MAX_HOURS)
            {
            overtime_hours = hours_worked - MAX_HOURS;
            income = (MAX_HOURS * NORMAL_PAY) + (overtime_hours * NORMAL_PAY * TIME_AND_HALF_RATIO);
            }
            else
            {
                income = hours_worked * NORMAL_PAY;
            }

            annual_income = income * 52;

            //checking to see age and applicable income tax
            if (age < 55 && toupper(gender) == 'M')
            {
                if (annual_income < 10000)
                {
                    tax = 0;
                }
                else if (annual_income <= 30000)
                {
                    tax = 0.1;
                }
                else if (annual_income <= 100000)
                {
                    tax = 0.2;
                }
                else
                {
                    tax = 0.3;
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
                    tax = 0.1;
                }
                else if (annual_income <= 100000)
                {
                    tax = 0.2;
                }
                else
                {
                    tax = 0.3;
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
                    tax = 0.1;
                }
                else if (annual_income <= 150000)
                {
                    tax = 0.2;
                }
                else
                {
                    tax = 0.3;
                }
            }
            else
            {
                tax = 0;
            }

            //outputs

            cout << "<------- INCOME TAXT CALCULATOR ------->     " << endl;
            cout << "Name:                 " << first_name << " " << surname << endl;
            cout << "Employee ID:         #"<< employee_id << endl; 
            cout << "Age:                  "<< age << endl; 
            cout << "Gross Pay per week:  $"<< income << endl; 
            cout << "Gross Annual Salary: $"<< annual_income<< endl; 
            cout << "Net Annual Salary:   $"<< annual_income - (annual_income * tax) << endl; 
            cout << "Annual Tax:          $"<< annual_income * tax << endl; 
        }

        else // checking for an input other than 'C' and 'Q'
        {
            cout << "Invalid Input...Quiting Programme" << endl;
            break;
        }
    
    }
}