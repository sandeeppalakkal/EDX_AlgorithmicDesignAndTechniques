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
