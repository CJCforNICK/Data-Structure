#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#define tiii tuple<int, int, int>
#define ll long long
using namespace std;
bool comparewithUVW(tiii &a, tiii &b)
{
    if (get<0>(a) != get<0>(b))
        return get<0>(a) > get<0>(b);
    if (get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);

    return get<2>(a) > get<2>(b);
}
int main()
{
    vector<tiii> vec;
    int n;
    cin >> n;
    while (n--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        vec.push_back({u, v, w});
    }
    sort(vec.begin(), vec.end(), comparewithUVW);
    for (auto &x : vec)
    {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    }
}