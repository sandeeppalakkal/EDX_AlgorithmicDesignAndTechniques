#include<iostream>
using namespace std;

unsigned Result(unsigned n)
{
    unsigned int p =0, q = 1, r, s;
    if(n < 2)
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

int main()
{
    unsigned int m;
    cout << "Enter a positive numbers: ";
    cin >> m;

    cout << "Last digit of sum of Fibnocci numbers of " << m;
    cout << " is " << Result(m) << endl;
    return 0;
}
