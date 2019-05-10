#include <iostream>

using namespace std;

int main()
{
    int sol = 1;
    int r0 = 100;
    unsigned long long square_sum = 0;
    unsigned long long sum_square = 0;
    
    for(int i = 1; i < r0 + 1; i++)
    {
        square_sum += i * i;
        sum_square += i;
    }
    sol = sum_square * sum_square - square_sum;
    cout<<"The solution is "<<sol<<endl;
    return 0;
}
