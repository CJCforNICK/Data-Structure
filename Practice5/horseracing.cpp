#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
vector<vector<ll>> dag;
vector<ll> indegree;
vector<ll> numorder;
void topologicalSort(int n)
{
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            s.insert(i);
    }
    while (!s.empty())
    {
        auto it = s.begin();
        int cur = *it;
        numorder.push_back(cur);
        s.erase(it);

        for (auto nxt : dag[cur])
        {
            indegree[nxt]--;

            if (indegree[nxt] == 0)
            {
                s.insert(nxt);
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