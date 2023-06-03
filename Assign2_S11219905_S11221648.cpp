#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// constants
const int MAX_NUMBER_OF_ENTRIES = 300;

ifstream file_reader;

// arrays
string lastNameArr[MAX_NUMBER_OF_ENTRIES];
string FNameInitialArr[MAX_NUMBER_OF_ENTRIES];
int BitrhYearArr[MAX_NUMBER_OF_ENTRIES];
int StudentIdArr[MAX_NUMBER_OF_ENTRIES];
double GPAArr[MAX_NUMBER_OF_ENTRIES];
int age[MAX_NUMBER_OF_ENTRIES];
int degreeClassifArr[MAX_NUMBER_OF_ENTRIES];
string degreeArr[MAX_NUMBER_OF_ENTRIES];


void SortAscending(int nElements,string initial[] , int id[], int birth_year[],double gpa[], int age[],string lastname[], string degree[], string firstname[]);
void Swap(int index, int minIndex, string initial[], int id[], int birth_year[], double gpa[],int age [], string lastname[], string degree[],string firstname[]);
void printAll(string last_name[], string first_name[], int student_id[], double gpa[], int birth_year[], int count, int age[], string degree[]);
void calculateAge(int age[], int year_of_birth[], int count);
void displayDegreeClassification(double gpa[], int count, string degree[]);
void printListIncludingLastNameInitial(string last_name[], string first_name[], int student_id[], double gpa[], int count);

int main()
{
    // variable initialization
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

    while(file_reader >> last_name) // reads file and stores data in appropriate arrays 
    {
        
        file_reader >> first_name_inital;
        file_reader >> student_id;
        file_reader >> year_of_birth;
        file_reader >> gpa;

        lastNameArr[count] = last_name;
        FNameInitialArr[count] = first_name_inital;
        StudentIdArr[count] = student_id;
        BitrhYearArr[count] = year_of_birth;
        GPAArr[count] = gpa;

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

		//prints the entire class list
        if(option == '1')
        {
            printAll(lastNameArr, FNameInitialArr,  StudentIdArr,  GPAArr, BitrhYearArr, count,  age, degreeArr);
        }
        //prints the entire class list with inclusion of last name initial and age
        else if(option == '2')
        {
            printListIncludingLastNameInitial(lastNameArr, FNameInitialArr, StudentIdArr, GPAArr, count);
           
        }
        //print class list sorted by GPA
        else if(option == '3')
        {
            SortAscending(count, lastNameArr, StudentIdArr, BitrhYearArr, GPAArr, degreeClassifArr, lastNameArr, lastNameArr, FNameInitialArr);
            printAll(lastNameArr, FNameInitialArr,  StudentIdArr,  GPAArr,  BitrhYearArr,  count,  age, degreeArr);
        	
		}
		//prints class list of students which match a given lastname initial
        else if(option == '4')
        {
            cout << "enter function 4 here" << endl;
           
        }
        //calculates and displays the corresponding degree classification as per GPA
        else if(option == '5')
        {
            cout << "enter function 5 here" << endl;
           
        }
        //produces file
        else if(option == '6')
        {
            cout << "enter function 6 here" << endl;
           
        }
        //exits program
        else if(option == '7')
        {
            cout << "Exit proggrame" << endl;
            running = false;
           
        }
        else cout << "Invalid input. Type number between 1 - 7" << endl;
    }

    return 0;

}

void printAll(string last_name[], string first_name[], int student_id[], double gpa[], int birth_year[], int count, int age[], string degree[])
{
	calculateAge(age, birth_year, count);
	displayDegreeClassification(gpa, count, degree);
    
	for (int i = 0; i < count; i++)
	{
		cout << " " << setw(5) << last_name[i] << " " << setw(5) ;
		cout << " " << setw(5) << first_name[i] << " " << setw(5) ;
		cout << " " << setw(5) << student_id[i] << " " << setw(5) ; 
		cout << " " << setw(5) << gpa[i] << " " << setw(5) ;
		cout << " " << setw(5) << age[i] << " " << setw(5) ;
		cout << " " << setw(15) << degree[i] << " " << setw(5);
		cout << " " << setw(10) << birth_year[i] << endl;
	}	
}

