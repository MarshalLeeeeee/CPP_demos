
#include <iostream>
using namespace std;

struct reportList
{
    int num;
    reportList *next;
};

reportList *descending_order_linkedlist(reportList *);

int main(void)
{
    reportList *head, *p, *q, *tail;
    int num;

    head = NULL;
    cout << "Input some integers(-1 as the end)" << endl;
    cin >> num;
    while(num != -1)
    {
        p = new reportList;
        p -> num = num;
        p -> next = NULL;
        if(head == NULL)
        {
            head = p;
        }
        else
        {
            tail -> next = p;
        }
        tail = p;
        cin >> num;
    }

    head = descending_order_linkedlist(head);

    cout << "Output in reverse" << endl;
    for(p = head; p != NULL; p = p -> next)
    {
        cout << p -> num << " ";
    }
    cout << endl;

    for(p = head; p != NULL; p = q)
    {
        q = p -> next;
        delete p;
    }

    return 0;
}
reportList *descending_order_linkedlist(reportList *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    reportList *q, *s, *t, *u;
    int max;
    max = head -> num;
    for(q = head -> next, s = head; q != NULL; q = q -> next)
    {
        if(q -> num > max)
        {
            max = q -> num;
            t = s;
        }
        s = q;
    }
    if(max != head -> num)
    {
        u = head;
        head = t -> next;
        t -> next = t -> next -> next;
        head -> next = u;
    }
    head -> next = descending_order_linkedlist(head -> next);
    return head;
}
