#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<vector<ll>> sumbyroot;
void MaxIS(vector<int> &vis, vector<vector<ll>> &sumbyroot, vector<vector<ll>> &adj, ll root) // need to figure out why visited dont call by reference
{
    vis[root] = true; // visited
    bool flag = false;
    // MAX { (1 + sum of LISS for all grandchildren of X),(sum of LISS for all children of X) }
    for (int i = 0; i < adj[root].size(); i++)
    {
        if (vis[adj[root][i]] == false) // son has not been visited
        {
            flag = true;
            MaxIS(vis, sumbyroot, adj, adj[root][i]);                                          // sum of all son clusters
            sumbyroot[root][0] += max(sumbyroot[adj[root][i]][0], sumbyroot[adj[root][i]][1]); // exclude
            sumbyroot[root][1] += sumbyroot[adj[root][i]][0];                                  // include
            // cout << "in:" << sumbyroot[root][1] << " " << root << " " << i << "\n";
            // cout << "ex:" << sumbyroot[root][0] << " " << root << " " << i << "\n";
        }
    }
    if (flag == false) // this root is leaf node
    {
        sumbyroot[root][0] = 0; // exclude
        sumbyroot[root][1] = 1; // include
    }
    else // not leaf node
    {
        sumbyroot[root][1] += 1;
    }
}

int main()
{
    int n;
    int u, v;
    cin >> n;
    vector<vector<ll>> adj;
    vector<int> vis(n + 1, 0);
    adj.resize(n + 1);
    sumbyroot.resize(n + 1, vector<ll>(2, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << sumbyroot[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < n - 1; i++)
    { // i only use for count n-1 lines
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i < adj.size(); i++)
    // {
    //     cout << "i:" << i << " " << adj[i].size() << " ,";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    MaxIS(vis, sumbyroot, adj, 1); // start from 1
    // for (int i = 0; i < sumbyroot.size(); i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << sumbyroot[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << max(sumbyroot[1][0], sumbyroot[1][1]) << "\n";
}