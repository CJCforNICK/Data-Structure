#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, op, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        list<int> lst;
        vector<list<int>::iterator> vecforit(n);
        list<int> dead(1, 1);

        for (int i = 0; i < n; i++)
        {
            lst.emplace_back(i + 1);
            vecforit[i] = (--lst.end());
        }

        // for (auto &x : lst)
        // {
        //     cout << x << " ";
        // }
        while (k--)
        {
            cin >> op;
            if (vecforit[op - 1] != dead.end())
            {
                if (next(vecforit[op - 1]) != lst.end())
                {
                    cout << *(next(vecforit[op - 1])) << '\n';
                    vecforit[*(next(vecforit[op - 1])) - 1] = dead.end();
                    lst.erase(next(vecforit[op - 1]));
                }
                else
                    cout << "Penguin07 QQ\n";
            }
            else
            {
                cout << "Penguin07 QQ\n";
            }
        }
    }
}