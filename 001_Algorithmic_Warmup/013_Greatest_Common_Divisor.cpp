#include <iostream>
using namespace std;

typedef unsigned long long ullong;

ullong gcd(ullong m, ullong n)
{
    ullong p, q;
    p = (m > n) ? m : n;
    q = (m > n) ? n : m;
    ullong r = p % q;
    if(r == 0) return q;
    else return gcd(q,r);
}

int main()
{
    ullong m, n;
    cout << "Enter two positive numbers: ";
    cin >> m >> n;
    cout << "GCD is ";
    cout << gcd(m, n) << endl;
    return 0;
}
