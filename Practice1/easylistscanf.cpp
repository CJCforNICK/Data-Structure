#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
int main()
{

    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        int n, q, idx, i;
        char c;
        scanf("%d %d\n", &n, &q);
        list<int> lst;

        for (i = 0; i < n; i++)
        {
            lst.push_back(i + 1);
        }
        while (q--)
        {
            scanf("%c %d\n", &c, &idx);
            int i = 0;
            list<int>::iterator ite = find(lst.begin(), lst.end(), idx);
            if (c == 'H')
            {
                lst.erase(ite);
                lst.push_front(idx);
            }
            else
            {
                lst.erase(ite);
                lst.push_back(idx);
            }
        }
        for (auto it : lst)
        {
            cout << it << " ";
        }
        cout << '\n';
    }
}