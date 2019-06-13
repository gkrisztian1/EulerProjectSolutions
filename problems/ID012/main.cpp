#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>


using namespace std;

void export_answer(stringstream &);
unsigned long long T(int n);
int num_of_divs(unsigned long long num);

int main()
{
    stringstream s;
    unsigned long long number = 1;


    while (num_of_divs(T(number)) < 500)
    {
       number++;

    }
    cout << number << "\t" << T(number) << endl;
    s << T(number);
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

unsigned long long T(int n) { return n * (n + 1) / 2; }
int num_of_divs(unsigned long long num)
{
    int nod = 0;
    unsigned long long end = static_cast<unsigned long long>(sqrt(num));

    for (int i = 1; i <= end ; ++i)
    {
        if (num % i == 0)
            nod += 2;
    }

    if (end * end == num)
        nod--;

    return nod;
}
