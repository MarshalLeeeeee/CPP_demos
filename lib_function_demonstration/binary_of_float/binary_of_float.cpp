#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float arr[32];
    int xx = 0x7fffffff;
    cout << xx << endl;
    float x = xx;
    float y = 0.5;
    for(int index = 0; index < 32; index++)
        arr[index] = 1 << index;
    for(int index = 0; index < 32; index++)
    {
        cout << dec << setw(2) << index << ": " <<
        setw(20) << (int)arr[index] << ' ' <<
        setw(20) << hex << *(int *)(&arr[index]) << endl;
    }
    cout << dec <<  "x : " << setw(20) << x << ' ' << hex << setw(20) << *(int *)(&x) << endl;
    cout << dec <<  "y : " << setw(20) << y << ' ' << hex << setw(20) << *(int *)(&y) << endl;
    cout << dec << xx + arr[31] << endl;
    return 0;
}
