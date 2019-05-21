#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void export_answer(stringstream &);


int main()
{
    stringstream s;
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
    s << *factors.rbegin();

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
