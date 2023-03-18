#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int number = 0;
 char reply;
 bool is_positive;
 
 cout << "Enter a number: ";
 cin >> number;
 
 cout << "Enter a letter: ";
 cin >> reply;
 
 is_positive = (number >=0);
 
 if( is_positive && number < 10){
   cout << "Roses are red. "; 
 } 
 
 if(!is_positive){
   cout << "Violets are blue. " ; 
 }
 
 if(reply >= 'A' && reply <= 'Z'){
   cout << "Sugar is sweet. "; 
 }
 if(reply < 'A' || reply > 'M'){
   cout << "So are you. "; 
 } 

 cout << endl;

}
int main(){
int animals = 0;
int dogs, cats;
 
    cout << "How many dogs have you seen? ";
    cin >> dogs;
  
    if( dogs > 0 ){
      cout << "How many animals have you seen altogether? ";
      cin >> animals;
    cats = animals - dogs;
   }

   cout << "There were " << cats << " cats\n";
   cout << "There were " << dogs << " dogs\n";
   cout << "The percentage dogs is " << 100 * dogs/animals << "%\n";
   
   system("pause");
   return 0;