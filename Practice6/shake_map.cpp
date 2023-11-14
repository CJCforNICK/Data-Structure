#include <iostream>
#include <set>
#include <map>
using namespace std;
map<int, set<int>> adj;

int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    int op, x, y;
    while (q--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            adj[x].insert(y);
            adj[y].insert(x);
        }
        else
        {
            if (adj[x].count(y) || adj[y].count(x))
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }

    return 0;
}