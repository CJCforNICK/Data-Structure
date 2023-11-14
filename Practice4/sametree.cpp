#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;
vector<int> calpost;
vector<int> pos;
struct node
{
    node *left, *right;
    int value;
    node(int value) : value(value) {}
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        int now = 0;
        string s;
        preorder.resize(n + 1, 0);
        inorder.resize(n + 1, 0);
        pos.resize(n + 1, 0);
        postorder.resize(n, 0);
        calpost.clear();
        unordered_map<string, int> umap;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            umap[s] = i;
            preorder[i] = umap[s];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            inorder[i] = umap[s];
            pos[inorder[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            postorder[i] = (umap[s]);
        }
        function<node *(int, int, int)> build = [&](int l, int r, int n)
        {
            if (l > r || now > n)
            {
                return (node *)(NULL);
            }
            node *res = new node(preorder[now++]);
            if (find(pos.begin(), pos.end(), res->value) != pos.end())
            {
                res->left = build(l, pos[res->value] - 1, n);
                res->right = build(pos[res->value] + 1, r, n);
                // cout << "l:" << l << ",pos[res->value] - 1:" << pos[res->value] - 1 << ",pos[res->value] + 1:" << pos[res->value] + 1 << ",r:" << r << "\n";
            }
            else
            {
                return (node *)(NULL);
            }
            return res;
        };
        function<void(node *)> post = [&](node *t)
        {
            if (!t)
                return;
            post(t->left);
            post(t->right);
            calpost.push_back(t->value);
        };
        node *t = build(0, n - 1, n - 1);
        post(t);
        // cout << "post:";
        // for (auto &x : calpost)
        // {
        //     cout << x << " ";
        // }
        if (calpost == postorder)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}