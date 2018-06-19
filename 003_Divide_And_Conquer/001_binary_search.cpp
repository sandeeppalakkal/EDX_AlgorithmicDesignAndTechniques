#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

long long *buffer;

long long binary_search(const vector<long long> &array,long long beg, long long end, long long query)
{
    long long index = -1;
    long long size = end - beg;
    cout << "size: " << size << endl;
    if(size == 1)
    {
        if(array[beg] == query) index = beg;
    }
    else
    {
        long long mid = beg+size/2;
        if(array[mid] > query)
        {
            index = binary_search(array,beg,mid,query);
        }
        else
        {
            index = binary_search(array,mid,end,query);
        }
    }
    return index;
}

void merge_sort(vector<long long> &array,long long beg,long long end)
{
    long long size = end - beg;
    //cout << "size " << size << endl;
    if(size < 2)
    {
        return;
    }
    else
    {
        long long mid = beg+size/2;
        //cout << beg << " " << mid << endl;
        merge_sort(array,beg,mid);
        merge_sort(array,mid,end);
        
        //Combine
        long long i = beg, j = mid, k = beg;
        while(i <  mid && j < end)
        {
            if(array[i] < array[j])
            {
                buffer[k++] = array[i++];
            }
            else
            {
                buffer[k++] = array[j++];
            }
        }

        while(i < mid) buffer[k++] = array[i++];
        while(j < end) buffer[k++] = array[j++];

        for(i=beg; i < end; ++i)
        {
            array[i] = buffer[i];
        }
    }
}

int main()
{
    vector<long long> queries, numbers;
    long long num;
    string line;
    ifstream infile("4_1_binary_search.in");
    //Get the queries
    getline(infile, line);
    stringstream ss(line);
    while(ss >> num)
    {
        queries.push_back(num);
    }
    //Get the numbers
    getline(infile, line);
    ss.clear();
    ss.str(line);
    while(ss >> num)
    {
        numbers.push_back(num);
    }

    cout << queries.size() << endl;
    cout << numbers.size() << endl;

    buffer = new long long[numbers.size()];
    merge_sort(numbers, 0, numbers.size());

    ofstream outfile("sorted.out");
    for(int i = 0; i < numbers.size(); ++i)
    {
        outfile << numbers[i] << endl;
    }

    for(long long i = 0; i < queries.size(); ++i)
    {
        num = queries[i];
        long long index = binary_search(numbers,0,numbers.size(),num);
        if(index != -1)
        {
            cout << num << " is found at " << index << endl;
        }
        else
        {
            cout << num << " is not found in the array." << endl;
        }
        cout << "Continue? (Y/N): ";
        char stat;
        cin >> stat;
        if(stat != 'y' && stat != 'Y')
        {
            break;
        }
    }

    infile.close();
    delete[] buffer;
    return 0;
}
