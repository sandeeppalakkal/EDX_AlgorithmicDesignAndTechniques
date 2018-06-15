#include<iostream>
using namespace std;

int MaxPairwiseProduct(int *array, int n)
{
    int max_prod = array[0] * array[1];
    for(int i=2; i < n; ++i)
    {
        int new_prod = array[i] * array[i-1];
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
    int result = MaxPairwiseProduct(array,n);
    cout << "Result: ";
    cout << result;
    cout << endl;

    return 0;
}
