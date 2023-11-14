#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        price.push_back(x);
    }
    stack<int> s;
    vector<int> ans(price.size());
    for (int j = price.size() - 1; j >= 0; j--)
    {
        while (!s.empty() && s.top() > price[j])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[j] = price[j];
            s.push(price[j]); // new discount
        }
        else
        {
            ans[j] = price[j] - s.top();
            s.push(price[j]);
        }
    }
    for (auto &x : ans)
    {
        cout << x << " ";
    }
}