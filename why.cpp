#include <iostream>
#include <chrono>
#include <thread>
#include <sstream> 

using namespace std;


int main()
{
    string tempI;
    string tempJ;
    string tempK;
    for (int i = 0; i < 24; i++)
    {
        if (i < 10)
        {
            tempI = '0' + to_string(i);
        }
        else
        {
            tempI = to_string(i);
        }
        for (int j = 0; j < 60; j++)
        {
            if (j < 10)
            {
                tempJ = '0' + to_string(j);
            }
            else
            {
                tempJ = to_string(j);
            }
            for (int k = 0; k  < 60; k++)
            {
                if (k < 10)
                {
                    tempK = '0' + to_string(k);
                }
                else
                {
                    tempK = to_string(k);
                }
                cout << tempI << ":" << tempJ << ":" << tempK << endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }
}
