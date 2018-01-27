#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char str[] = "1234567890";
    cout << setw(4) << str << endl;

    double pi = 3.1415926535897932384626;
    cout << setw(4) << pi << endl;
    cout << setw(10) << pi << endl;
    cout << setprecision(8) << pi << endl;
    cout << fixed << setprecision(8) << pi << endl;
    cout << setw(20) << fixed << setprecision(8) << pi << endl;
    cout << setfill('0') << setw(20) << fixed << setprecision(8) << pi << endl;
    cout << setiosflags(ios::left) << setfill('0') << setw(20) << fixed << setprecision(8) << pi << endl;
    cout << setiosflags(ios::showpos) << setfill('0') << setw(20) << fixed << setprecision(8) << pi << endl;
    cout << setiosflags(ios::scientific) << pi << endl;

    int p = 30;
    cout << oct << p << endl;
    cout << hex << p << endl;
    //cout << setiosflags(ios::)
    return 0;
}
