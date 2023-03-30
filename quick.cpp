#include <iostream>

using namespace std;

int main() {
    int sum = 0; // variable to store the sum of all numbers that meet the criteria
    int count = 0; // variable to keep track of how many numbers meet the criteria

    for (int i = 1; i <= 1000; i++) {
        if (i % 7 == 0 && i % 2 != 0) { // check if the number is a multiple of 7 but not a multiple of 2
            sum += i; // add the number to the sum
            count++; // increment the count
        }
    }

    double average = (double)sum / count; // calculate the average

    cout << "Rudr Prasad - s11219309" << endl;
    return 0;
}
