#include <iostream>

using namespace std;

int main()
{
  int r1 = 1000;
  unsigned int sum = 0;
  for(int i = 1; i < r1; i++)
    {
      bool s1 = i % 3 == 0;
      bool s2 = i % 5 == 0;
      if (s1 || s2)
	{
	  sum += i;
	}
    }
  cout<<"The solution is "<<sum<<endl;
  return 0;
}
