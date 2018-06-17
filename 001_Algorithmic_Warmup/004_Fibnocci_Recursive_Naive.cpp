// Fibnocci number computation using naive approach
// Sandeep Palakkal
// sandeep.dion@gmail.com
#include<iostream>
using namespace std;

unsigned long long additions = 0;

unsigned long long Fibnocci(unsigned n)
{
    unsigned long long m;
    if(n < 2) m = 1;
    else
    {
        m = Fibnocci(n-1) + Fibnocci(n-2);
        ++additions;
    }
    return m;
}

int main()
{
    unsigned int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    unsigned long long m = Fibnocci(n);
    cout << "Fibnocci(" << n << ") = " << m << endl;
    cout << "Total computations: " << additions << endl;

    return 0;
}
