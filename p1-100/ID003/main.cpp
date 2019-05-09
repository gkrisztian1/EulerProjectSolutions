#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  unsigned long long num = 600851475143 ;
  vector<unsigned int> primes;
  set<unsigned int> factors;
  
  ifstream f;
  f.open("primes-to-100k.txt");
  unsigned int line;
  while(f >> line) {primes.push_back(line);}
  f.close();
  
  for(const auto i: primes)
  {
      if(num % i == 0)
      {
          factors.insert(i);
          num = num / i;
          cout<<i<<endl;
      }
  }
  
  
  cout<<"The solution is "<<*factors.rbegin()<<endl;
  return 0;
}
