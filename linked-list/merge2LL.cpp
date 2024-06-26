#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
// ---------- Link list ---------------//

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}
void insertInMiddle(node *&root, int afterNode, int data)
{
    if (root == NULL)
    {
        return;
    }
    node *temp = new node(data);
    node *head = root;
    while (head != nullptr and (head->data != afterNode))
    {
        head = head->next;
    }
    if (head == nullptr)
    {
        cout << " Not found middle node";
        return;
    }
    temp->next = head->next;
    head->next = temp;
}
void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "--->";
        head = head->next;
    }
    cout << endl;
}
node *reverseLL(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *s = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return s;
}

void iterativeRevLL(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = NULL, *current = head, *prev = NULL;
    while (head->next != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    temp = prev;
    return;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c = NULL;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printLL(head);

    node *head2 = NULL;
    insertAtHead(head2, 10);
    insertAtHead(head2, 9);
    insertAtHead(head2, 8);
    insertAtHead(head2, 7);
    insertAtHead(head2, 6);
    printLL(head2);
    return 0;
}
