#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define tiii tuple<int, int, int>
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
    int n;
    cin >> n;
    DSU dsu(n);
    vector<pii> shop(n + 1);
    vector<tuple<int, int, int>> edge;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        shop[i].first = x;
        shop[i].second = y;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ll temp = ((shop[i].first - shop[j].first) * (shop[i].first - shop[j].first)) + ((shop[i].second - shop[j].second) * (shop[i].second - shop[j].second));
            if (i != j)
            {
                edge.push_back({temp, i, j});
            }
            else
            {
                continue;
            }
        }
    }
    sort(edge.begin(), edge.end());
    for (auto x : edge)
    {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    }
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