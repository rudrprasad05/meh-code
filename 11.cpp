// // RUDR RAVI PRASAD s11219309

// #include <iostream>

// using namespace std;

// int main()
// {
//     double sum = 0;
//     int count = 0;
//     double average;

//     for (int i = 1; i <=1000; i++)
//     {
//         if (i % 7 == 0 && i % 2 != 0)
//         {
//             sum += i;
//             count++;
//         }
//         average = sum / count;
        
//     }
//     cout << "the average is " << average << endl;
//     cout << "Rudr Prasad s11219309";
// }

 // RUDR RAVI PRASAD s11219309

#include <iostream>

using namespace std;

int main()
{
     double sum = 0;
     int count = 0;
     double average;

     for (int i = 1; i <=1000; i++)
     {
          if (i % 7 == 0 && i % 2 != 0)
          {
               sum += i;
               count++;
          }
     }
     average = sum / count;

     cout << "the average is " << average << endl;
     cout << "Rudr Prasad s11219309";
}
