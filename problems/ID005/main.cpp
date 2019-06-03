#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void export_answer(stringstream &);
bool test_number(unsigned long long);

int main()
{
    stringstream s;
    int sol = 1;
    while(!test_number(sol)){++sol;}
    s << sol;
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


bool test_number(unsigned long long number)
{
    bool flag = true;
    for(int i = 1; i < 21; i++)
    {
        if((number % i) != 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
