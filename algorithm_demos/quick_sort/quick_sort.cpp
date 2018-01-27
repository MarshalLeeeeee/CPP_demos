#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T> void quick_sort(T *, int, int);
template <class T> void random_quick_sort(T *, int, int);
template <class T> void print_arr(T *, int);

int main()
{
    int arr1[1] = {1};
    int arr2[2] = {1, 2};
    int arr3[2] = {2, 1};
    int arr4[3] = {6, 10, 3};
    int arr5[7] = {6, 10, 3, 2, 7, 1, 8};
    random_quick_sort(arr1, 0, 0);
    random_quick_sort(arr2, 0, 1);
    random_quick_sort(arr3, 0, 1);
    random_quick_sort(arr4, 0, 2);
    random_quick_sort(arr5, 0, 6);
    print_arr(arr1, 1);
    print_arr(arr2, 2);
    print_arr(arr3, 2);
    print_arr(arr4, 3);
    print_arr(arr5, 7);
    return 0;
}
template <class T> void quick_sort(T *arr, int start, int end)
{
    if(start >= end) return ;
    T pivot = arr[start];
    T tmp;
    int i, j;
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
template <class T> void random_quick_sort(T *arr, int start, int end)
{
    if(start >= end) return ;
    srand((unsigned int)time(NULL));
    int rand_index = rand() % (end - start + 1) + start;
    T pivot = arr[rand_index];
    T tmp;
    arr[rand_index] = arr[start];
    arr[start] = pivot;
    int i, j;
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
    random_quick_sort(arr, start, i - 2);
    random_quick_sort(arr, i, end);
}
template <class T> void print_arr(T *arr, int len)
{
    int index;
    for(index = 0; index < len; index++)
    {
        cout << arr[index] << ' ';
    }
    cout << endl;
}
