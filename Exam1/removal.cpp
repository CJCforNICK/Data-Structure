#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
string t;
bool traversal(vector<int> &ind, int m, int p)
{
    vector<bool> dele(m + 1, false);
    // make dele whose length is same as indices with all false
    for (int i = 0; i <= p; i++)
        dele[ind[i] - 1] = true;
    dele[m] = true;
    int current = 0;

    for (int i = 0; i < s.length(); i++)
    {
        while (dele[current])
        {
            current++;
            if (current == m)
                return true;
        }
        if (t[current] == s[i])
            current++; // found
        if (current == m)
            return true;
    }
    return false;
}
int main()
{
    int n, m, z;
    cin >> n >> m;
    vector<int> ind(m + 1);
    cin >> s;
    cin >> t;
    for (auto &x : ind)
    {
        cin >> x;
    }
    int l = 0, r = m - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        // cout << "left=" << left << " mid="  << mid << " right=" << right << endl;
        if (traversal(ind, m, mid))
        {
            // cout << "**find seq" << endl;
            r = mid;
        }
        else
            l = mid + 1;
    }
    cout << l + 1 << '\n';
}