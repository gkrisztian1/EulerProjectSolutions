#ifndef WINDOW_H
#define WINDOW_H

#include <iomanip>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
#include "grid.h"

#define SPLINE cout<<"--------------------------------------"<<endl;

using namespace std;

class Window
{
    public:
        Window();
        ~Window();

        void print_window();
        void test_window();
        void copy_window(const int *);
        unsigned long get_best() const;

    private:
        array<int, W * W> w; // hold the values of a windows
        unsigned long maxv;  // hold the largest product

        void copy_row(const int*, int);
};

#endif // WINDOW_H
