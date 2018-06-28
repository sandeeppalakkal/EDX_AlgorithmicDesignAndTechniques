#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
using namespace std;

long long *buffer;

void merge_sort(vector<long long> &array,long long beg,long long end)
{
    long long size = end - beg;
    if(size < 2)
    {
        return;
    }
    else
    {
        long long mid = beg+size/2;
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
    int num;
    string line, in_file = "4_1_binary_search.in";
    ifstream infile("4_1_binary_search.in"); 

    getline(infile,line);
    stringstream ss(line);
    while(ss >> num) queries.push_back(num);
    getline(infile,line);
    ss.clear();
    ss.str(line);
    while(ss >> num) numbers.push_back(num);

    buffer = new long long[numbers.size()];
    clock_t t0 = clock();
    merge_sort(numbers,0,numbers.size());
    t0 = clock() - t0;
    cout << "Time taken by merge sort: " << 
        float(t0)/CLOCKS_PER_SEC * 1000 << " ms.\n";

    ofstream outfile("sorted_1.out");
    for(int i = 0; i < numbers.size(); ++i)
    {
        outfile << numbers[i] << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
