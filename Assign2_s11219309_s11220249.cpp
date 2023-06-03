/*

Below is the assignment 2 of cs111 semester 1, 2023
Rudr Prasad - s11219309
Arshiya Prasad - s11220249

*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// global variables and constants

//const
const int MAX_ENTRIES = 300;
const int CURRENT_YEAR = 2023;

//table fomarting const only. Not used in computation
const int THRITY_TWO_SPACING = 32;
const int EIGHTEEN_SPACING = 18;
const int SIXTEEN_SPACING = 16;
const int TEN_SPACING = 10;
const int EIGHT_SPACING = 8;
const int SEVEN_SPACING = 7;
const int SIX_SPACING = 6;
const int FIVE_SPACING = 5;

// classes
ifstream file; //ifstream = input stream = reads data
ofstream write_file;


// updtaes age array. Loops through year of births array and subtracts from current year
void updateAgeArray(int count, int age[], int birth_year[]);

// used only to format the tables in cout and txt files
string formatTable(int width);

// together with updateAgeArray, prints age onto console
void calculateAge(string lastName[], string firstName[], int studentId[], int birth_year[], double gpa[], int age[], int count);

// used with sortAscending to sort arrays according to gpa in ascending order. 
void swap(int index, int minIndex, string firstName[], string lastName[], int id[], int age[], double gpa[]);

// sorts gpa in ascending order. Calls swap function to swap other arrays accordingly
void sortAscending(int length, string firstName[], string lastName[], int id[], int age[], double gpa[], int birth_year[]);

// prints sorted arrys according to acsending order of GPA
void printOrderedList(string lastName[], string firstName[], int studentId[], double gpa[], int age[], int count);

// returns boolean didItRun to see it search parameter produced a serach result or not
bool searchByLastName(char param, string arr[],int id[], int count);

// uses GPA array to calculate what type of honors the student will receive. 
void calculateDegree(string degree[], double gpa[], int count, int age[], int birthYear[]);

// wirtes data onto new file called Enrollments.txt
void writeFile(string lastName[], string firstName[], int studentId[], int birth_year[], double gpa[], int age[], int count, string degree[]);

// prints data onto console
void printAll(string lastName[], string firstName[], int studentId[], int birth_year[], double gpa[],int age[], string degree[], int count, int width);


int main(){
    // main loop boolean
    bool running = true;

    //arrays
    string last_name_arr[MAX_ENTRIES];
    string first_name_arr[MAX_ENTRIES];
    string degree_arr[MAX_ENTRIES];
    int id_arr[MAX_ENTRIES];
    int birth_year_arr[MAX_ENTRIES];
    double gpa_arr[MAX_ENTRIES];
    int age_arr[MAX_ENTRIES];

    // variable initialization
    int option;
    int counter = 0;
    int student_id; 
    int birth_year;
    double gpa;

    string dump_string;
    string last_name_string;
    string first_name_string;

    file.open("StudentRec.txt");

    // used to disregard the 1st 3 lines
    for(int i = 0; i < 3; i++)
    {
        getline(file, dump_string);
    }

    while(file >> last_name_string) // reads file and stores data in appropriate arrays 
    {
        
        file >> first_name_string;
        file >> student_id;
        file >> birth_year;
        file >> gpa;

        last_name_arr[counter] = last_name_string;
        first_name_arr[counter] = first_name_string;
        id_arr[counter] = student_id;
        birth_year_arr[counter] = birth_year;
        gpa_arr[counter] = gpa;

        counter++;
        
    }

    file.close();

    cout << "\nHello and welcome to Student Enrolment. Please select an option from the menu below" << endl;

    while(running && (counter < MAX_ENTRIES)) // checks to see if running is true and max entries (300 - set as constant) have not been exceeded. 
    {

        // menu options

        cout << "\n ---==[   Menu   ]==---\n" << endl;
        cout << "1. Print the entire class list\n" <<
            "2. Print the entire class list with inclusion of lastname, first name initial and age\n" <<
            "3. Print class list sorted by GPA\n" <<
            "4. Print class list of students which match a given lastname initial\n" <<
            "5. Calculate Degrees\n"
            "6. Create enrollmets.txt\n"
            "7. Exit\n";

 
        cout << "\nSelect an option: "; // prompts user to select an option, 1-7. Any other input is invalid and input is asked again
        cin >> option;
        cout << endl;

        while (cin.fail() || option < 1 || option > 7) // check to see if option is a valid interger input in range 1-7. Note: strings could have been used but ints were chosen
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error! Invalid input, please enter menu option again: ";
            cin >> option;
        }

        // if statemnets that check for the value of variable option and run associated functions. 
        if (option == 1)
        {
            printAll(last_name_arr, first_name_arr, id_arr, birth_year_arr, gpa_arr, age_arr, degree_arr, counter, 91);
        }

        else if (option == 2)
        {
            calculateAge(last_name_arr, first_name_arr, id_arr, birth_year_arr, gpa_arr, age_arr, counter);
    
        }
        else if (option == 3)
        {   
            sortAscending(counter, first_name_arr, last_name_arr, id_arr, age_arr, gpa_arr, birth_year_arr);
            printOrderedList(last_name_arr, first_name_arr, id_arr, gpa_arr, age_arr, counter);
        
        }
        else if (option == 4)
        {
            char last_name_initial;
            cout << "Enter search parameter (inital of last name): ";
            cin >> last_name_initial;
            cout << "\n";

            while (cin.fail()) // check to see if option is a valid character is used
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error! Invalid input, please enter inital of last name again: ";
                cin >> last_name_initial;
            }
            if (!searchByLastName(last_name_initial, last_name_arr, id_arr, counter))
            {
                cout << "no matching record found" << endl;
            }
        }

        else if (option == 5)
        {
            printAll(last_name_arr, first_name_arr, id_arr, birth_year_arr, gpa_arr, age_arr, degree_arr, counter, 91);
            
        }

        else if (option == 6)
        {
            writeFile(last_name_arr, first_name_arr, id_arr, birth_year_arr, gpa_arr, age_arr, counter, degree_arr);
            cout << "File written successfully. Created in same directory" << endl;
          
        }

        else if (option == 7)
        {
            // exit programme
            cout << "Exiting programme..." << endl;
            running = false;
        }
        else
        {
            // check for any other input. return to start of loop. 
            cout << "Invalid input. Try again" << endl;
        }

    }
    
    return 0;
}


void updateAgeArray(int count, int age[], int birth_year[])
{
    for (int i = 0; i < count; i++)
    {
        age[i] = CURRENT_YEAR - birth_year[i];
    }
}

string formatTable(int width)
{
    // Width and tableString are just used to format the table printed. 
    // Width is arbitary, set to make space for all sections of table depending on what sections were required.

    string tableString;
    for (int i = 0; i < width; i++)
    {
        tableString += "-";
    }
    return tableString;
}

void calculateAge(string lastName[], string firstName[], int studentId[], int birth_year[], double gpa[], int age[], int count)
{
    updateAgeArray(count, age, birth_year);
    
    string table_string = formatTable(70);
    cout << " |" << table_string << "| " << endl;
    cout << " | " << setw(TEN_SPACING) << "Last Name" 
        << " | " << setw(TEN_SPACING) << "Initial"
        << " | " << setw(TEN_SPACING) << "First Name" 
        << " | " << setw(FIVE_SPACING) << "ID" << setw(SIX_SPACING)
        << " | " << setw(FIVE_SPACING) << "Age" << setw(FIVE_SPACING)
        << " | " << setw(FIVE_SPACING) << "GPA" << setw(FIVE_SPACING)
        << " |"<<  endl;
    cout << " |" << table_string << "| " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << " | " << setw(SEVEN_SPACING) << lastName[i] << setw(SIX_SPACING)
            << " | " << setw(SIX_SPACING) << lastName[i][0] << setw(SEVEN_SPACING)
            << " | " << setw(SIX_SPACING) << firstName[i] << setw(SEVEN_SPACING)
            << " | " << setw(EIGHT_SPACING) << studentId[i]
            << " | " << setw(FIVE_SPACING) << age[i] << setw(FIVE_SPACING)
            << " | " << setw(FIVE_SPACING) << gpa[i] << setw(FIVE_SPACING)

            << " |"<<  endl;
    }

    cout << " |" << table_string << "|" << endl;
}

void swap(int index, int minIndex, string firstName[], string lastName[], int id[], int age[], double gpa[], int birth_year[])
{
    string tempstr; 
    int temp;
    double tempDouble;

    updateAgeArray(index, age, birth_year);

    //first name
    tempstr = firstName[index];
    firstName[index] = firstName[minIndex];
    firstName[minIndex] = tempstr;

    //surname
    tempstr = lastName[index];
    lastName[index] = lastName[minIndex];
    lastName[minIndex] = tempstr;
    
    //id
    temp = id[index];
    id[index] = id[minIndex];
    id[minIndex] = temp;

    //age
    temp = age[index];
    age[index] = age[minIndex];
    age[minIndex] = temp;

    //swap income array elements temp = income[index];
    tempDouble = gpa[index];
    gpa[index] = gpa[minIndex];
    gpa[minIndex] = tempDouble;

}

void sortAscending(int length, string firstName[], string lastName[], int id[], int age[], double gpa[], int birth_year[])
{
    int minPos;
    double min;
  
    for (int i = 0; i < length - 1; i++)
    {
        min = gpa[i];
        minPos = i;
        for (int j = i+1; j < length; j++)
        {
            if (gpa[j] < min)
            {
                min = gpa[j];
                minPos = j;    
            }
             
        }
        swap(i, minPos, firstName, lastName, id, age, gpa, birth_year);
        
    }
    
}

void printOrderedList(string lastName[], string firstName[], int studentId[], double gpa[], int age[], int count)
{
    string table_string = formatTable(34);
    
    cout << " |" << table_string << "|" << endl;
    cout << " | " << setw(TEN_SPACING) << "Last Name"
        << " | " << setw(FIVE_SPACING) << "ID" << setw(SIX_SPACING)
        << " | " << setw(FIVE_SPACING) << "GPA" << setw(FIVE_SPACING)
        << " |"<<  endl;
    cout << " |" << table_string << "|" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << " | " << setw(SIX_SPACING) << lastName[i][0] << setw(SEVEN_SPACING)
             << " | " << setw(EIGHT_SPACING) << studentId[i]
             << " | " << setw(SIX_SPACING) << gpa[i] << setw(FIVE_SPACING)
             << " | "<<  endl;
    }
    cout << " |" << table_string << "|" << endl;
}

bool searchByLastName(char param, string arr[],int id[], int count)
{
    bool didItRun = false;
    for (int i = 0; i <= count; i++)
    {
        size_t found_upper = arr[i].find(toupper(param));
        if (found_upper == 0)
        {
            cout << "Last Name: "<< arr[i]<< endl << "ID number: " << id[i] << endl;
            
            didItRun = true;
        }
    
    }
    return didItRun;
    
}

void calculateDegree(string degree[], double gpa[], int count, int age[], int birthYear[])
{

   for (int i = 0; i < count; i++)
    {
        age[i] = CURRENT_YEAR - birthYear[i];
    }
    string degreeClass;
    for (int i = 0; i < count; i++)
    {
        if (gpa[i] == 4)
        {
            degreeClass = "First-class honours";
            degree[i] = degreeClass;
        }
        else if (gpa[i] <= 3.9 && gpa[i] >= 3.3)
        {
            degreeClass = "Upper second-class honours";
            degree[i] = degreeClass;
            
        }
        else if (gpa[i] <=3.2 && gpa[i] >= 2.7)
        {
            degreeClass = "Lower second-class honours";
            degree[i] = degreeClass;
            
        }
        else if (gpa[i] <= 2.6 && gpa[i] >=2)
        {
            degreeClass = "Third class honours";
            degree[i] = degreeClass;
            
        }
        else if (gpa[i] <=1.9 && gpa[i] >=0)
        {
            degreeClass = "Ordinary degree";
            degree[i] = degreeClass;
            
        }
      
    }

}

void writeFile(string lastName[], string firstName[], int studentId[], int birth_year[], double gpa[], int age[], int count, string degree[])
{
    write_file.open("Enrollments.txt");

    calculateDegree(degree, gpa, count, age, birth_year);
    updateAgeArray(count, age, birth_year);

    string table_string = formatTable(104);

    write_file << " |" << table_string << "| " << endl;
    write_file << " | " << setw(TEN_SPACING) << "Last Name" 
        << " | " << setw(TEN_SPACING) << "Initial"
        << " | " << setw(TEN_SPACING) << "First Name" 
        << " | " << setw(FIVE_SPACING) << "ID" << setw(SIX_SPACING)
        << " | " << setw(FIVE_SPACING) << "Age" << setw(FIVE_SPACING)
        << " | " << setw(FIVE_SPACING) << "GPA" << setw(FIVE_SPACING)
        << " | " << setw(SIXTEEN_SPACING) << "Degree" << setw(EIGHTEEN_SPACING )
        << " |"<<  endl;
    write_file << " |" << table_string << "| " << endl;

    for (int i = 0; i < count; i++)
    {
        write_file << " | " << setw(SEVEN_SPACING) << lastName[i] << setw(SIX_SPACING)
            << " | " << setw(SIX_SPACING) << lastName[i][0] << setw(SEVEN_SPACING)
            << " | " << setw(SIX_SPACING) << firstName[i] << setw(SEVEN_SPACING)
            << " | " << setw(EIGHT_SPACING) << studentId[i]
            << " | " << setw(FIVE_SPACING) << age[i] << setw(FIVE_SPACING)
            << " | " << setw(FIVE_SPACING) << gpa[i] << setw(FIVE_SPACING)
            << " | " << setw(THRITY_TWO_SPACING) << degree[i]
            

            << " |"<<  endl;
    }

    write_file << " |" << table_string << "|" << endl;
    write_file.close();
}

void printAll(string lastName[], string firstName[], int studentId[], int birth_year[], double gpa[],int age[], string degree[], int count, int width)
{
    updateAgeArray(count, age, birth_year);
    calculateDegree(degree, gpa, count, age, birth_year);
    
    string table_string = formatTable(width);
    cout << " |" << table_string << "| " << endl;
    cout << " | " << setw(TEN_SPACING) << "Last Name" 
        << " | " << setw(TEN_SPACING) << "First Name" 
        << " | " << setw(FIVE_SPACING) << "ID" << setw(SIX_SPACING)
        << " | " << setw(FIVE_SPACING) << "Age" << setw(FIVE_SPACING)
        << " | " << setw(FIVE_SPACING) << "GPA" << setw(FIVE_SPACING)
        << " | " << setw(EIGHTEEN_SPACING) << "Degree" << setw(SIXTEEN_SPACING)
        << " |"<<  endl;
    cout << " |" << table_string << "| " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << " | " << setw(SEVEN_SPACING) << lastName[i] << setw(SIX_SPACING)
            << " | " << setw(SIX_SPACING) << firstName[i] << setw(SEVEN_SPACING)
            << " | " << setw(EIGHT_SPACING) << studentId[i]
            << " | " << setw(FIVE_SPACING) << age[i] << setw(FIVE_SPACING)
            << " | " << setw(FIVE_SPACING) << gpa[i] << setw(FIVE_SPACING)
            << " | " << setw(THRITY_TWO_SPACING) << degree[i]
            << " |"<<  endl;
    }

    cout << " |" << table_string << "| " << endl;
}
