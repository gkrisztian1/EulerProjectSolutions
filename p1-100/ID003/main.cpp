#include <iostream>

using namespace std;

unsigned long long fib(unsigned long long);

int main()
{
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
  
  cout<<"The solution is "<<sum<<endl;
  return 0;
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
