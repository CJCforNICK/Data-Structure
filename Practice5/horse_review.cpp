#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define ll long long
using namespace std;
vector<vector<ll>> dag;
vector<ll> indegree;
vector<ll> numorder;
void topologicalSort(int n)
{
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.emplace(i);
    }
    while (!q.empty())
    {
        int cur = q.top();
        numorder.push_back(cur);
        q.pop();
        for (auto nxt : dag[cur])
        {
            indegree[nxt]--;

            if (indegree[nxt] == 0)
            {
                q.emplace(nxt);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    dag.resize(n + 1);
    indegree.resize(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        dag[u].emplace_back(v);
        indegree[v]++;
    }
    topologicalSort(n);
    if (numorder.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << numorder[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}