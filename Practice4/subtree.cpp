#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj_tree;
vector<int> cnt;
vector<int> temp;
void tocount(int idx, int i, vector<vector<int>> &adj_tree)
{
    if (adj_tree[i].size() == 0) // adj_tree[i] is a leaf node
    {
        return;
    }
    else // adj_tree[i] is not a leaf node
    {
        cnt[idx] += adj_tree[i].size(); // the amount of son
        for (auto &j : adj_tree[i])     // j is son of adj_tree[i]
        {
            cout << "temp[" << j << "]:" << temp[j] << "\n";
            if (temp[j] != 0) // j(son) has been done before
            {
                cout << "!=0,temp[" << j << "]:" << temp[j] << "\n";
                cnt[idx] += temp[j];
            }
            else
            {
                tocount(idx, j, adj_tree);
                temp[j] = cnt[j];
                cout << "idx:" << idx << ",i:" << i << ",j:" << j << ",cnt:";
                for (int k = 1; k < cnt.size(); k++)
                {
                    cout << cnt[k] << " ";
                }
                cout << "\n";
            }
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    int x;
    adj_tree.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        adj_tree[x].push_back(i); // i = x's son
    }
    cnt.resize(n + 1, 0);
    temp.resize(n + 1, 0);
    for (int idx = 1; idx <= n; idx++)
    {
        tocount(idx, idx, adj_tree); // start from (1,1,tree). the first idx, which represents root, won't change in a for-loop
    }
    for (int idx = 1; idx <= n; idx++)
    {
        cout << cnt[idx] << " ";
    }
    cout << "\n";
}