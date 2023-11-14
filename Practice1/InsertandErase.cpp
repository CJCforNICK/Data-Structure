#include <iostream>
#include <list>
using namespace std;
struct Node
{
    int data;
    Node *nxt;
};
class linkedlist
{
private:
    Node *head, *tail;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void addnode(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->nxt = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->nxt = temp;
            tail = tail->nxt;
        }
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->nxt;
    }
}
int main()
{
    linkedlist lst;
    lst.addnode(1);
    lst.addnode(2);
    printList();
}