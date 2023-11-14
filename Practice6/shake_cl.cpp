#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    adj.resize(n + 1);
    while (q--)
    {
        int op, x1, x2;
        cin >> op >> x1 >> x2;

        if (op == 1)
        {
            adj[x1].push_back(x2);
            adj[x2].push_back(x1);
        }
        else if (op == 2)
        {
            if (find(adj[x1].begin(), adj[x1].end(), x2) != adj[x1].end())
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}