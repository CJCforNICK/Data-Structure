#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
#define ll long long
#define tiil tuple<int, int, ll>
vector<tiil> edge;      // rd
vector<vector<ll>> adj; // v
bool comparewithW(tiil &a, tiil &b)
{
    return get<2>(a) < get<2>(b);
}
struct DSU
{
    vector<int> dsu, sz;
    DSU(int n)
    {
        dsu.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            dsu[i] = i;
    }
    int get(int x) // find
    {
        return (dsu[x] == x ? x : dsu[x] = get(dsu[x]));
    }
    bool oni(int a, int b)
    {
        a = get(a), b = get(b);
        if (a == b)
            return false;
        if (sz[a] > sz[b])
            swap(a, b);
        dsu[a] = b;
        sz[b] += sz[a];
        return true;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end(), comparewithW);
    for (int i = 1, x = 0; x < m && i < n; x++)
    {
        if (dsu.oni(get<0>(edge[x]), get<1>(edge[x])))
        {
            adj[get<0>(edge[x])].push_back(get<1>(edge[x]));
            adj[get<1>(edge[x])].push_back(get<0>(edge[x]));
            i++;
        }
    }
    vector<bool> vis(n + 1, 0);
    vis[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (!vis[adj[i][j]])
            {
                cout << adj[i][j] << " ";
                vis[adj[i][j]] = 1;
            }
            cout << "\n";
        }
    }
}