#include <iostream>
#include <sstream>
#include <fstream>
#include "BigNum.hpp"
#include "numbers.hpp"

using namespace std;

void export_answer(stringstream &);


int main()
{
    stringstream s;
    BigNum b;

    for (int i = 0; i < 100; ++i)
    {
     BigNum o{numbers[i]};
     b = b + o;

    }
    s << b;
    export_answer(s);
    return 0;
}


void export_answer(stringstream &sstream)
{
    fstream f;
    f.open("../solution.txt", ios::out);
    f << sstream.str();
    f.close();
}
