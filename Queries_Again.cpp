#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


int sz = 0;

void insert_at_head(Node *&head, Node *&tail, int val)
{
    sz++;
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    sz++;
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void insert_at_any_pos(Node *head, int idx, int val)
{
    sz++;
    Node *newnode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next->prev = newnode;
    tmp->next = newnode;
    newnode->prev = tmp;
}
void print_forward(Node *head)
{
    cout << "L -> ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backward(Node *tail)
{
    cout << "R -> ";
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;

    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        if (idx < 0 || idx > sz)
        {
            cout << "Invalid" << endl;
        }

        else
        {
            if (idx == 0)
            {//insert at head
                insert_at_head(head, tail, val);
            }
            else if (idx == sz)
            { // insert at tail
                insert_at_tail(head, tail, val);
            }
            else
            { // insert at any positon
                insert_at_any_pos(head, idx, val);
            }
            print_forward(head);
            print_backward(tail);
        }
    }
    return 0;
}    

// Input
// 5
// 1 10
// 0 10
// 1 20
// 3 30
// 2 30
// // output
// Invalid
// L -> 10
// R -> 10
// L -> 10 20
// R -> 20 10
// Invalid
// L -> 10 20 30
// R -> 30 20 10
