#include <iostream>

using namespace std;

int quick_select(int *, int, int, int);
int quick_select_index(int *, int *, int, int, int);

int main()
{
    int arr[10] = {3, 7, 4, 5, 1, 9, 10, 2, 6, 8};
    int arr2[10] = {3, 7, 4, 5, 1, 9, 10, 2, 6, 8};
    int order[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << quick_select(arr, 0, 9, 7) << endl;
    cout << quick_select_index(arr2, order, 0, 9, 7) << endl;
    return 0;
}
int quick_select(int *arr, int start, int end, int k)
{
    //return the kth small
    if(k > end - start + 1) return -1;
    if(start == end) return arr[start];
    int pivot = arr[start];
    int tmp;
    int i, j;
    for(i = start + 1; i <= end; i++)
    {
        if(arr[i] < pivot) continue;
        else break;
    }
    for(j = i + 1; j <= end; j++)
    {
        if(arr[j] > pivot) continue;
        else
        {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
        }
    }
    arr[start] = arr[i - 1];
    arr[i - 1] = pivot;
    if(k == i - start) return arr[i - 1];
    else if(k > i - start) return quick_select(arr, i, end, k - (i - start));
    else return quick_select(arr, start, i - 2, k);
}
int quick_select_index(int *arr, int *order, int start, int end, int k)
{
    if(k > end - start + 1) return -1;
    if(start == end) return order[start];
    int pivot = arr[start];
    int tmp;
    int i, j;
    for(i = start + 1; i <= end; i++)
    {
        if(arr[i] < pivot) continue;
        else break;
    }
    for(j = i + 1; j <= end; j++)
    {
        if(arr[j] > pivot) continue;
        else
        {
            tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            tmp = order[j];
            order[j] = order[i];
            order[i] = tmp;
            i++;
        }
    }
    arr[start] = arr[i - 1];
    arr[i - 1] = pivot;
    tmp = order[i - 1];
    order[i - 1] = order[start];
    order[start] = tmp;
    int index;
    if(k == i - start) return order[i - 1];
    else if(k > i - start) return quick_select_index(arr, order, i, end, k - (i - start));
    else return quick_select_index(arr, order, start, i - 2, k);
}
