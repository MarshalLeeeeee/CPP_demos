#include <iostream>
#define INF 1000000
using namespace std;
int vertice, edge,  in, out, weight, start, route = 0;
struct Node
{
    int index;
    int weight;
    Node *next;
    Node(void): next(NULL){}
};
struct Edge
{
    Node *head, *tail;
    Edge(void){head = new Node; tail = head;}
};
Edge graph[10001];
bool visited[10001];
int lowcost[10001];
void create(int x)
{
    if(route == -1) return ;
    cout << "x: " << x << endl;
    lowcost[x] = 0;
    visited[x] = 1;
    Node *curr = graph[x].head;
    while(curr->next)
    {
        if(!visited[curr->next->index] && curr->next->weight < lowcost[curr->next->index]) lowcost[curr->next->index] = curr->next->weight;
        curr = curr->next;
    }
    int mininum = INF + 1, minindex = 0;
    for(int index = 1;  index <= vertice; index++)
    {
        if(!lowcost[index]) continue;
        if(lowcost[index] < mininum)
        {
            mininum = lowcost[index];
            minindex = index;
        }
    }
    if(mininum == INF) route = -1;
    else
    {
        if(minindex)// only when there exists points that is added newly should we continue
        {
            route += mininum;
            create(minindex);
        }
    }
}
int main()
{
    cout << "Input the vertice number: "; cin >> vertice;
    cout << "Input the edge number: "; cin >> edge;
    cout << "Input the edge info: " << endl;
    for(int index = 1; index <= edge; index++)
    {
        cin >> in >> out >> weight;
        Node *new_node1 = new Node;
        Node *new_node2 = new Node;
        new_node1->weight = weight;
        new_node2->weight = weight;
        new_node1->index = out;
        new_node2->index = in;
        graph[in].tail->next = new_node1;
        graph[in].tail = new_node1;
        graph[out].tail->next = new_node2;
        graph[out].tail = new_node2;
    }
    for(int index = 1; index <= vertice; index++) lowcost[index] = INF;
    create(1);// argument is the start point
    cout << "The shortest route is: " << route << endl;
    return 0;
}
