#include <iostream>
#define INF 1000000
using namespace std;
int vertice, edge;
int route[1001][1001];

int main()
{
    cout << "Input the vertice number: " ; cin >> vertice;
    cout << "Input the edge number: "; cin >> edge;
    cout << "Input the edge info: " << endl;
    int in, out, weight;
    for(int index1 = 1; index1<= vertice; index1++)
        for(int index2 = 1; index2 <= vertice; index2++)
            route[index1][index2] = INF;
    for(int index1 = 1; index1 <= vertice; index1++) route[index1][index1] = 0;
    for(int index = 1; index <= edge; index++)
    {
        cin >> in >> out >> weight;
        route[in][out] = weight;
    }
    for(int index1 = 1; index1 <= vertice; index1++)
    {
        for(int index2 = 1; index2 <= vertice; index2++)
        {
            for(int index3 = 1; index3 <= vertice; index3++)
            {
                // exam the route cost from index2 to index3
                if(index2 != index3 && index2 != index1 && index3 != index1)
                {
                    if(route[index2][index1] + route[index1][index3] < route[index2][index3])
                        route[index2][index3] = route[index2][index1] + route[index1][index3];
                }
            }
        }
    }
    cout << "The final route: " << endl;
    for(int index1 = 1; index1 <= vertice; index1++)
    {
        for(int index2 = 1; index2 <= vertice; index2++)
        {
            cout << route[index1][index2] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
