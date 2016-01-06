#include <iostream>

using namespace std;

/**
 * the sign of result is the same with x
 */
int gcd(int x, int y)
{
    if (x % y == 0) return y;
    return gcd(x, x % y);
}

int main()
{
    cout << "gcd(5, 10)=" << gcd(5, 10) << endl;
    cout << "gcd(-5, -10)=" << gcd(-5, -10) << endl;
    cout << "gcd(-5, 10)=" << gcd(-5, 10) << endl;
    cout << "gcd(15, 10)=" << gcd(15, 10) << endl;
    cout << "gcd(5, -10)=" << gcd(5, -10) << endl;

    return 0;
}
