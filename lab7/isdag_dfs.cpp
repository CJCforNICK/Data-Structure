#include <iostream>
#include <vector>
using namespace std;
// used unvisited:0, visited:-1 finished:1
vector<vector<int>> G;
vector<int> ans;
vector<int> used;

bool dfs(int u)
{
    used[u] = -1;
    for (int v : G[u])
    {
        if (used[v] < 0)
            return false;
        else if (!used[v])
            if (!dfs(v))
                return false;
    }
    used[u] = 1;
    ans.emplace_back(u);
    return true;
}

bool topological_sort(int n)
{
    ans.clear();
    used.assign(n + 1, 0);
    for (int u = 1; u <= n; u++)
    {
        if (!used[u])
            if (!dfs(u))
                return false;
    }
    return true;
}
signed main()
{
    int n, m, u, v;
    cin >> n >> m;
    G.resize(n + 1);
    while (m--)
    {
        cin >> u >> v;
        G[u].emplace_back(v);
    }
    if (!topological_sort(n))
        cout << "NO\n";
    else
        cout << "YES\n";
}