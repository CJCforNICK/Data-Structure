#include <iostream>
#include <set>
#include <vector>
#define ll long long
using namespace std;
int n, k;
vector<ll> color;
vector<ll> p;
multiset<ll> s;

int Find(int x)
{
    return p[x] < 0 ? x : p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    int g1 = Find(x);
    int g2 = Find(y);
    if (p[g1] > p[g2])
        swap(g1, g2);
    auto it = s.find(-p[g1]);
    s.erase(it);
    it = s.find(-p[g2]);
    s.erase(it);
    p[g1] += p[g2];
    p[g2] = g1;
    s.insert(-p[g1]);
    // cout << g1 << " " << g2 << ",s:";
    // for (auto x : s)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    color.resize(n + 1);
    p.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> color[i];
        if (color[i])
        {
            p[i] = -1;
            s.insert(1);
            if (color[i - 1])
                Union(i - 1, i);
        }
    }
    // for (int i = 1; i < p.size(); i++)
    // {
    //     cout << p[i] << " ";
    // }
    // cout << "\n";
    // for (auto x : s)
    // {
    //     cout << x << " ";
    // }
    // cout << "done\n";
    ll max = *s.rbegin();
    ll min = *s.begin();
    // cout << min << " " << max << "\n";
    int pos;
    for (int i = 0; i < k; i++)
    {
        cin >> pos;
        color[pos] = 1;
        p[pos] = -1;
        s.insert(1);
        if (color[pos - 1])
            Union(pos - 1, pos);
        if (color[pos + 1])
            Union(pos, pos + 1);
        ll maxtoadd = *s.rbegin();
        ll mintoadd = *s.begin();
        // cout << "max:" << maxtoadd << ",min:" << mintoadd << "\n";
        max += *s.rbegin();
        min += *s.begin();
    }
    cout << max << "\n";
    cout << min << "\n";
    return 0;
}