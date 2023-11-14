#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    list<int> li;
    for (int i = 1; i <= n; i++)
        li.push_back(i);

    auto it = li.begin();
    auto it1 = li.end();
    for (int j = 0; j < k; j++)
    {
        it++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << *it << ' ';
        it = li.erase(it);
        if (it == li.end())
        {
            it = li.begin();
        }
        for (int j = 0; j < k; j++)
        {
            it++;
        }
        if (it == li.end())
            it = li.begin();
    }
}