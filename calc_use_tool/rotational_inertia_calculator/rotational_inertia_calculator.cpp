#include <iostream>
#include <iomanip>
#include <fstream>
#define G 9.794
#define PI 3.1415926535897932384626
#define NAME_MAX 256

using namespace std;

void dashbar(void);

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

    double mass, radius;
    in_file >> mass >> radius;

    double time[18][8];
    int i, j;
    for(i = 0; i < 18; i++)
    {
        for(j = 0;  j < 8 ; j++)
        {
            in_file >> time[i][j];
        }
    }

    double beta[18][5];
    double sum;
    for(i = 0; i < 18; i++)
    {
        out_file << i+1 << ": ";
        for(j = 0, sum = 0; j < 4; j++)
        {
            beta[i][j] = 2 * PI *((j + 1) * time[i][j + 4] - (j + 5) * time[i][j]) / (time[i][j] * time[i][j] * time[i][j + 4] - time[i][j + 4] * time[i][j + 4] * time[i][j]);
            sum += beta[i][j];
            out_file << setw(10) << fixed << setiosflags(ios::left) << beta[i][j];
        }
        beta[i][j] = sum / 4;
        out_file << setprecision(6) << fixed << beta[i][j] << "       " << endl;
    }
    out_file << endl << endl;

    double rotational_inertia[9];
    for(i = 0; i < 9; i++)
    {
        rotational_inertia[i] = mass * radius * (G - radius * beta[2 * i + 1][4]) / (beta[2 * i + 1][4] - beta[2 * i][4]);
        out_file << i+1 << ": " << rotational_inertia[i] << endl;
    }
    out_file << endl << endl;
    return 0;
}
void dashbar(void)
{
    cout << "___________________________________________" << endl;
}
