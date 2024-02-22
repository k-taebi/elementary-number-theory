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
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    long c = a % b;
    return gcd(b, c);
}