#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include <ctime>
using namespace std;

void display_array(const vector<long long> &array)
{
    for(long long i = 0; i < array.size(); ++i)
    {
        cout << i <<":"<< array[i] << " ";
    }
    cout << endl;
}

void swap(vector<long long> &array,long long i, long long j)
{
    long long temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void quick_sort(vector<long long> &array,long long beg,long long end)
{
    if(end - beg == 2)
    {
        if(array[beg] > array[end - 1]) swap(array,beg,end-1);
    }
    else if(end - beg > 2)
    {
        long long pivot = array[end - 1];
        long long i = beg, j = end - 2;
        while(i < j)
        {
            while(array[i] <= pivot && i <= end-2) ++i;
            while(array[j] > pivot && j >= beg) --j;
            if(i < j) swap(array,i,j);
        }
        swap(array,i,end-1);
        quick_sort(array,beg,i);
        quick_sort(array,i,end);
    }
}


int main()
{
    vector<long long> queries, numbers;// {1,5,2,4,9,7,0,6};
    long long num;
    string line, in_file = "4_1_binary_search.in";
    ifstream infile("4_1_binary_search.in");

    getline(infile,line);
    stringstream ss(line);
    while(ss >> num) queries.push_back(num);
    getline(infile,line);
    ss.clear();
    ss.str(line);
    while(ss >> num) 
    {
        numbers.push_back(num);
    }

    clock_t t0 = clock();
    quick_sort(numbers,0,numbers.size());
    t0 = clock() - t0;
    cout << "Time taken by quick sort: " << 
        float(t0)/CLOCKS_PER_SEC * 1000 << " ms.\n";


    ofstream outfile("sorted_2.out");
    for(long long i = 0; i < numbers.size(); ++i)
    {
        outfile << numbers[i] << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
