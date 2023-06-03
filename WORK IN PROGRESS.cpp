#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

using namespace std;

const int CAPACITY = 300;
const int CURRENT_YEAR = 2023;

// Function to sort student records in ascending order based on last name
void SortAscending(int nElements, string initial[], int id[], int birth_year[], double income[], int age[], string lastname[]);

// Function to swap the position of two elements in the arrays
void Swap(int index, int minIndex, string initial[], int id[], int birth_year[], double income[], int age[], string lastname[]);

// Function to get the degree classification based on GPA
string GetDegreeClassification(double gpa);

void CalculateAge(int size, int age[], int yob[], string lname_initial[], string lname[], char fname[], int id[], double gpa[]);

void SearchName(int size, string lname_initial[], string searchInitial, string lname[], int id[]);

int main()
{
	// Open the file containing student records
	ifstream StudentFile;
	StudentFile.open("StudentRec.txt");

	// Arrays to store student information
	string lname[CAPACITY];
	char fname[CAPACITY];
	int id[CAPACITY];
	int yob[CAPACITY];
	double gpa[CAPACITY];
	int age[CAPACITY];
	string lname_initial[CAPACITY];
	int size = 0;

	string dummy;
	int input;

	// Skips the first three lines in the file
	for (int i = 0; i < 3; i++)
	{
		getline(StudentFile, dummy);
	}
	
	// Read student records from the file
	while (!StudentFile.eof())
	{
		StudentFile >> lname[size];
		StudentFile >> fname[size];
		StudentFile >> id[size];
		StudentFile >> yob[size];
		StudentFile >> gpa[size];
		size++;
	}

	StudentFile.close();

	size = size - 1;	// Adjust the size to exclude the extra iteration

	// Menu-driven program loop
	while (input != 7)
	{
		// Display menu options
		cout << "Welcome to the program. Please select an option:\n\n";
		cout << "1. Print the entire class list\n";
		cout << "2. Print the entire class list with inclusion of last name initial and age\n";
		cout << "3. Print the class list sorted by GPA\n";
		cout << "4. Print the class list of students matching a given last name initial\n";
		cout << "5. Calculate and display the degree classification\n";
		cout << "6. Produce a file called Enrollments.txt\n";
		cout << "7. Exit program\n\n";

		cin >> input;

		// Validate user input for an integer
		while (cin.fail())
		{
			cin.clear();
			string notint;
			cin >> notint;
			cout << "Input " << notint << " is not an integer. Enter an integer.\n";
			cin >> input;
		}
		
			if (input < 1 || input > 7)
		{
		    cout << "Please enter a valid input.\n";
		}
		else if (input == 1)
		{
			// Display student information: Last Name, First Name, ID, Year of Birth (YOB), and GPA.
		    cout << setw(15) << "Last Name" << setw(15) << "First Name" << setw(10) << "ID" << setw(15) << "YOB" << setw(11) << "GPA" << setw(29) << "Degree Classification" << endl;
		    for (int i = 0; i < size; i++)
		    {
		    	 // Output the details of each student.
		        cout << setw(15) << lname[i] << setw(15) << fname[i] << setw(16) << id[i] << setw(10) << yob[i] << setw(10) << gpa[i] << setw(34) << GetDegreeClassification(gpa[i]) << endl;
		    }
		}
		else if (input == 2)
		{
			CalculateAge(size, age, yob, lname_initial, lname, fname, id, gpa);
			
		}
		else if (input == 3)
		{
			// Sort the student records in ascending order based on last name initial.
		    SortAscending(size, lname_initial, id, yob, gpa, age, lname);
		
			// Display student information: Last Name Initial, ID, and GPA.
		    cout << setw(15) << "Initial" << setw(10) << "ID" << setw(16) << "GPA" << endl;
		    for (int i = 0; i < size; i++)
		    {
		    	// Output the details of each student.
		        cout << setw(15) << lname_initial[i] << setw(16) << id[i] << setw(10) << gpa[i] << endl;
		    }
		
		    cout << endl;
		}
		else if (input == 4)
		{
			// Search for student records based on the given last name initial.
		    cout << "Enter the last name initial to search : " ;		    
		    string searchInitial;
		    cin >> searchInitial;

			SearchName(size, lname_initial, searchInitial, lname, id);

		
		    cout << endl;
		}
		else if (input == 5)
		{
			// Display student information: Last Name, First Name, ID, YOB, GPA, and Degree Classification.
		    cout << setw(15) << "Last Name" << setw(15) << "Initial" << setw(15) << "First Name" << setw(10) << "ID" << setw(15) << "YOB" << setw(12) << "GPA " << setw(28) << "Degree Classification" << endl;
		        for (int i = 0; i < size; i++)
		    {
		    	// Output the details of each student along with their degree classification.
		        cout << setw(15) << lname[i] << setw(15) << lname_initial[i] << setw(15) << fname[i] << setw(16) << id[i] << setw(10) << yob[i] << setw(10) << gpa[i] << setw(34) << GetDegreeClassification(gpa[i]) << endl;
		    }
		
		    cout << endl;
		}
		else if (input == 6)
		{
			// Write student enrollment information to a file.
		    ofstream EnrollmentFile;
		    EnrollmentFile.open("Enrollments.txt");
		
		    if (EnrollmentFile.is_open())
		    {
		    	// Write the header to the file.
		        EnrollmentFile << setw(15) << "Last Name" << setw(15) << "Initial" << setw(15) << "First Name" << setw(10) << "ID" << setw(10) << "Age" << setw(10) << "GPA" << setw(20) << "Degree Classification" << endl;
		        for (int i = 0; i < size; i++)
		        {
		        	// Write the details of each student to the file along with their degree classification.
		            EnrollmentFile << setw(15) << lname[i] << setw(15) << lname_initial[i] << setw(15) << fname[i] << setw(10) << id[i] << setw(10) << age[i] << setw(10) << gpa[i] << setw(20) << GetDegreeClassification(gpa[i]) << endl;
		        }
		
		        cout << "Enrollments.txt file created successfully.\n";
		    }
		    else
		    {
		        cout << "Unable to create Enrollments.txt file.\n";
		    }
		
		    EnrollmentFile.close();
		}
		else if (input == 7)
		{
			// Exit the program.
		    cout << "Thank you for using the program!\n";
		}	
		
	}
		//Exit the main function		
		return 0;			
	}

