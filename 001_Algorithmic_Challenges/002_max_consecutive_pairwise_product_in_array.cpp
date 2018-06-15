#include<iostream>
using namespace std;

long long int MaxConsecutivePairwiseProduct(int *array, int n)
{
    long long int max_prod = array[0] * array[1];
    cout << max_prod;
    for(int i=2; i < n; ++i)
    {
        long long int new_prod = array[i] * array[i-1];
        max_prod = (max_prod > new_prod) ? max_prod : new_prod;
    }
    return max_prod;
}


int main()
{
    int n;
    cout << "Enter array size (>=2): ";
    cin >> n;
    int array[n];
    cout << "Enter array elements: ";
    for(int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    long long int result = MaxConsecutivePairwiseProduct(array,n);
    cout << "Result: ";
    cout << result;
    cout << endl;

    return 0;
}
