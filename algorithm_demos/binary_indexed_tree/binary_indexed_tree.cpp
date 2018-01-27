#include <iostream>
#define LEN 10

using namespace std;

void binary_indexed_tree_add(int *, int, int, int);
int binary_indexed_tree_sum(const int *, int);
void print_arr(const int *, int);

int main()
{
    int arr[LEN] = {0}; print_arr(arr, LEN);
    int index;
    for(index = 0; index < LEN; index++)
    {
        binary_indexed_tree_add(arr, index, index + 1, LEN);
        print_arr(arr, LEN);
    }
    for(index = 1; index <= LEN; index++)
    {
        cout << binary_indexed_tree_sum(arr, index) << endl;
    }
    return 0;
}
void print_arr(const int *arr, int len)
{
    int index;
    for(index = 0; index < len; index++)
    {
        cout << arr[index] << ' ';
    }
    cout << endl;
}
void binary_indexed_tree_add(int *arr, int pos, int value, int len)
{
    //here the pos represents the index of the data, which starts from 0 and ends at n-1
    int index;
    for(index = pos + 1; index <= len; index += (index & -index))
    {
        //index & -index return the lowbit of index
        //index += lowbit of index return the sup of index
        arr[index - 1] += value;
    }
}
int binary_indexed_tree_sum(const int *arr, int num)
{
    //here the num represents the number of the elements
    //for instance, if num = 10, means we want the sum of the first 10 numbers in the arr
    int index;
    int sum = 0;
    for(index = num; index; index -= (index & -index))
    {
        //index & -index return the lowbit of index
        //index -= lowbit of index return the previuos peer of index, which is in the same class with index
        sum += arr[index - 1];
    }
    return sum;
}