// Function to sort an array of data based on the income in ascending order
void SortAscending(int nElements, string initial[], int id[], int birth_year[], double income[], int age[], string lastname[])
{
	double min;
	int minPos;
	// loop through the array
	for (int i = 0; i < nElements - 1; i++)
	{
		min = income[i];
		minPos = i;
		// find the minimum value in the remaining part of the array
		for (int j = i + 1; j < nElements; j++)
		{
			if (income[j] < min)
			{
				min = income[j];
				minPos = j;
			}
		}
		// swap the current element with the minimum element found
		Swap(i, minPos, initial, id, birth_year, income, age, lastname);
	}
}

// Function to swap two elements in an array
void Swap(int index, int minIndex, string initial[], int id[], int birth_year[], double income[], int age[], string lastname[])
{
	// temporarily store the values of the elements to be swapped
	string tempstr;
	int temp;

	tempstr = initial[index];
	initial[index] = initial[minIndex];
	initial[minIndex] = tempstr;

	tempstr = lastname[index];
	lastname[index] = lastname[minIndex];
	lastname[minIndex] = tempstr;

	temp = id[index];
	id[index] = id[minIndex];
	id[minIndex] = temp;

	temp = birth_year[index];
	birth_year[index] = birth_year[minIndex];
	birth_year[minIndex] = temp;

	temp = age[index];
	age[index] = age[minIndex];
	age[minIndex] = temp;

	temp = income[index];
	income[index] = income[minIndex];
	income[minIndex] = temp;
}

// Function to return the degree classification based on the provided GPA value
string GetDegreeClassification(double gpa)
{
	if (gpa >= 4.0)
	{
		return "First-class honours";
	}
	else if (gpa >= 3.3 && gpa <= 3.9)
	{
		return "Upper second-class honours";
	}
	else if (gpa >= 2.7 && gpa <= 3.2)
	{
		return "Lower second-class honours";
	}
	else if (gpa >= 2.0 && gpa <= 2.6)
	{
		return "Third class honours";
	}
	else if (gpa >= 0 && gpa <= 1.9)
	{
		return "Ordinary degree (no honours)";
	}
	else
	{
		return "Unknown";
	}
}

void CalculateAge(int size, int age[], int yob[], string lname_initial[], string lname[], char fname[], int id[], double gpa[])
{
	// Calculate the age of each student and extract the first letter of their last names.
	for (int i = 0; i < size; i++)
	{
		age[i] = CURRENT_YEAR - yob[i];
	}

	for (int i = 0; i < size; i++)
	{
		lname_initial[i] = lname[i].substr(0, 1);
	}

	cout << endl;
	
	// Display student information with age and last name initial.
	cout << setw(15) << "Last Name" << setw(15) << "Initial" << setw(15) << "First Name" << setw(10) << "ID" << setw(17) << "Age" << setw(9) << "GPA" << endl;
	for (int i = 0; i < size; i++)
	{
		// Output the details of each student.
		cout << setw(15) << lname[i] << setw(15) << lname_initial[i] << setw(15) << fname[i] << setw(16) << id[i] << setw(10) << age[i] << setw(10) << gpa[i] << endl;
	}

	cout << endl;
}

void SearchName(int size, string lname_initial[], string searchInitial, string lname[], int id[])
{
	
	// Display student information: Last Name and ID.
	cout << setw(15) << "Last Name" << setw(10) << "ID" << endl;
	for (int i = 0; i < size; i++)
	{
		// Check if the last name initial matches the search input.
		if (lname_initial[i][0].equals(searchInitial)
		{		        
			// Output the details of the matching student.
			cout << setw(15) << lname[i] << setw(16) << id[i] << endl;
			
		}else if (lname_initial[i].compare(searchInitial) != 0) 
		{
			cout << "No matching records found.\n";
		}
	}

		
}
