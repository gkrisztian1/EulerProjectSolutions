#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void export_answer(stringstream &);

struct triplet
{
    int a;
    int b;
    int c;

    bool valid;

    int sum;
    int mul;

};

void triplet_init     (triplet &);
void triplet_validate (triplet &);

int main()
{
    stringstream s;
    srand (time(NULL));
    triplet t;

    int maxiter = 1e6;
    int i = 0;
    do
    {
        triplet_init(t);
        triplet_validate(t);
        ++i;

    } while(!t.valid && i < maxiter);

    cout<<i<<" iteration"<<endl;
    s << t.mul;
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


void triplet_init(triplet &t)
{
    t.c = rand() % 499 + 1;
    t.b = rand() % 499 + 1;
    t.a = 1000 - t.b - t.c;
}

void triplet_validate(triplet &t)
{
    bool s0 = (t.a + t.b + t.c) == 1000;
    bool s1 = (t.a < t.b) < t.c;
    bool s2 = (t.a * t.a + t.b * t.b) == t.c * t.c;
    //cout<<s0<<" "<<s1<<" "<<s2<<endl;

    if (s0 && s1 && s2)
    {
        t.valid = true;
        t.sum = t.a + t.b + t.c;
        t.mul = t.a * t.b * t.c;
    } else
    {
        t.valid = false;
        t.sum = 0;
        t.mul = 0;
    }
}
