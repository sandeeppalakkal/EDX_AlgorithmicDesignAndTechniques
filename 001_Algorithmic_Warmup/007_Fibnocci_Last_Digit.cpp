//Last digit of Fibnocci(n)
//Sandeep Palakkal
//sandeep.dion@gmail.com
#include<iostream>
using namespace std;

int main()
{
    unsigned int n, p = 0, q = 1, r = 0;
    cout << "Enter a positive integer: ";
    cin >> n;
    if(n < 2) r = n;
    for(int i = 2; i < n+1; ++i)
    {
        r = (p + q) % 10;
        p = q;
        q = r;
    }
    cout << "Last digit of Fibnocci(" << n << ") is " << r << endl;
    return 0;
}
