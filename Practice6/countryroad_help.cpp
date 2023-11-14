#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <numeric>
#define LL long long
#define f first
#define s second
#define all(x) x.begin(), x.end()
using namespace std;
vector<int> sz, anc;
struct road
{
    LL v;
    int l, r;
    bool operator<(road rd) { return v < rd.v; }
};
int find(int x) { return anc[x] == x ? x : anc[x] = find(anc[x]); }
bool merge(int l, int r)
{
    if (find(l) == find(r))
        return false;
    if (sz[find(l)] < sz[find(r)])
        sz[find(r)] += sz[find(l)], anc[find(l)] = find(r);
    else
        sz[find(l)] += sz[find(r)], anc[find(r)] = find(l);
    return true;
}
int main()
{
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>());
    vector<road> rd(m);
    sz.assign(n + 1, 1);
    anc.assign(n + 1, 1);
    iota(all(anc), 0);
    for (auto &i : rd)
        cin >> i.l >> i.r >> i.v;
    sort(all(rd));
    for (int i = 1, x = 0; x < m && i < n; x++)
    {
        if (merge(rd[x].l, rd[x].r))
        {
            v[rd[x].l].push_back(rd[x].r);
            v[rd[x].r].push_back(rd[x].l);
            i++;
        }
    }
    bool used[n + 1];
    memset(used, 0, sizeof(used)), used[1] = 1;
    for (int x = 1; x <= n; x++)
    {
        cout << x << ' ';
        for (size_t y = 0; y < v[x].size(); y++)
            if (!used[v[x][y]])
                cout << v[x][y] << ' ', used[v[x][y]] = 1;
        cout << '\n';
    }
    return 0;
}