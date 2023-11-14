#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
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
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (dsu.get(u) == dsu.get(v))
            continue;
        dsu.oni(u, v);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cout << i << "," << j << ":";
            if (dsu.get(i) == dsu.get(j))
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
}