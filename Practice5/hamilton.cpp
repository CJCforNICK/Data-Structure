#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
vector<vector<int>> DG;
vector<ll> indegree;
vector<ll> orders;

void topologicalSort(int n)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.emplace(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        orders.emplace_back(cur);
        q.pop();

        for (auto nxt : DG[cur])
        {
            indegree[nxt]--;
            if (indegree[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    ll cnt = 0;
    DG.resize(n + 1);
    indegree.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        DG[u].emplace_back(v);
        indegree[v]++;
    }

    topologicalSort(n);

    for (int i = 0; i < n - 1; i++)
    {
        for (auto x : DG[orders[i]])
        {
            if (x == orders[i + 1])
            {
                cnt++;
                break;
            }
        }
        if (cnt != i + 1)
        {
            cout << "NO\n";
            break;
        }
    }
    if (cnt == n - 1)
    {
        cout << "YES\n";
    }
}