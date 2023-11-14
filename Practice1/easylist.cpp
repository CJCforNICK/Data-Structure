#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // this part is the faster i/o way I found on the Internet
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, idx, i;
        char c;
        cin >> n >> q;
        list<int> lst;
        for (i = 0; i < n; i++)
        {
            lst.push_back(i + 1); // make the list with sequential integer
        }
        while (q--)
        {
            cin >> c;
            cin >> idx;                                                  // the input after char
            list<int>::iterator ite = find(lst.begin(), lst.end(), idx); // find if there is any data same as idx
            if (c == 'H')                                                // move to head
            {
                lst.erase(ite);
                lst.push_front(idx);
            }
            else // move to tail
            {
                lst.erase(ite);
                lst.push_back(idx);
            }
        }
        for (auto it : lst) // print list
        {
            cout << it << " ";
        }
        cout << '\n';
    }
}