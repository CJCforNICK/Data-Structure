#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long
vector<vector<ll>> adj;
set<ll> nums;
ll num = 0, curlarge = 1;
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
    int get_size(int x)
    {
        return sz[get(x)];
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
        if (curlarge <= sz[b])
        {
            curlarge = sz[b];
        }
        nums.erase(nums.find(a));
        nums.emplace(b);
    }
};
int main()
{
    int n, m;
    adj.resize(n + 1);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        nums.insert(i);
    }
    DSU dsu(n); // initial DSU
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (dsu.get(u) != dsu.get(v))
        {
            dsu.oni(u, v);
            num = nums.size();
            cout << num << " " << curlarge << "\n";
        }
        else
        {
            num = nums.size();
            cout << num << " " << curlarge << "\n";
        }
    }
    return 0;
}