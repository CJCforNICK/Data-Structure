#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> m(1000001, 0);
    // m[i] is to check m[0] and m[i] match or not
    vector<int> ans;
    string s;
    int left = 0, right = 0;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
        if (i <= right && m[i - left] < right - i + 1)
        {
            m[i] = m[i - left];
        }
        else
        {
            left = i;
            if (i > right)
            {
                right = i;
            }
            while (right < s.length() && s[right - left] == s[right])
                right++;
            right--;
            m[left] = right - left + 1;
        }
        if (m[i] == s.length() - i)
            ans.push_back(s.length() - i);
    }
    reverse(ans.begin(), ans.end());
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}