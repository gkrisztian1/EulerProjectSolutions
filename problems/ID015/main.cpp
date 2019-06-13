#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void export_answer(stringstream &);


int main()
{
    stringstream s;
    
    export_answer(s);
    return 0;
}


void export_answer(stringstream &sstream)
{
    fstream f;
    f.open("../solution.txt", ios::out);
    f << sstream.str();
    f.close();
}
