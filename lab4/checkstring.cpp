#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

const int N = 110;
const int maxlength = 5010;
const long long mod = 1000000007, M = 37;

int n, q;
long long pw[maxlength];
vector<ll> h(N);
vector<ll> len(N);

void solve()
{

    while (q--)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;
        x--, y--;
        if (c == 'E')
            cout << (h[x] == h[y] ? "Y" : "N") << '\n';
        else
        {
            h[x] = (h[x] + h[y] * pw[len[x]] % mod) % mod;
            len[x] += len[y];
        }
    }
}

int main()
{
    pw[0] = 1;
    for (int i = 1; i < maxlength; i++) // build the power
        pw[i] = pw[i - 1] * M % mod;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        len[i] = s.size();
        for (int j = 0; j < len[i]; j++) // added each char
            h[i] = (h[i] + s[j] * pw[j] % mod) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        cout << h[i] << " ";
    }
}