#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
vector<ll> start;
vector<ll> curStudentend;                               // from large to small
priority_queue<pll, vector<pll>, greater<pll>> classes; // from small to large
bool compare2(ll a, ll b)
{
    return (a > b);
}
int main()
{
    ll n, k, max = 0;
    cin >> n >> k;
    start.resize(n + 1);
    curStudentend.resize(k, -1); // default
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
        for (int i = 0; i < curStudentend.size(); i++)
        {
            if (curStudentend[i] < nxt)
            {
                curStudentend[i] = classes.top().first;
                max++;
                sort(curStudentend.begin(), curStudentend.end(), compare2);
                break;
            }
        }
        classes.pop();
    }
    cout << max << "\n";
}