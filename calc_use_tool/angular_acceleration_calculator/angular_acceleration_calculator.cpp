#include <iostream>
#include <fstream>
#define PI 3.1415926535897932384626
#define NAME_MAX 256

using namespace std;

void dashbar(void);
double average(double *, int);

int main()
{
    char in_file_name[NAME_MAX];
    char out_file_name[NAME_MAX];
    cout << "Input the name of the file for read: ";
    cin.getline(in_file_name, NAME_MAX);
    dashbar();
    cout << "Input the name of the file for save: ";
    cin.getline(out_file_name, NAME_MAX);
    dashbar();

    ifstream in_file(in_file_name);
    ofstream out_file(out_file_name);

    double beta[4];
    double average_beta;
    double time[8];
    int index;
    for(index = 0; index < 8; index++)
    {
        in_file >> time[index];
    }
    in_file.close();

    for(index = 0; index < 4; index++)
    {
        beta[index] = 2 * PI *((index + 1) * time[7 - index] - (8 - index) * time[index]) / (time[index] * time[index] * time[7 - index] - time[7 - index] * time[7 - index] * time[index]);
        out_file << beta[index] << endl;
    }
    average_beta = average(beta);
    out_file << average_beta << endl;

    out_file.close();
    return 0;
}
void dashbar(void)
{
    cout << "___________________________________________" << endl;
}
double average(double *ptr, int n)
{
    int index;
    double sum = 0;
    for(index = 0; index < n; index++)
    {
        sum += ptr[index];
    }
    return sum/n;
}
