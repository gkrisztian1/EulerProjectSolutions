#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <set>

using namespace std;

void export_answer(stringstream &);
bool is_palidrome(string);

int main()
{
    stringstream s;
    int r0 = 999;
    int r1 = 999;
    bool found = false;
    set<int> palidromes;
    for(int i = r0; i > 99; i--)
    {
        for(int j = r1; j > 99; j--)
        {
            stringstream ss;
            ss << i * j;
            if(is_palidrome(ss.str()))
            {
                //cout<<i<<"\t"<<j<<"\t"<<i * j<<endl;
                palidromes.insert(i * j);
            }
        }
    }

    s << *palidromes.rbegin();
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

bool is_palidrome(string s)
{
    string revs = s;
    reverse(revs.begin(), revs.end());
    return !s.compare(revs);
}
