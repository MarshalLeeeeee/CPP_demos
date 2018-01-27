#include <iostream>
using namespace std;
int vertice, edge, in, out, weight, short_route = 0;
struct Edge
{
    int in, out;
    int weight;
    bool operator<(const Edge &other){return weight < other.weight;}
    bool operator>(const Edge &other){return weight > other.weight;}
    Edge &operator=(const Edge &other){in = other.in; out = other.out; weight = other.weight; return *this;}
};
Edge edge_set[100001];
int vertice_set[10001];
int return_root(int x)
{
    int curr_x = x;
    while(vertice_set[curr_x] > 0) curr_x = vertice_set[curr_x];
    return curr_x;
}
bool together(int a, int b)
{
    return return_root(a) == return_root(b);
}
void comb(int x, int y)
{
    int root_x = return_root(x);
    int root_y = return_root(y);
    if(root_x != root_y)
    {
        if(vertice_set[root_x] < vertice_set[root_y])
        {
            vertice_set[root_x] += vertice_set[root_y];
            vertice_set[root_y] = root_x;
        }
        else
        {
            vertice_set[root_y] += vertice_set[root_x];
            vertice_set[root_x] = root_y;
        }
    }
}
void quick_sort(int ibegin, int iend)
{
    if(ibegin >= iend) return ;
    Edge pivot = edge_set[ibegin], tmp;
    int left, right;
    for(left = ibegin; left <= iend; left++)
    {
        if(pivot < edge_set[left]) break;
    }
    for(right = left+1; right <= iend; right++)
    {
        if(pivot > edge_set[right])
        {
            tmp = edge_set[right];
            edge_set[right] = edge_set[left];
            edge_set[left] = tmp;
            left++;
        }
    }
    edge_set[ibegin] = edge_set[left-1];
    edge_set[left-1] = pivot;
    quick_sort(ibegin, left-2);
    quick_sort(left, iend);
}
int main()
{
    cout << "Input the vertice: "; cin >> vertice;
    cout << "Input the edge: "; cin >> edge;
    cout << "Input the edge info: " << endl;
    for(int index = 1; index <= edge; index++)
        cin >> edge_set[index].in >> edge_set[index].out >> edge_set[index].weight;
    quick_sort(1, edge);
    cout << "*******************" << endl;
    for(int index = 1; index <= edge; index++) cout << edge_set[index].in << ' ' << edge_set[index].out << ' ' << edge_set[index].weight << endl;
    for(int index = 1; index <= vertice; index++) vertice_set[index] = -1;
    for(int index = 1, pos = 1; index <= vertice-1; index++)
    {
        while(together(edge_set[pos].in, edge_set[pos].out)) pos++;
        cout << "pos: " << pos << endl;
        short_route += edge_set[pos].weight;
        comb(edge_set[pos].in, edge_set[pos].out);
    }
    cout << "Shortest route is: " << short_route << endl;
    return 0;
}
