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
    const int age_80 = 80;
    const int age_55 = 55;

    // tax percent constants
    const double TEN_PERCENT = 0.1;
    const double TWENTY_PERCENT = 0.2;
    const double THIRTY_PERCENT = 0.3;

    //main loop condition
    bool running = true;

    cout << "\nWelcome to The Income Tax Calculator 5000" << endl;

    // main loop
    while (running)
    {
        
        cout << "Press 'C' to CONTINUE or 'Q' to QUIT" << endl;
        cin >> entry_character;

        if (toupper(entry_character) == 'Q') // quits proggrame if input is "Q"
        {
            cout << "Have a nice day...Quiting Programme" << endl;
            running = false;
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

            while (toupper(gender) != 'M' && toupper(gender) != 'F') // make sure that the input in only either 'M' or 'F'
            {
                cout << "enter your gender (M -> male, F -> female): ";
                cin >> gender;
                cout << "\n";
            }
            
            cout << "enter year of birth: ";
            cin >> year_of_birth;

            while (cin.fail()) // check to see if age is a valid interger input
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error. Expected interger, entered string ";
                cout << "Enter birth year again: ";
                cin >> year_of_birth;
            }

            age = CURRENT_YEAR - year_of_birth; // calculates age using current year as 2023
            cout << "\n";

            cout << "Enter number of hours worked in this week: ";
            cin >> hours_worked;

            while (cin.fail()) // check to see if hours_worked is a valid interger input
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Error. Expected interger, entered string";
                cout << "Enter hours worked again: ";
                cin >> hours_worked;
            }
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

             
            if (age < age_55 && toupper(gender) == 'M') // sees the persons age and and calculates their corresponding income tax.
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
            else if (age < age_55 && toupper(gender) == 'F')
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
            else if (age <= age_80)
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
            else if (age > age_80)
            {
                tax = 0;
            }
            else
                cout << "error, try again" << endl;
        

            //outputs
            cout << "<------- INCOME TAXT CALCULATOR ------->     " << endl;
            cout << "Name:                " << first_name << " " << surname << endl;
            cout << "Employee ID:         "<< employee_id << endl; 
            cout << "Age:                 "<< age << endl;
            cout << "Gender               " << ((toupper(gender) == 'M') ? "Male" : "Female") << endl; // ternary operator that validates sex as Male if 'M' and Female if 'F'
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

    return 0;
}