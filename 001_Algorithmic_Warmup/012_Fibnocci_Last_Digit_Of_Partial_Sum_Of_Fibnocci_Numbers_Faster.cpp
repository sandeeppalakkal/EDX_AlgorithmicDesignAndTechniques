#include<iostream>
using namespace std;

unsigned Result_(unsigned n)
{
    unsigned int p =0, q = 1, r, s;
    if(n < 0)
    {
        s = 0;
    }
    else if(n < 2)
    {
        s = n;
    }
    else
    {
        s = 1;
    }
    for(int i = 2; i < n + 1; ++i)
    {
        r = (p + q) % 10;
        p = q;
        q = r;
        s = (s + r) % 10;
    }
    return s;
}
unsigned Result(unsigned long long m, unsigned long long n)
{
    unsigned long long q1 = (m - 1) / 60, q2 = n/60;
    int r1 = (m > 0) ? 60 + (m - 1) % 60 : 0, r2 = n % 60, s = 0;
    if( m == 0 && n == 0 )
    {
        return 0;
    }
    s = (s + Result_(r2) + 60 - Result_(r1)) % 10;
    return s;
}


int main()
{
    unsigned long long m, n;
    cout << "Enter two positive numbers, the second larger than the first: ";
    cin >> m >> n;

    if ( m > n) return 1;

    cout << "Last digit of partial sum of Fibnocci numbers from ";
    cout << m << " to " << n << " is " << Result(m,n) << endl;
    return 0;
}
