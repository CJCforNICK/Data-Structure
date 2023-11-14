#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    struct Node *nxt, *prv;
};
vector<Node *> IdxAddress; // vector to store address
Node *head = NULL;
Node *tail = NULL;
void moveTohead(int index)
{
    Node *tmpnd = IdxAddress[index]; // store data to temporary pointer
    // determine where the index is
    if (tmpnd == head)
        return;
    else if (tmpnd == tail)
    {
        (tmpnd->prv)->nxt = NULL; // sec-last be the tail
        tail = tmpnd->prv;
        tmpnd->nxt = head;
        tmpnd->prv = NULL;
        head->prv = tmpnd;
        head = tmpnd;
    }
    else
    {
        (tmpnd->prv)->nxt = tmpnd->nxt;
        (tmpnd->nxt)->prv = tmpnd->prv;
        tmpnd->nxt = head;
        tmpnd->prv = NULL;
        head->prv = tmpnd;
        head = tmpnd;
    }
}
void moveToTail(int index)
{
    Node *tmpnd = IdxAddress[index]; // store data to temporary pointer
    // determine where the index is
    if (tmpnd == tail)
        return;
    else if (tmpnd == head)
    {
        (tmpnd->nxt)->prv = NULL; // sec be the head
        head = (tmpnd->nxt);
        tmpnd->nxt = NULL;
        tmpnd->prv = tail;
        tail->nxt = tmpnd;
        tail = tmpnd;
    }
    else
    {
        (tmpnd->nxt)->prv = tmpnd->prv;
        (tmpnd->prv)->nxt = (tmpnd->nxt);
        tmpnd->nxt = NULL;
        tmpnd->prv = tail;
        tail->nxt = tmpnd;
        tail = tmpnd;
    }
}
void swiTch(int idx, int idx2)
{
    Node *tmpnd = IdxAddress[idx];
    Node *tmpnd2 = IdxAddress[idx2];
    Node *tmptmpnd;
    if (tmpnd == head && tmpnd2 == tail)
    {
        (tmpnd->nxt)->prv = NULL;
        head = tmpnd->nxt;
        (tmpnd2->prv)->nxt = NULL;
        tail = tmpnd2->prv;
        tmpnd->nxt = NULL;
        tmpnd->prv = tail;
        tail->nxt = tmpnd;
        tail = tmpnd;
        tmpnd2->nxt = head;
        tmpnd2->prv = NULL;
        head->prv = tmpnd2;
        head = tmpnd2;
    }
    else if (tmpnd != head && tmpnd2 == tail)
    {
        (tmpnd->nxt)->prv = tmpnd->prv;
        (tmpnd->prv)->nxt = tmpnd->nxt;
        (tmpnd2->prv)->nxt = NULL;
        tail = tmpnd2->prv;
        tmpnd2->nxt = tmpnd->nxt;
        tmpnd2->prv = tmpnd->prv;
        (tmpnd->prv)->nxt = tmpnd2;
        (tmpnd->nxt)->prv = tmpnd2;
        tmpnd->nxt = NULL;
        tmpnd->prv = tail;
        tail->nxt = tmpnd;
        tail = tmpnd;
    }
    else if (tmpnd == head && tmpnd2 != tail)
    {
        (tmpnd->nxt)->prv = NULL;
        head = tmpnd->nxt;
        (tmpnd2->nxt)->prv = tmpnd2->prv;
        (tmpnd2->prv)->nxt = tmpnd2->nxt;
        tmpnd->nxt = tmpnd2->nxt;
        tmpnd->prv = tmpnd->prv;
        (tmpnd2->nxt)->prv = tmpnd;
        (tmpnd2->prv)->nxt = tmpnd;
        tmpnd2->prv = NULL;
        tmpnd2->nxt = head;
        head->prv = tmpnd2;
        head = tmpnd2;
    }
    else
    {
        // first, let tmptmpnd spare for the data from tmpnd2
        tmptmpnd->nxt = tmpnd2->nxt;
        tmptmpnd->prv = tmpnd2->prv;
        (tmpnd2->prv)->nxt = tmptmpnd;
        (tmpnd2->nxt)->prv = tmptmpnd;
        // switch tmpnd to tmpnd2
        tmpnd2->nxt = tmpnd->nxt;
        tmpnd2->prv = tmpnd->prv;
        (tmpnd->prv)->nxt = tmpnd2;
        (tmpnd->nxt)->prv = tmpnd2;
        // switch tmpnd3 to tmpnd
        tmpnd->nxt = tmptmpnd->nxt;
        tmpnd->prv = tmptmpnd->prv;
        (tmptmpnd->prv)->nxt = tmpnd;
        (tmptmpnd->nxt)->prv = tmpnd;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, idx, idx2, i;
        char c;
        cin >> n >> q;
        IdxAddress.push_back(NULL);
        for (i = 0; i < n; i++) // make the list with sequential integer
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
        while (q--)
        {
            cin >> c;
            cin >> idx;   // the input after char
            if (c == 'H') // move to head
            {
                moveTohead(idx);
            }
            else if (c == 'T')
            {
                moveToTail(idx);
            }
            else
            {
                cin >> idx2;
                swiTch(idx, idx2);
            }
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
        // free the IdxAddress
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
}