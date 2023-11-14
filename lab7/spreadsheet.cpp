#include <iostream>
#include <vector>
#define ll long long
using namespace std;
// unvisited:0, visited:-1,finished:1
vector<vector<int>> adj;
vector<int> temp;
vector<int> y;
vector<int> vis;
ll f(int u)
{
    // case 1: 1->2->3->1 no solution
    if (vis[u] == -1)
        return -1; // return -1 means no solution
    // case 2: u has not been visited, cal u
    if (vis[u] == 0)
    {
        vis[u] = -1;
        temp[u] = y[u]; // first plus value y
        for (auto &x : adj[u])
        {
            if (f(x) == -1)
            {
                return -1;
            }
            else
            {
                temp[u] += f(x);
            }
        }
        vis[u] = 1;
    }
    return temp[u];
}
int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    temp.resize(n + 1, 0);
    y.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        char oper;
        int u, v;
        cin >> oper >> u;
        for (int k = 'A'; k < oper; k++) // ex: B 2 1 20(oper:B,u:2,v1;1,v2:20)
        {
            cin >> v;
            adj[u].push_back(v);
        }
        cin >> y[u];
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = f(i);
        if (ans == -1)
        {
            cout << "#REF!\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}