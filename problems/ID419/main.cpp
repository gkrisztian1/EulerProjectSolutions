#include <iostream>
#include <sstream>
#include <fstream>

void export_answer(stringstream &);

using namespace std;


int main()
{
    stringstream s;
    
    
    return 0;
}


void export_answer(stringstream &sstream)
{
    ofstream f("solution.txt", "w");
    f.write(sstream.str());
    f.close();
}