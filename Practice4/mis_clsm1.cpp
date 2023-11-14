#include <iostream>
#include <vector>
using namespace std;
int dp[200005][2];
void dptree(int now, vector<vector<int>> &adj, vector<int> &visited)
{
    visited[now] = 1; // not go back to parentnode
    int flag = 0;
    for (int i = 0; i < adj[now].size(); i++)
    {
        if (visited[adj[now][i]] == 0)
        {
            flag = 1;                                                  // nownode isn't leafnode
            dptree(adj[now][i], adj, visited);                         // update dp of childnodes
            dp[now][0] += max(dp[adj[now][i]][0], dp[adj[now][i]][1]); // undrawnownode,childnode can be draw or undraw,we choose maximum one
            dp[now][1] += dp[adj[now][i]][0];                          // drawnownode,childnode must be undraw
        }
    }
    if (flag == 0)
    {
        // flag==0,leafnode, if drawnode dp=1,notdrawnode dp=0
        dp[now][0] = 0;
        dp[now][1] = 1;
    }
    else
    {
        dp[now][1]++; // plus 1 as drawing nownode
    }
}
int main(void)
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> visited(n + 1, 0);
    vector<int> draw(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    dptree(1, adj, visited);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << max(dp[1][0], dp[1][1]) << endl; // take the maximum of draw or undraw in the nownode 1
}