#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
vector<ll> start;
multiset<ll, greater<ll>> curStudentend;                // from large to small
priority_queue<pll, vector<pll>, greater<pll>> classes; // from small to big of pair.first
int main()
{
    ll n, k, max = 0;
    cin >> n >> k;
    start.resize(n + 1);
    for (int i = 1; i <= k; i++)
    {
        curStudentend.emplace(-1); // default
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> start[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int end;
        cin >> end;
        classes.push({end, start[i]}); // classes queue is in ascending order of ending time
    }
    while (!classes.empty())
    {
        ll nxt = classes.top().second;
        for (auto it : curStudentend)
        {
            if (it < nxt)
            {
                curStudentend.erase(curStudentend.find(it));
                curStudentend.emplace(classes.top().first);
                max++;
                break;
            }
        }
        classes.pop();
    }
    cout << max << "\n";
}