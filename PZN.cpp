#include <iostream>
#include <cmath>
using namespace std;

int calculate_PZN(int PZN)
{
    int weightedSum = 0;
    int num_digits = (int)log10(PZN) + 1;
    int factor = num_digits + 1;

    while (PZN > 0)
    {
        int digit = PZN % 10;
        weightedSum += digit * factor;
        PZN /= 10;
        factor--;
    }

    return weightedSum % 11;
}

int main()
{
    int number = 435713;
    cout << "PZN = " << calculate_PZN(number) << endl;

    return 0;
}