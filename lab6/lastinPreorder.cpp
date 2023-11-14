#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<int> preorder;
vector<int> postorder;
vector<int> inorder;
void makepreorder(int i, vector<pair<int, int>> &tree)
{
    if (i == -1)
        return;
    preorder.push_back(i);
    makepreorder(tree[i].first, tree);
    makepreorder(tree[i].second, tree);
    return;
}
void makepostorder(int i, vector<pair<int, int>> &tree)
{
    if (i == -1)
        return;
    makepostorder(tree[i].first, tree);
    makepostorder(tree[i].second, tree);
    postorder.push_back(i);
    return;
}
void makeinorder(int i, vector<pair<int, int>> &tree)
{
    if (i == -1)
        return;
    makeinorder(tree[i].first, tree);
    inorder.push_back(i);
    makeinorder(tree[i].second, tree);
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> tree;
    tree.resize(n + 5);
    vector<int> parent(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].first >> tree[i].second;
        if (tree[i].first != -1)
        {
            parent[tree[i].first] = i;
        }
        if (tree[i].second != -1)
        {
            parent[tree[i].second] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!parent[i])
        {
            makepreorder(i, tree);
            makepostorder(i, tree);
            makeinorder(i, tree);
        }
    }
    cout << "Preorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << preorder[i] << " ";
    }
    cout << "\n";
    cout << "Postorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << postorder[i] << " ";
    }
    cout << "\n";
    cout << "Inorder: ";
    for (int i = 0; i < n; i++)
    {
        cout << inorder[i] << " ";
    }
    cout << "\n";
}