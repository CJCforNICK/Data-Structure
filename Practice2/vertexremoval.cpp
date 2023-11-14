#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 1<=n<=1000, m<=n(n-1)/2
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n + 1);
    vector<int> deg(n + 1, 0);
    while (m--)
    {
        int p, q;
        cin >> p >> q;
        edge[p].emplace_back(q);
        deg[p]++;
        edge[q].emplace_back(p);
        deg[q]++;
    }
    // for (int i = 1; i < n + 1; i++)
    // {
    //     cout << deg[i] << " ";
    // }
    // cout << "\n";
    for (int k = 0; k < n; k++)
    {
        int curhigh = -1000000, idx = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (deg[i] >= curhigh)
            {
                if (i > idx)
                {
                    curhigh = deg[i];
                    idx = i;
                }
            }
        }
        cout << idx << " ";
        for (int l = 0; l < edge[idx].size(); l++)
        {
            // cout << l << " " << deg[idx] << " " << edge[idx][l] << " " << deg[edge[idx][l]] << "/";
            if (deg[idx] != -10000000)
            {
                deg[idx]--;
                if (deg[edge[idx][l]] != 0 || deg[edge[idx][l]] != -10000000)
                {
                    deg[edge[idx][l]]--;
                }
            }
            // auto it = std::find(edge[edge[idx][l]].begin(), edge[edge[idx][l]].end(), idx);
            // if (it != edge[edge[idx][l]].end())
            // {
            //     edge[edge[idx][l]].erase(it);
            // }
            // cout << l << " " << deg[idx] << " " << edge[idx][l] << " " << deg[edge[idx][l]] << "\n";
        }
        deg[idx] = -10000000;
        // auto it = std::find(edge.begin(), edge.end(), idx);
        // edge.erase(it);
        // cout << "current deg[]";
        // for (int i = 1; i < n + 1; i++)
        // {
        //     cout << deg[i] << " ";
        // }
        // cout << "\n";
        // cout << "current real deg";
        // for (int i = 1; i < n + 1; i++)
        // {
        //     cout << edge[i].size() << " ";
        // }
        // cout << "\n";
    }
}