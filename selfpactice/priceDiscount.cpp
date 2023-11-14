#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prices.push_back(x);
    }
    vector<int> ans(prices.size());
    stack<int> s; // stack is for discount
    for (int i = prices.size() - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top() > prices[i])
            s.pop();   // when price[i+1]>price[i], price[i+1] will no longer be the discount
        if (s.empty()) // prices is the lowest price and discount
        {
            ans[i] = prices[i];
            s.push(prices[i]);
        }
        else // not empty && s.top()<prices[i]
        {
            ans[i] = prices[i] - s.top();
            s.push(prices[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}