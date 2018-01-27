#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T> void quick_sort(T *, long, long);

int main()
{
    ofstream os("save.txt");
    long n;
    long long m;
    cin >> n >> m;
    long long *ptr;
    ptr = new long long[n];
    long index;
    srand((unsigned int)time(NULL));
    for(index = 0; index < n; index++)
    {
        ptr[index] = rand() % m;
    }
    //quick_sort(ptr, 0, n-1);
    for(index = 0; index < n; index++)
    {
        os << ptr[index] + 1 << endl;
    }
    return 0;
}
template <class T> void quick_sort(T *arr, long start, long end)
{
    if(start >= end) return ;
    T pivot = arr[start];
    T tmp;
    long i, j;
    for(i = start + 1; i <= end; i++)
    {
        if(arr[i] < pivot) continue;
        break;
    }
    if(i <= end)
    {
        for(j = i + 1; j <= end; j++)
        {
            if(arr[j] < pivot)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                i++;
            }
            else
            {
                continue;
            }
        }
    }
    arr[start] = arr[i - 1];
    arr[i - 1] = pivot;
    quick_sort(arr, start, i - 2);
    quick_sort(arr, i, end);
}
