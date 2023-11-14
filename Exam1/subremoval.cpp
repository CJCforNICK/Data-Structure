#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n, m, z, p = 1;
    cin >> n >> m;
    vector<char> s(n);
    vector<char> t(m);
    vector<char> newt(m);
    for (auto &x : s)
    {
        cin >> x;
    }
    for (auto &y : t)
    {
        cin >> y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> z;
        newt[i] = t[z - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cout << newt[i];
    }
    cout << "\n";
    int check = 0, tmp = 0;
    for (int i = p; i < m; i++)
    {
        cout << i << " " << newt[i];
        for (int j = tmp; j < n; j++)
        {
            if (newt[i] == s[j])
            {
                check++;
                cout << i << " " << j << " " << newt[i] << " "
                     << "check";
                break;
            }
            tmp = j;
        }
    }
    if (check == (m - p))
    {
        cout << "yes";
    }
    else
        cout << "no";
}