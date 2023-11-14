#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
vector<vector<ll>> vv;
vector<set<ll>> vs;
int main()
{
    int n, m;
    cin >> n >> m;
    vv.resize(n + 1);
    vs.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        vv[u].push_back(v);
        vv[v].emplace_back(u);
        vs[u].emplace(v);
        vs[v].emplace(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << vv[i].size() << ",";
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << vs[i].size() << ",";
        for (auto x : vs[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
