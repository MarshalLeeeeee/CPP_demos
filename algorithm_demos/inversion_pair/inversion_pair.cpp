#include <iostream>
#define MAX 5

using namespace std;

void binary_indexed_tree_add(int *, int, int, int);
int binary_indexed_tree_sum(const int *, int);
int inversion_pair(const int *, int);

int main()
{
    int arr[5] = {4, 5, 1, 2, 3};
    cout << inversion_pair(arr, 5) << endl;
    return 0;
}
int inversion_pair(const int *arr, int len)
{
    int record[MAX] = {0};
    int index;
    int ans = 0;
    for(index = len - 1; index >= 0; index--)
    {
        ans += binary_indexed_tree_sum(record, arr[index] - 1);
        binary_indexed_tree_add(record, arr[index] - 1, 1, MAX);
    }
    return ans;
}
void binary_indexed_tree_add(int *arr, int pos, int value, int len)
{
    int index;
    for(index = pos + 1; index <= len; index += (index & -index))
    {
        arr[index - 1] += value;
    }
}
int binary_indexed_tree_sum(const int *arr, int num)
{
    int index;
    int sum = 0;
    for(index = num; index; index -= (index & -index))
    {
        sum += arr[index - 1];
    }
    return sum;
}
