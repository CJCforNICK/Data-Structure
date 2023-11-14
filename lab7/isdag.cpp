#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
vector<int> indegree;
vector<int> ans;
void topologicalSort(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.emplace(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto &v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.emplace(v);
            }
        }
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    indegree.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    topologicalSort(n);
    if (ans.size() == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}