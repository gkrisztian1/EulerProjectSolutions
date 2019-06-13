//
// Created by gkris on 2019. 06. 13..
//

#include "BigNum.hpp"

BigNum::BigNum(): digits(W, 0) {}
BigNum::BigNum(const unsigned int* _digists): digits(_digists, _digists + W) {}

std::ostream &operator<<(std::ostream &os, const BigNum &num)
{
    for(int i = 0; i < 10; i++)
        //os << std::setw(3) << v;
        os << num.digits[i];

    return os;
}

BigNum BigNum::operator+(const BigNum &other)
{
    BigNum b;
    int mod = 0;
    for (int i = W - 1; i >= 0; --i)
    {
        int n = this->digits[i] + other.digits[i] + mod;
        b.digits[i] += n % 10;
        mod = n / 10;
    }
    b.digits[0] += mod*10;

    return b;
}
