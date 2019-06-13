#pragma once

#include <initializer_list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define W 50

class BigNum
{
    std::vector<int> digits;
public:
    BigNum();
    BigNum(const unsigned int * _digits);
    friend std::ostream &operator<<(std::ostream &os, const BigNum &num);
    BigNum operator+(const BigNum& other);
};
