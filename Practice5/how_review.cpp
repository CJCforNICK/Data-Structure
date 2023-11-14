#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
int mod = 1000000007;
vector<vector<ll>> dg;
vector<ll> indegree;
vector<ll> ways;
void topologocalSort(int n)
{
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.emplace(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto x : dg[cur])
        {
            indegree[x]--;
            ways[x] = ways[x] + ways[cur];
        }
        if (indegree[x] == 0)
        {
            q.push(x);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    ways.resize(n + 1, 0);
    dg.resize(n + 1);
    indegree.resize(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        dg[u].emplace_back(v);
        indegree[v]++;
    }
    topologicalSort(n);
    cout << ways[n] << "\n";
}