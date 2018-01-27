#include <iostream>

using namespace std;

int main()
{
    cout << "This is a progrom to calculate the GCD and LCM of two integers" << endl;

    int a, b, c, m, n;
    cout << "Input two integers" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    m = a; n = b;

    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    cout << "The GCD of a and b is: " << a << endl;
    cout << "The LCM of a and b is: " << m * n / a << endl;
    return 0;
}
