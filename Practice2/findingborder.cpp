#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e6;
const long long mod = 1e9 + 7, M = 373;
char s[N];
ll pw[N];
ll h[N];
int n;
bool allCharactersSame(string s)
{
    int n = s.length();
    for (int i = 1; i < n; i++)
        if (s[i] != s[0])
            return false;

    return true;
}
void build()
{
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * M % mod;
    for (int i = 1; i <= n; i++)
    {
        h[i] = (h[i - 1] + (s[i - 1] * pw[i]) % mod) % mod;
    }
}

bool isSame(int len)
{
    if ((h[len] * pw[n - len]) % mod == (((h[n] - h[n - len]) % mod) + mod) % mod)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    cin >> s;
    n = strlen(s);
    // cout << len << "\n";
    build();
    if (allCharactersSame(s))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
        return 0;
    }
    // cout << "build done\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << pw[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << h[i] << " ";
    // }
    // cout << "\n";
    for (int i = 1; i < n; i++)
    {
        if (isSame(i) == true)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}