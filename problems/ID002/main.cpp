#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void export_answer(stringstream &);

unsigned long long fib(unsigned long long);

int main()
{
    stringstream s;
    int i = 1;
    unsigned long long sum = 0;
    while(true)
    {
        unsigned long long num = fib(i);
        if (num < 4e6)
        {
            if (num % 2 ==0)
            {
                cout<<i<<"\t"<<num<<endl;
                sum += num;
            }
        } else
        {
            break;
        }
        ++i;
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

unsigned long long fib(unsigned long long x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    else {
        return fib(x - 1) + fib(x - 2);
    }
}
