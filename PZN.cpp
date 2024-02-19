#include <algorithm>
#include "gcd.h"
#include <iostream>
#include <cmath>
#include <set>
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

int replace_digit(int num, int x, int y)
{
    std::string num_str = std::to_string(num);

    char char_x = '0' + x;
    char char_y = '0' + y;

    std::replace(num_str.begin(), num_str.end(), char_x, char_y);

    return stoi(num_str);
}

set<int> get_digits(int num)
{
    set<int> digits = {};
    int d;
    while (num > 0)
    {
        d = num % 10;
        digits.insert(d);
        num /= 10;
    }
    return digits;
}

set<int> get_divisors(int num)
{
    set<int> divisors = {};
    int d;
    for (int i = 1; i < num + 1; i++)
    {
        if (num % i == 0)
        {
            divisors.insert(i);
        }
    }
    return divisors;
}

int main()
{
    int number = 187377;
    int test_PZN = calculate_PZN(number);

    set<int> digits = get_digits(number);

    for (auto i : digits)
        for (int j = 0; j < 10; j++)
        {
            int new_number = replace_digit(number, i, j);
            if (calculate_PZN(new_number) == test_PZN)
            {
                cout << i << " " << j << endl;
            }
        }

    long x = 54, y = 24;
    cout << "The gcd of " << x << " and " << y << " is "
         << gcd(x, y) << endl;

    set<int> divisors_x, divisors_y, intersect;

    divisors_x = get_divisors(x);
    divisors_y = get_divisors(y);
    set_intersection(divisors_x.begin(), divisors_x.end(),
                     divisors_y.begin(), divisors_y.end(),
                     std::inserter(intersect, intersect.begin()));
    int max_elem = *intersect.rbegin();
    cout << "The gcd of " << x << " and " << y << " still is " << max_elem << endl;
    return 0;