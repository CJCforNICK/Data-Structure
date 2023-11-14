#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    while (n--)
    {
        char c;
        int cmd;
        cin >> c;
        if (c == 'I')
        {
            cin >> cmd;
            if (s.find(cmd) != s.end()) // set.find result is a iterator
            {
                cout << s.size() << "\n";
            }
            else
            {
                s.insert(cmd);
                cout << s.size() << "\n";
            }
            // for (auto &x : s)
            // {
            //     cout << x << " ";
            // }
            // cout << "\n";
        }
        else if (c == 'D')
        {
            cin >> cmd;
            if (s.find(cmd) != s.end()) // set.find result is a iterator
            {
                s.erase(cmd);
                cout << s.size() << "\n";
            }
            else
            {
                cout << s.size() << "\n";
            }
            // for (auto &x : s)
            // {
            //     cout << x << " ";
            // }
            // cout << "\n";
        }
        else if (c == 'S')
        {
            cin >> cmd;
            if (s.find(cmd) != s.end()) // set.find result is a iterator
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            // for (auto &x : s)
            // {
            //     cout << x << " ";
            // }
            // cout << "\n";
        }
        else if (c == 'L')
        {
            cin >> cmd;
            if (s.lower_bound(cmd) != s.end()) // set.find result is a iterator
            {
                cout << *s.lower_bound(cmd) << "\n";
            }
            else
            {
                cout << "-1L\n";
            }
            // for (auto &x : s)
            // {
            //     cout << x << " ";
            // }
            // cout << "\n";
        }
        else if (c == 'U')
        {
            cin >> cmd;
            if (s.upper_bound(cmd) != s.end()) // set.find result is a iterator
            {
                cout << *s.upper_bound(cmd) << "\n";
            }
            else
            {
                cout << "-1U\n";
            }
            // for (auto &x : s)
            // {
            //     cout << x << " ";
            // }
            // cout << "\n";
        }
        else if (c == 'm')
        {
            if (!s.empty())
            {
                cout << *s.begin() << " m\n";
            }
        }
        else if (c == 'M')
        {
            if (!s.empty())
            {
                cout << *s.rbegin() << " M\n";
            }
        }
    }
}