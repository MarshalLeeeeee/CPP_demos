#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        cout << "No valid arguments" << endl;
        return 1;
    }

    double data[argc-1];
    int index;
    double sum = 0;
    for(index = 0; index < argc - 1; index++)
    {
        data[index] = atof(argv[index + 1]);
        sum += data[index];
    }

    double average;
    average = sum / (argc - 1);

    double var = 0;
    double sample_variance;
    for(index = 0; index < argc - 1; index++)
    {
        var += (data[index] - average) * (data[index] - average);
    }
    sample_variance = var / (argc - 2);
    cout << "sample average: " << average << endl;
    cout << "sample variance: " << sample_variance << endl;
    cout << "sample standard deviation: " << sqrt(sample_variance) << endl;
    return 0;
}
