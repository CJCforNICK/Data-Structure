#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj_tree;
vector<int> cnt;
int count_dfs(int root)
{
    if (adj_tree[root].size() == 0) // adj_tree[i] is a leaf node
    {
        return cnt[root];
    }
    else
    {
        for (auto i : adj_tree[root]) // son of root
        {
            // cout << i << " " << cnt[root] << "\n";
            cnt[root] += count_dfs(i);
        }
    }
    return cnt[root];
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
        // due to one way adjency list, no need to check visited
    }
    cnt.resize(n + 1, 1); // initialize 1
    count_dfs(1);         // start from 1
    for (int idx = 1; idx <= n; idx++)
    {
        cout << cnt[idx] - 1 << " "; // minus back
    }
    cout << "\n";
}
