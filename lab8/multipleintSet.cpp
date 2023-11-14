#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
int main()
{
    int n, m;
    map<int, int> mp; // map<key, value> and will automatically in order of key
    // insert: mp[key] = value;
    cin >> n >> m;
    vector<int> occurence(n, 0);
    while (n--)
    {
        int u;
        cin >> u;
        mp[u]++;
    }
    for (auto &x : mp)
    {
        cout << "num:" << x.first << " occurence: " << x.second << "\n";
    }
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "min")
        {
            cout << (*mp.begin()).first << "\n";
        }
        else if (s == "max")
        {
            cout << (*mp.rbegin()).first << "\n";
        }
        else if (s == "maxOc")
        {
            int tempMax = 0;
            for (auto &x : mp)
            {
                if (x.second > tempMax)
                {
                    tempMax = x.second;
                }
            }
            cout << tempMax << "\n";
        }
        else if (s == "minOc")
        {
            int tempmin = 1;
            for (auto &x : mp)
            {
                if (x.second < tempmin)
                {
                    tempmin = x.second;
                }
            }
            cout << tempmin << "\n";
        }
    }
}