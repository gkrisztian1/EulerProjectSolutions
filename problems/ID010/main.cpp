#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

void export_answer(stringstream &);

bool is_prime(unsigned long long);

int main()
{
    stringstream s;
    unsigned long long sol = 0;
    int r0 = 2e6;

    for(int i = 2; i < r0; i++)
    {
        if(is_prime(i))
        {
            sol += i;
        }
    }
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

bool is_prime(unsigned long long num)
{
    if (num <= 1) {return false;}
    if (num <= 3) {return  true;}

    if (num % 2 == 0 || num % 3 == 0) {return false;}

    for(int i = 5; i * i <= num; i = i + 6)
    {
        if (num % i == 0 || num % (i + 2) == 0) {return false;}
    }

    return true;
}
