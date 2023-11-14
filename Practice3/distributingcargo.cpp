#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<bool> visited(100005, false);
vector<ll> brokesum(100001, 0);
ll accumb = 0;
struct islandData
{
    int num;
    ll broken;
    islandData(int num, ll broken)
        : num(num), broken(broken){};
};

void dfs(int u, vector<vector<islandData>> &island, vector<bool> &visited, vector<bool> &low)
{
    visited[u] = true;
    for (auto &x : island[u])
    {
        int v = x.num;
        ll brokeness = x.broken;
        if (!visited[v])
        {
            accumb = accumb + brokeness;
            dfs(v, island, visited, low);
            accumb = accumb - brokeness;
            // the end of dfs, accumb will overadded by 2 times of brokeness
        }
        if (low[u]) // only leaf will have brokensum, comment if then every one will have correct  brokensum
        {
            brokesum[u] = accumb;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<islandData>> island(n + 1);
    vector<bool> low(n + 1, false);
    if (n == 1)
    {
        cout << "City 1: 0\n";
        return 0;
    }
    else
    {
        for (int i = 1; i < n; i++) // i is just for count n-1 lines of input cmd
        {
            ll u, v;
            ll b;
            cin >> u >> v >> b;
            island[u].emplace_back(v, b);
            island[v].emplace_back(u, b);
        }
        for (int i = 1; i <= n; i++)
        {
            if (island[i].size() == 1)
            {
                low[i] = true; // check the leaf
            }
        }
        for (auto &u : island[1])
        {
            cout << u.num << " " << u.broken << "\n";
        }
        dfs(1, island, visited, low);
        for (int i = 1; i <= n; i++)
        {
            if (low[i])
            {
                cout << "City " << i << ": " << brokesum[i] << endl;
            }
        }
    }
    return 0;
}