#include "gcd.h"
#include <iostream>
using namespace std;
long gcd(long a, long b)
{
    // if a and b are both zero, print an error and return 0
    if ((a == 0) && (b == 0))
    {
        cerr << "gcd is not defined for both arguments equal to zero."
             << endl;
        return 0;
    }
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    long new_a, new_b;
    while (b != 0)
    {
        new_a = b;
        new_b = a % b;
        a = new_a;
        b = new_b;
    }
    return a;
}