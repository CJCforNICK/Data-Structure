#include <iostream>
#include <string>
#include <vector>
#include <set>
#define ll long long
using namespace std;
const int n = 2e5;
bool ispermutation(const vector<int> &cnt)
{
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
            return false;
    }
    return true;
}
ll get_hash_val(ll l, ll r, ll mod, ll n, vector<ll> &pw, vector<ll> &h)
{
    return (((h[r] - h[l - 1]) % mod * pw[n - l + 1]) % mod + mod) % mod;
}
int main()
{
    ll mod = 1e9 + 7, M = 37, l, r, lenN;
    string N, H;
    cin >> N >> H;
    lenN = N.size();
    l = 0;
    r = lenN - 1;
    vector<int> cnt(26, 0);
    vector<ll> pw(2e5 + 1, 1);
    vector<ll> h(H.size(), 0);
    set<ll> all;
    for (int i = 0; i < lenN; i++) // 0~25->a~z, count amount of each character in needle
    {
        cnt[N[i] - 97]++;
    }
    for (ll i = 1; i <= 200000; i++) // power with M=37
    {
        pw[i] = pw[i - 1] * M % mod;
    }
    for (ll i = 1; i <= H.size(); i++) // hash table of haystack
    {
        h[i] = (h[i - 1] + H[i] * pw[i] % mod) % mod;
    }
    for (ll k = l; k <= r; k++)
    {
        cnt[H[k] - 97]--;
    }
    while (r < H.size())
    {
        if (ispermutation(cnt))
        {
            all.emplace(get_hash_val(l + 1, r, mod, n, pw, h));
        }
        cnt[H[l] - 97]++;
        l++;
        r++;
        if (r >= H.size())
            break;
        cnt[H[r] - 97]--;
    }
    cout << all.size() << "\n";
}