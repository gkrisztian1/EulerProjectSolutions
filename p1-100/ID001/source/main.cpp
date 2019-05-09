#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  for(int i = 1; i < 10; i++)
    {
      cout<<i * 3<<setw(10)<<i * 5 <<endl;
    }
  return 0;
}
