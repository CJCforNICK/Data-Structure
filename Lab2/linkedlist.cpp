#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    list<int> linkedlst;
    while (N--)
    {
        string ops;
        cin >> ops;
        if (ops == "IH")
        {
            int i;
            cin >> i;
            linkedlst.push_front(i);
        }
        else if (ops == "IT")
        {
            int i;
            cin >> i;
            linkedlst.push_back(i);
        }
        else if (ops == "RH")
        {

            if (linkedlst.empty())
            {
                continue;
            }
            else
                linkedlst.pop_front();
        }
        else if (ops == "RT")
        {

            if (linkedlst.empty())
            {
                continue;
            }
            else
                linkedlst.pop_back();
        }
        else if (ops == "S")
        {
            int i;
            cin >> i;
            if (linkedlst.empty())
            {
                cout << "E" << endl;
            }
            else if (find(linkedlst.begin(), linkedlst.end(), i) != linkedlst.end())
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
        }
        else
        {
            if (linkedlst.empty())
            {
                cout << "E" << endl;
            }
            else
            {
                for (auto it : linkedlst)
                {
                    cout << it << " ";
                }
            }
            cout << endl;
        }
    }
}