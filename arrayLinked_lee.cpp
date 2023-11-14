#include<iostream>
#include<vector>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next,*prev;
}Node;

vector<Node *>addrTable;
Node *Head = NULL, *Tail = NULL;


void printArr(){
    Node *ptr = Head;
    while(1){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
        if(ptr == Tail){
            cout << ptr -> data;
            break;
        }
    }
    cout << endl;
    return;
}

void insertHead(int num){
    Node *temp = addrTable[num];
    // remove the node
    if(temp == Head) return;
    else if (temp == Tail){
        (temp -> prev) -> next = NULL;
        Tail = temp -> prev;
    }else{
        (temp -> prev) -> next = temp -> next;
        (temp -> next) -> prev = temp -> prev;
    }
    
    // insert at begin
    temp -> prev = NULL;
    temp -> next = Head;
    Head -> prev = temp;
    Head = temp;
    return;
}

void insertTail(int num){
    Node *temp = addrTable[num];
    // remove the node
    if(temp == Tail) return;
    else if(temp == Head){
        (temp -> next) -> prev = NULL;
        Head = temp -> next;
    }else{
        (temp -> prev) -> next = temp -> next;
        (temp -> next) -> prev = temp -> prev;
    }
    // insert at end
    temp -> next = NULL;
    temp -> prev = Tail;
    Tail -> next = temp;
    Tail = temp;
    return;
}

void buildArray(int n){
    addrTable.push_back(NULL);
    for(int i = 0; i < n; i++){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode -> data = i + 1;
        if(Head == NULL){           // empty array
            Head = newNode;
            newNode -> prev = NULL;
            newNode -> next = NULL;
            Tail = newNode;
            // cout << " new round" << endl;
        }else{
            newNode -> prev = Tail;
            Tail -> next = newNode;
            newNode -> next = NULL;
        }
        addrTable.push_back(newNode);   // store index i (from 1 to n) in a table
        Tail = newNode;
    }
    return;
}

void freeArr(){
    Node *ptr = Head,*ptr1 = NULL;
    while(1){
        ptr1 = ptr -> next;
        free(ptr);
        ptr = ptr1;
        if(ptr == Tail){
            free(ptr);
            Head = NULL;
            Tail = NULL;
            addrTable.clear();
            break;
        }
    }
    return;

}



int main(){
    int t = 0;
    cin >> t;   // the number of testcases
    for(int i = 0; i < t; i++){
        int n = 0, q = 0;
        cin >> n >> q;
        buildArray(n);
        // cout << "Initial array: ";
        // printArr();
        for(int a = 0; a < q; a++){
            char cmd;
            int x = 0;
            cin >> cmd >> x;
            if(cmd == 'H') insertHead(x);
            else if (cmd == 'T') insertTail(x);
            // printArr();
        }   // end of round i commands
        printArr();
        freeArr();
    }   // end of all testcases
    return 0;
}

