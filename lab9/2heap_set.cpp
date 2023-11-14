#include <iostream>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
#define ll long long
multiset<ll, greater<ll>> maxheap;
multiset<ll> minheap;
void addNum(int num)
{
    if (maxheap.empty() || num < *(maxheap.begin()))
    {
        maxheap.insert(num);
    }
    else
    {
        minheap.insert(num);
    }
    if (maxheap.size() > minheap.size() + 1)
    {
        ll temp = *(maxheap.begin());
        multiset<ll>::iterator it = maxheap.begin();
        minheap.insert(temp);
        maxheap.erase(it);
    }
    else if (minheap.size() > maxheap.size())
    {
        ll temp1 = *(minheap.begin());
        multiset<ll>::iterator it = minheap.begin();
        maxheap.insert(temp1);
        minheap.erase(it);
    }
}
double findmid()
{
    if (maxheap.size() == minheap.size())
    {
        return *(minheap.begin()) / 2.0 + *(maxheap.begin()) / 2.0;
    }
    return *(maxheap.begin());
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
        else if (s == "findmid")
        {
            cout << fixed << setprecision(1) << findmid() << "\n";
        }
    }
    // cout << "max:";
    // for (auto &x : maxheap)
    // {
    //     cout << x << " ";
    // }
    // cout << ",min:";
    // for (auto &x : minheap)
    // {
    //     cout << x << " ";
    // }
}
