#include "window.h"

Window::Window()
{
    w = array<int, W * W>{};
    maxv = 0;
}

Window::~Window() {}

void Window::print_window()
{
    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < W; j++)
        {
            cout<<setw(3)<<w[i * W + j];
        }
        cout<<endl;
    }
}

void Window::copy_row(const int* arr, int bg)
{
    copy(arr, arr + W, w.begin() + bg * W);
}

void Window::copy_window(const int *arr)
{
    for(int i = 0; i < W; i++) { copy_row(arr + i * D, i); }
}

void Window::test_window()
{
    set<unsigned long> values;
    unsigned long dval1 = 1;
    unsigned long dval2 = 1;

    for(int i = 0; i < W; i++)
    {
        unsigned long hval = 1;
        unsigned long vval = 1;


        for(int j = 0; j < W; j++)
        {
            hval *= w[i * W + j];
            vval *= w[j * W + i];
        }

        values.insert(hval);
        values.insert(vval);

        dval1 *= w[i * W + i];
        dval2 *= w[i * (W - 1) + (W - 1)];
    }

    values.insert(dval1);
    values.insert(dval2);

    if (*values.rbegin() > maxv)
    {
        maxv = *values.rbegin();
    }
}


unsigned long Window::get_best() const { return maxv; }
