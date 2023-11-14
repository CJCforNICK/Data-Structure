#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *nxt, *prv;
};
vector<Node *> IdxAddress;
Node *head = NULL, *tail = NULL;
int main()
{
    IdxAddress.push_back(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node *newnd = (Node *)malloc(sizeof(Node));
        newnd->data = i + 1;
        if (head == NULL)
        { // empty array
            head = newnd;
            tail = newnd;
            newnd->nxt = NULL; // newnode is head and tail itself
            newnd->prv = NULL;
        }
        else
        {
            newnd->nxt = NULL;
            newnd->prv = tail;
            tail->nxt = newnd;
        } // done setting newnode
        IdxAddress.push_back(newnd);
        tail = newnd;
    }
    Node *tmp = head; // print array
    while (1)
    {
        cout << tmp->data << " ";
        tmp = tmp->nxt;
        if (tmp == NULL)
            break;
    }
    cout << '\n';
    Node *ptr = head, *ptr1;
    while (1)
    {
        ptr1 = ptr->nxt;
        free(ptr);
        ptr = ptr1;
        if (ptr == NULL)
        {
            head = NULL;
            tail = NULL;
            IdxAddress.clear();
            break;
        }
    }
}