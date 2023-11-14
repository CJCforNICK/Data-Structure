#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int mod = 1000000007;
vector<vector<int>> DG;
vector<long long int> indegree;
vector<long long int> ways;

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
        q.pop();

        for (auto nxt : DG[cur])
        {
            ways[nxt] = (ways[nxt] + ways[cur]) % mod;
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

    DG.resize(n + 1);
    indegree.resize(n + 1, 0);
    ways.resize(n + 1, 0);
    ways[1] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        DG[u].emplace_back(v);
        indegree[v]++;
    }

    topologicalSort(n);

    cout << ways[n] << "\n";
}