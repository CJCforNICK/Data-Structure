#include <iostream>
#include <queue>
#include <string>
#include <set>
#define ll long long
using namespace std;
priority_queue<ll> maxheap; // priority default is big to small
// multiset<ll ,greater<ll>> maxheap;
priority_queue<ll, vector<ll>, greater<ll>> minheap; // priority greater from small to big
// multiset<ll> minheap;
void addNum(int num)
{
    if (maxheap.empty() || num < maxheap.top())
    {
        maxheap.push(num);
    }
    else
    {
        minheap.push(num);
    }
    if (maxheap.size() > minheap.size() + 1)
    {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
    else if (minheap.size() > maxheap.size())
    {
        maxheap.push(minheap.top());
        minheap.pop();
    }
}
double findmid()
{
    if (maxheap.size() == minheap.size())
    {
        return maxheap.top() / 2.0 + minheap.top() / 2.0;
    }

    return maxheap.top();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int num;
            cin >> num;
            addNum(num);
        }
        else if (s == "find")
        {
            cout << findmid() << "\n";
        }
    }
    // cout << "max:";
    // while (!maxheap.empty())
    // {
    //     cout << maxheap.top() << " ";
    //     maxheap.pop();
    // }
    // cout << ",min:";
    // while (!minheap.empty())
    // {
    //     cout << minheap.top() << " ";
    //     minheap.pop();
    // }
}
