#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int num1;
    double count;
    double mean;
    while (num1 >= 0)
    {
        sum += num1;
        count++;
        cout << "enter number: ";
        cin >> num1;
    }

    cout << "sum = "<< sum << endl;

    mean = sum / count;
    
    cout << "mean = " << mean << endl;
    return 0;
}