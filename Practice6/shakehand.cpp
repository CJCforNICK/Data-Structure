#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
vector<set<int>> adj;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    adj.resize(n + 1);
    cin >> q;
    int op, x, y;
    while (q--)
    {
        cin >> op >> x >> y;
        bool check = false;
        if (op == 1)
        {
            if (x == y)
            {
                adj[x].emplace(y);
            }
            else
            {
                adj[x].emplace(y);
                adj[y].emplace(x);
            }
        }
        else
        {
            if (adj[x].find(y) != adj[x].end())
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}