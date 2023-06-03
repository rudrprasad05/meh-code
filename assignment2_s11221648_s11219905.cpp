#include <iostream>
#include <fstream>

using namespace std;

// constants
const int MAX_NUMBER_OF_ENTRIES = 300;

ifstream file_reader;

// arrays
string last_name_arr[MAX_NUMBER_OF_ENTRIES];
string first_name_initial_arr[MAX_NUMBER_OF_ENTRIES];
int year_of_birth_arr[MAX_NUMBER_OF_ENTRIES];
int student_id_arr[MAX_NUMBER_OF_ENTRIES];
double gpa_arr[MAX_NUMBER_OF_ENTRIES];


int main()
{
    // variable init
    bool running = true;
    int count = 0;
    char option;

    
    cout << "\nStudent Enrollment Software" << endl;

    cout << "Select an option from the menu below ( enter between range 1 - 7 )" << endl;

    // varibale used to extract text from file
    string last_name;
    string dump_string;
    string first_name_inital;
    int year_of_birth;
    int student_id;
    double gpa;

    file_reader.open("StudentRec.txt");

    // used to disregard the 1st 3 lines
    for(int i = 0; i < 3; i++)
    {
        getline(file_reader, dump_string);
    }

    while(!file_reader.eof()) // reads file and stores data in appropriate arrays 
    {
        file_reader >> last_name;
        file_reader >> first_name_inital;
        file_reader >> student_id;
        file_reader >> year_of_birth;
        file_reader >> gpa;

        last_name_arr[count] = last_name;
        first_name_initial_arr[count] = first_name_inital;
        student_id_arr[count] = student_id;
        year_of_birth_arr[count] = year_of_birth;
        gpa_arr[count] = gpa;

        count++;
    }

    file_reader.close();
    

    while(running && (count < MAX_NUMBER_OF_ENTRIES)) 
    {

        cout << "1. Print the entire class list" << endl;
        cout << "2. Print the entire class list with inclusion of lastname, first name initial and age" << endl;
        cout << "3. Print class list sorted by GPA" << endl;
        cout << "4. Print class list of students which match a given lastname initial" << endl;
        cout << "5. Calculate Degrees" << endl;
        cout << "6. Create enrollmets.txt" << endl;
        cout << "7. Exit" << endl;

 
        cout << "\nSelect an option: ";
        cin >> option;
        cout << endl;


        if(option == '1')
        {
            cout << "enter function 1 here" << endl;
           
        }
        else if(option == '2')
        {
            cout << "enter function 2 here" << endl;
           
        }
        else if(option == '3')
        {
            cout << "enter function 3 here" << endl;
           
        }
        else if(option == '4')
        {
            cout << "enter function 4 here" << endl;
           
        }
        else if(option == '5')
        {
            cout << "enter function 5 here" << endl;
           
        }
        else if(option == '6')
        {
            cout << "enter function 6 here" << endl;
           
        }
        else if(option == '7')
        {
            cout << "Exit proggrame" << endl;
            running = false;
           
        }
        else cout << "Invalid input. Type number between 1 - 7" << endl;
    }

    return 0;

}

