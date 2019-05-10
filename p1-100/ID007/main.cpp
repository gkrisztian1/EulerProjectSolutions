#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(unsigned long long);

int main()
{
    unsigned long long i = 0;
    int        numprimes = 0;
    while (true)
    {
        if (is_prime(i))
        {
            ++numprimes;
            if (numprimes == 10001) {break;}
        }
        ++i;
    }
    cout<<"The solution is "<<i<<endl;
    return 0;
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