void printListIncludingLastNameInitial(string last_name[], string first_name[], int student_id[], double gpa[], int count)
{
    
	for (int i = 0; i < count; i++)
	{
		cout << " " << setw(5) << last_name[i] << " " << setw(5) ;
        cout << " " << setw(5) << last_name[i][0] << " " << setw(5) ;
		cout << " " << setw(5) << first_name[i] << " " << setw(5) ;
		cout << " " << setw(5) << student_id[i] << " " << setw(5) ; 
		cout << " " << setw(5) << gpa[i] << endl;
		
	}	
}


void SortAscending(int nElements,string initial[] , int id[], int birth_year[],double gpa[], int age[],string lastname[], string degree[], string firstname[])
{
	 double min;
	 int minPos;
	 for (int i=0; i<nElements-1; i++)
	 {
	 	min = gpa[i];
	 	minPos = i;
			 for (int j=i+1;j<nElements;j++)
			 if(gpa[j] < min)
			 {
			 min = gpa[j];
			 minPos = j;
	 		}
	 Swap(i, minPos, initial, id, birth_year, gpa, age, lastname, degree, firstname);
	 }
}


void Swap(int index, int minIndex, string initial[], int id[], int birth_year[], double gpa[],int age [], string lastname[], string degree[],string firstname[])
{
	string tempstr;
	double temp;
	//swap initial array elements
	 tempstr = initial[index];
	 initial[index] = initial[minIndex];
	 initial[minIndex] = tempstr;
	 
	//swap lastname array elements
	 tempstr = lastname[index];
	 lastname[index] = lastname[minIndex];
	 lastname[minIndex] = tempstr;
	 
	//swap id array elements
	 temp = id[index];
	 id[index] = id[minIndex];
	 id[minIndex] = temp;
	 
	//swap age array elements
	 temp = age[index];
	 age[index] = age[minIndex];
	 age[minIndex] = temp;
	 
	//swap gpa array elements
	 temp = gpa[index];
	 gpa[index] = gpa[minIndex];
	 gpa[minIndex] = temp; 
	 
	//swap first array elements
	 temp = gpa[index];
	 gpa[index] = gpa[minIndex];
	 gpa[minIndex] = temp;
	 
	 //swap degree array elements
	 tempstr = degree[index];
	 degree[index] = degree[minIndex];
	 degree[minIndex] = temp; 
	 
	 //swap gpa array elements
	 temp = gpa[index];
	 gpa[index] = gpa[minIndex];
	 gpa[minIndex] = temp; 
	
}

void calculateAge(int age[], int year_of_birth[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int tempAge = 2023 - year_of_birth[i];
		age[i] = tempAge;
	}
}

void displayDegreeClassification(double gpa[], int count, string degree[]) {
    string degreeTemp;
    for (int i = 0; i < count; i++)
    {
        if (gpa[i] >= 3.7) 
        {
            degreeTemp = "First Class Honours";
            degree[i] = degreeTemp;
        }
        else if (gpa[i] >= 3.3) 
        {
            degreeTemp = "Upper Second Class Honours";
            degree[i] = degreeTemp;
        }
        else if (gpa[i] >= 2.7) 
        {
            degreeTemp = "Lower Second Class Honours";
            degree[i] = degreeTemp;
        }
        else if (gpa[i] >= 2.0) 
        {
            degreeTemp = "Third Class Honours";
            degree[i] = degreeTemp;
        }
        else 
        {
            degreeTemp = "Fail";
            degree[i] = degreeTemp;
        }
    }

   
    
}





