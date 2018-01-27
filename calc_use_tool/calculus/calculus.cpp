#include <iostream>
#include <cmath>
#define N 6.02
#define K 1.38
using namespace std;

double f(double x)
{
    return x * x * x / (exp(x) - 1);
}

int main()
{
    double T, Td;
    cout << "Input T and Td" << endl;
    cin >> T >> Td;
    double pro = 9 * N * K * pow(T, 4) / pow(Td, 3);
    double sup = Td / T;
    double step = sup / 10000;
    double integral = 0;
    int index;
    for(index = 0; index < 10000; index++)
    {
        integral += f(index * step + step) * step;
    }
    cout << "ans is " << integral * pro << endl;
    return 0;
}
