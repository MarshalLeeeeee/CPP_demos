#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    int i = 5;
    int j = 6;

    int *ptr1;
    ptr1 = (int*)malloc(i*sizeof(int));
    for(int index = 0;index<i;index++)
    {
        cout<<(ptr1[index] = index)<< "  ";
    }

    cout<<endl<<endl;;
    free(ptr1);

    int **ptr2;
    ptr2 = (int**)malloc(j*sizeof(int*));
    for(int x = 0;x<j;x++)
    {
        ptr2[x] = (int *)malloc(i*sizeof(int));
    }
    for(int x = 0;x < j;x++)
    {
        for(int y =0;y < i;y++)
        {
            cout << setw(3) << setiosflags(ios::left) << (ptr2[x][y] = x*y) << "  ";
        }
        cout << endl;
    }

    free(ptr2);


    int **ptr3;
    ptr3 = new int *[i];
    int index;
    for(index = 0; index < i; index++)
    {
        ptr3[index] = new int[j];
    }

    int index1, index2;
    for(index1 = 0; index1 < i; index1++)
    {
        for(index2 = 0; index2 < j; index2++)
        {
            ptr3[index1][index2] = index1 * index2;
            cout << ptr3[index1][index2] << '\t';
        }
        cout << endl;
    }
    return 0;
}
