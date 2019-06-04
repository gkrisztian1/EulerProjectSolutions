#include <iostream>
#include <sstream>
#include <fstream>
#include "grid.h"
#include "window.h"

#define D 20 // size of   grid
#define W  4 // size of window

using namespace std;

void export_answer(stringstream &);

unsigned long test_row(const int *);
unsigned long test_col(const int *);

int main()
{
    stringstream s;
    
	for(int i = 0; i < D; i++)
    {
        for(int j = 0; j < D; j++)
        {
            cout<<setw(3)<<grid[i * D + j];
        }
        cout<<endl;
    }
    SPLINE

    Window w0;
    w0.copy_window(grid + 1*D + 1);

    set<unsigned long> allmax;
    for(int i = 0; i < D - W; i++)
    {
        allmax.insert(test_row(grid + D * i));
        allmax.insert(test_col(grid + i));
    }
	
    s << *allmax.rbegin();
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

unsigned long test_row(const int *arr)
{
    Window w;
    set<unsigned long> values;
    for(int i = 0; i < D - W; i++)
    {
        w.copy_window(arr + i);
        w.test_window();
        values.insert(w.get_best());
    }

    return *values.rbegin();
}

unsigned long test_col(const int *arr)
{
    Window w;
    set<unsigned long> values;
    for(int i = 0; i < D - W; i++)
    {
        w.copy_window(arr + i * D);
        w.test_window();
        values.insert(w.get_best());
    }

    return *values.rbegin();
}