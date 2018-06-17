#include <iostream>
#include <vector>
#include <climits>

using std::vector;
using std::cin;
using std::cout;

void FindMaxTwo(const vector<unsigned long long>& numbers, vector<unsigned long long> &max)
{
    max[0] = 0;
    max[1] = 0;
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(numbers[i] > max[0])
        {
            max[1] = max[0];
            max[0] = numbers[i];
        }
        else if(numbers[i] > max[1])
        {
            max[1] = numbers[i];
        }
    }
}

unsigned long long MaxPairwiseProduct(const vector<unsigned long long>& numbers) 
{
    vector<unsigned long long> a(2);
    FindMaxTwo(numbers,a);
    return a[0] * a[1];
}

int main() {
    //cout << LLONG_MAX;
    int n;
    cin >> n;
    vector<unsigned long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    unsigned long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
