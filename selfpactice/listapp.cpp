#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> lst;
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        int x;
        cin >> x;
        lst.push_back(x);
    }
    for (auto &x : lst)
    {
        cout << x << ' ';
    }
    cout << '\n';
    lst.sort();
    for (auto &x : lst)
    {
        cout << x << ' ';
    }
}