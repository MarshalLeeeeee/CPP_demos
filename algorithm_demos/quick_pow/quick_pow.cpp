#include <iostream>

using namespace std;

long quick_pow(long, int);

int main()
{
    cout << quick_pow(2, 10) << endl;
    return 0;
}
long quick_pow(long num, int exp)
{
    if(exp == 0) return 1;
    else if(exp == 1) return num;
    else
    {
        long tmp;
        tmp = quick_pow(num, exp / 2);
        if(exp % 2 == 0)
        {
            return tmp * tmp;
        }
        else
        {
            return tmp * tmp * num;
        }
    }
}
