#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void export_answer(stringstream &);


int main()
{
    stringstream s;
    int r0 = 100;
    unsigned long long square_sum = 0;
    unsigned long long sum_square = 0;

    for(int i = 1; i < r0 + 1; i++)
    {
        square_sum += i * i;
        sum_square += i;
    }
    s << sum_square * sum_square - square_sum;

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
