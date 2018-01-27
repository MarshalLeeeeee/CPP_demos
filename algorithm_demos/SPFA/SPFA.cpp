#include <iostream>
#define INF 1000000
using namespace std;
int edge, vertice, start;
int q[100001];
int cost[10001];
bool in_queue[10001];
int q_head = 0;
int q_tail = -1;
struct Edge
{
    int out;
    int weight;
    Edge *next;
    Edge(void):next(NULL){}
};
struct Vertice
{
    Edge *head, *tail;
    Vertice(void){head = new Edge; tail = head;}
};
Vertice graph[10001];
int main()
{
    cout << "Input the vertice number: "; cin >> vertice;
    cout << "Input the edge number: "; cin >> edge;
    cout << "Input the start point: "; cin >> start;
    cout << "Input the edge: " << endl;
    for(int index = 1, in; index <= edge; index++)
    {
        Edge *new_node = new Edge;
        cin >> in >> new_node->out >> new_node->weight;
        graph[in].tail->next = new_node;
        graph[in].tail = new_node;
    }
    for(int index = 1; index <= vertice; index++) {cost[index] = INF; in_queue[index] = 0;}
    q[++q_tail] = start; cost[start] = 0; in_queue[start] = 1;
    while(q_head <= q_tail)
    {
        int head = q_head;
        int tail = q_tail;
        for(; head <= tail; head++)
        {
            Edge *curr = graph[q[head]].head;
            while(curr->next)
            {
                if(cost[q[head]] + curr->next->weight < cost[curr->next->out])
                {
                    cost[curr->next->out] = cost[q[head]] + curr->next->weight;
                    if(!in_queue[curr->next->out]) { q[++q_tail] = curr->next->out; in_queue[curr->next->out] = 1;}
                }
                curr = curr->next;
            }
            in_queue[q[q_head++]] = 0;
        }
    }
    for(int index = 1; index <= vertice; index++) cout << cost[index] << endl;
    return 0;
}
