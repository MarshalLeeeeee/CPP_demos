#include <iostream>

using namespace std;

template <class T> void insert_sort(T *, int);
template <class T> void print_arr(const T *, int);

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {5, 4, 3, 2, 1};
    int arr3[7] = {2, 5, 3, 4, 1, 7, 6};
    int arr4[1] = {0};
    int arr5[2] = {2, 1};
    insert_sort(arr1, 5);
    insert_sort(arr2, 5);
    insert_sort(arr3, 7);
    insert_sort(arr4, 1);
    insert_sort(arr5, 2);
    print_arr(arr1, 5);
    print_arr(arr2, 5);
    print_arr(arr3, 7);
    print_arr(arr4, 1);
    print_arr(arr5, 2);
    return 0;
}
template <class T> void insert_sort(T *arr, int len)
{
    int index1, index2;
    T tmp;
    for(index1 = 0; index1 < len; index1++)
    {
        for(index2 = index1 - 1; index2 >= 0; index2--)
        {
            if(arr[index2] > arr[index2 + 1])
            {
                tmp = arr[index2];
                arr[index2] = arr[index2 + 1];
                arr[index2 + 1] = tmp;
            }
            else break;
        }
    }
}
template <class T> void print_arr(const T *arr, int len)
{
    int index;
    for(index = 0; index < len; index++)
    {
        cout << arr[index] << ' ';
    }
    cout << endl;
}
