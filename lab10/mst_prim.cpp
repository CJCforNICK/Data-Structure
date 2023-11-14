#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define PII pair<int, int>
#define VPII vector<PII>

int Prims_MST(int source_node, std ::vector<VPII> &graph)
{

    // The priority_queue stores the pair<weight, node>
    std ::priority_queue<PII, std ::vector<PII>, std ::greater<PII>> q;

    // The cost of the source node to itself is 0
    q.push(std ::make_pair(0, source_node));

    vector<bool> added(graph.size(), false);
    ll mst_cost = 0;
    while (!q.empty())
    {

        // Select the item <cost, node> with minimum cost
        PII item;
        item = q.top();
        q.pop();

        int node = item.second;
        int cost = item.first;
        // If the node is node not yet added to the minimum spanning tree add it, and increment the cost.
        if (!added[node])
        {
            mst_cost += cost;
            added[node] = true;
            cout << node << ":";
            // Iterate through all the nodes adjacent to the node taken out of priority queue.
            // Push only those nodes (weight,node) that are not yet present in the minumum spanning tree.
            for (auto &pair_cost_node : graph[node])
            {
                int adj_node = pair_cost_node.second;
                if (added[adj_node] == false)
                {
                    q.push(pair_cost_node);
                }
                cout << "\n";
            }
        }
    }
    return mst_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> adj;
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ":";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         pii temp = adj[i][j];
    //         cout << "{" << temp.first << "," << temp.second << "},";
    //     }
    //     cout << "\n";
    // }
    cout << "Cost of the minimum spanning tree in graph 1 : " << Prims_MST(1, adj) << std ::endl;
}