#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    double data[argc - 1];
    double calc[(argc - 1) / 2];
    double sum;
    int index;
    for(index = 0; index < argc - 1; index++)
    {
        data[index] = atof(argv[index + 1]);
    }
    for(index = 0, sum = 0; index < (argc - 1) / 2; index++)
    {
        calc[index] = (-data[index] + data[index + (argc - 1) / 2]);
        sum += calc[index];
    }
    cout << sum / ((argc - 1) / 2) << endl;
    return 0;
}
