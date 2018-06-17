#include<iostream>
using namespace std;

unsigned Result(unsigned m1, unsigned m2)
{
    unsigned int p =0, q = 1, r, s;
    unsigned int n = (m1 > m2) ? m1 : m2;
    if(n < 2)
    {
        s = m1 + m2;
    }
    else
    {
        s = 0;
    }
    for(int i = 2; i < n + 1; ++i)
    {
        r = (p + q) % 10;
        p = q;
        q = r;
        if(i == m1 || i == m2)
        {
            s = (s + r) % 10;
        }
    }
    if (m1 == m2) s = 2*s % 10;
    return s;
}

int main()
{
    unsigned int m, n;
    cout << "Enter two positive numbers: ";
    cin >> m >> n;

    cout << "Last digit of sum of Fibnocci numbers of " << m << " and " << n;
    cout << " is " << Result(m,n) << endl;
    return 0;
}
