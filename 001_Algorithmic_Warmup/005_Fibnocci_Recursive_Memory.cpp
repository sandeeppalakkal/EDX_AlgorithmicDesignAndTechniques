// Fibnocci number computation using recursion with memoization
// Sandeep Palakkal
// sandeep.dion@gmail.com#include <iostream>
#include <iostream>
using namespace std;

#define max_int 1000

int additions = 0;

unsigned long long Fibnocci(unsigned n, unsigned long long *memory)
{
    unsigned long long m;
    if (n < 2)
    {
        m = n;
    }
    else
    {
        m = 0;
        unsigned long long *k = memory+n;
        for(int i = 1; i < 3; ++i)
        {
            m += (*(k-i) == 0)? Fibnocci(n-i,memory) : *(k-i);
            ++additions;
        }
    }
    memory[n] = m;
    return m;
}
int main()
{
    unsigned int n;
    unsigned long long memory[max_int];
    for(int i = 0; i < max_int; ++i)
    {
        memory[max_int] = 0;
    }

    cout << "Enter a positive integer: ";
    cin >> n;

    unsigned long long m = Fibnocci(n,memory);
    cout << "Fibnocci(" << n << ") = " << m << endl;
    cout << "Total computations: " << additions << endl;

    return 0;
}
