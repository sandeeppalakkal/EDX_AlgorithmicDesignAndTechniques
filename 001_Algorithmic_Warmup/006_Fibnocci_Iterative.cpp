// Fibnocci number computation using iterative approach
// Sandeep Palakkal
// sandeep.dion@gmail.com#include<iostream>
using namespace std;

unsigned long long additions = 0;

unsigned long long Fibnocci(unsigned n)
{
    unsigned long long fib[n+1];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < n+1; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
        ++additions;
    }
    return fib[n];
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
