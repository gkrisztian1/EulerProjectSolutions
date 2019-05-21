#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void export_answer(stringstream &);


int main()
{
    stringstream s;
    int r1 = 1000;
    unsigned     int sum = 0;
    for(    int i = 1; i < r1; i++)
    {   
        bool     s1 = i % 3 == 0;
        bool s2 = i % 5 == 0;
        if (s1 || s2)
        {
            sum += i;
        }
    } 
    s << sum;
    export_answer(s);
    return 0;
}


void export_answer(stringstream &sstream)
{
    fstream f;
    f.open("solution.txt", ios::out);
    f << sstream.str();
    f.close();
}
