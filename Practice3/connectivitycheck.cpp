#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int N = 1e5;
int n, m;
vector<bool> visited(N, false);
vector<vector<ll>> G;
vector<vector<ll>> G_inverse;
bool is_connected = false;
void dfs(int u, vector<vector<ll>> &adj)
{
    visited[u] = true;
    for (auto &x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x, adj);
        }
    }
    for (int check = 1; check < visited.size(); check++)
    {
        if (visited[check] == true)
        {
            is_connected = true;
            continue;
        }
        else
        {
            is_connected = false;
            break;
        }
    }
}
int main()
{
    ll u, v, k;
    vector<ll> idx, idx1;
    cin >> n;
    cin >> m;
    visited.resize(n + 1, false);
    G.resize(n + 1);
    G_inverse.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u;
        cin >> v;
        G[u].emplace_back(v);
        G_inverse[v].emplace_back(u);
    }
    for (int i = 1; i < G.size(); i++)
    {
        fill(visited.begin(), visited.end(), false);
        dfs(i, G);
        if (is_connected == false)
        {
            continue;
        }
        else
        {
            idx.emplace_back(i);
        }
    }
    for (k = 0; k < idx.size(); k++)
    {
        fill(visited.begin(), visited.end(), false);
        dfs(idx[k], G_inverse);
        if (is_connected == true)
        {
            cout << "YES\n";
            break;
        }
    }
    if (k == idx.size())
    {
        cout << "NO";
    }
}
// cout << G.size() << "G[]\n";
// for (int i = 1; i < G.size(); i++)
// {
//     cout << "i:" << i << " " << G[i].size() << " ,";
//     for (int j = 0; j < G[i].size(); j++)
//     {
//         cout << G[i][j] << " ";
//     }
//     cout << "\n";
// }
// cout << "G_inverse[]\n";
// for (int i = 1; i < G_inverse.size(); i++)
// {
//     cout << "i:" << i << " " << G_inverse[i].size() << " ,";
//     ;
//     for (int j = 0; j < G_inverse[i].size(); j++)
//     {
//         cout << G_inverse[i][j] << " ";
//     }
//     cout << "\n";
// }
// for (int i = 1; i < G.size(); i++)
// {
//     cout << "i:" << i << " " << G[i].size() << " ,";
//     for (int j = 0; j < G[i].size(); j++)
//     {
//         cout << G[i][j] << " ";
//     }
//     cout << "\n";
// }
// cout << "idx: ";
// for (auto &x : idx)
// {
//     cout << x << " ";
// }
// for (auto &i : idx)
// {
//     fill(visited.begin(), visited.end(), false);
//     dfs(i, G_inverse);
//     if (is_connected == true)
//     {
//         cout << "YES\n";
//         break;
//     }
// }