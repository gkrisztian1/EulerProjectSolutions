#include <iostream>

using namespace std;

bool test_number(unsigned long long);

int main()
{
    int sol = 1;
    while(!test_number(sol)){++sol;}
    cout<<"The solution is "<<sol<<endl;
    return 0;
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