#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
bool comparewithv(tuple<int, int, int> &a, tuple<int, int, int> &b)
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
    int get(int x)
    {
        return (dsu[x] == x ? x : dsu[x] = get(dsu[x]));
    }
    void oni(int a, int b)
    {
        a = get(a), b = get(b);
        if (a == b)
            return;
        if (sz[a] > sz[b])
            swap(a, b);
        dsu[a] = b;
        sz[b] += sz[a];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n); // initialize DSU

    vector<tuple<int, int, int>> edge;
    vector<tuple<int, int, int>> edge1;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({w, u, v}); // sort by w
    }
    sort(edge.begin(), edge.end());
    // for (auto x : edge)
    // {
    //     cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    // }
    long long ans = 0;
    int cnt = 0;
    for (auto [w, u, v] : edge)
    {
        if (dsu.get(u) == dsu.get(v))
            continue;
        ans += w;
        cnt++;
        dsu.oni(u, v);
    }
    if (cnt != n - 1)
        cout << "-1";
    else
        cout << ans << "\n";
}