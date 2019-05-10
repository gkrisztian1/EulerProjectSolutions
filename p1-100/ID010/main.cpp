#include <iostream>
#include <vector>

using namespace std;

bool is_prime(unsigned long long);

int main()
{
    unsigned long long sol = 0;
    int r0 = 2e6;

    for(int i = 2; i < r0; i++)
    {
        if(is_prime(i))
        {
            sol += i;
        }
    }

    cout<<"The solution is "<<sol<<endl;
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
