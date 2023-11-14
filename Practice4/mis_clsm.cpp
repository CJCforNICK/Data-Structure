#include <iostream>
#include <vector>
using namespace std;
using LL = long long int;

LL countMIS(vector<vector<int>> &adj_list, LL root, LL dp[], vector<bool> visited)
{
    visited[root] = true;
    if (dp[root] != -1)
    {
        return dp[root];
    }

    // Calculate size excluding the current node
    LL excl = 0;
    LL incl = 1;
    for (LL i = 0; i < adj_list[root].size(); i++)
    {
        // cout<<i<<" "<<root<<"    see "<<adj_list[root][i]<<endl;
        if (!visited[adj_list[root][i]])
        {
            excl += countMIS(adj_list, adj_list[root][i], dp, visited);
            for (LL j = 0; j < (adj_list[adj_list[root][i]]).size(); j++)
            {
                if (!visited[adj_list[adj_list[root][i]][j]])
                {
                    incl += countMIS(adj_list, adj_list[adj_list[root][i]][j], dp, visited);
                }
            }
        }
    }

    dp[root] = max(incl, excl);
    return dp[root];
}

int main()
{

    LL a, b, n;
    cin >> n;
    vector<vector<int>> adj_list(n + 1);
    LL *dp = new LL[n + 1];
    for (LL i = 0; i < n + 1; i++)
    {
        dp[i] = -1;
    }
    for (LL i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj_list[a].emplace_back(b);
        adj_list[b].emplace_back(a);
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << "\n"
         << countMIS(adj_list, 1, dp, visited) << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    return 0;
}