#include <iostream>

using namespace std;

template <class T> int binary_search_index(const T *, int, int, const T);

int main()
{
    int arr1[1] = {1};
    int arr2[2] = {6, 9};
    int arr3[9] = {2, 4, 5, 8, 9, 12, 14, 23, 45};
    cout << binary_search_index(arr1, 0, 0, 1) << endl;
    cout << binary_search_index(arr1, 0, 0, 2) << endl;
    cout << binary_search_index(arr2, 0, 1, 6) << endl;
    cout << binary_search_index(arr2, 0, 1, 7) << endl;
    cout << binary_search_index(arr3, 0, 8, 45) << endl;
    cout << binary_search_index(arr3, 0, 8, 44) << endl;
    return 0;
}
template <class T> int binary_search_index(const T *arr, int start, int end, const T target)
{
    if(end < start) return -1;
    int arrow = (end - start) / 2 + start;
    if(arr[arrow] == target) return arrow;
    else if(arr[arrow] > target) return binary_search_index(arr, start, arrow - 1, target);
    else return binary_search_index(arr, arrow + 1, end, target);
}
