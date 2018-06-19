#include <iostream>
using namespace std;

typedef unsigned long long ullong;

ullong Fibnocci_Modulo(ullong m, ullong n)
{
    
}

int main()
{
    ullong m, n;
    cout << "Enter two positive numbers, the second smaller than first: ";
    cin >> m >> n;
    cout << "Fibnocci(" << m << ") modulo " << n << " is ";
    cout << Fibnocci_Modulo(m,n) << endl;
    return 0;
}
