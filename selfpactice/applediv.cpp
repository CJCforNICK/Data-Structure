#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll findminans(vector<ll> &arr, ll currsum, ll totalsum, int i)
{
    if (i == 0) // no need to do arr[0] because arr[0] is regarded as the other group
    {
        return abs((totalsum - currsum) - currsum);
    }
    return min(findminans(arr, currsum + arr[i], totalsum, i - 1), findminans(arr, currsum, totalsum, i - 1));
}
int main()
{
    int n;
    ll x;
    ll totalsum = 0;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
        totalsum += arr[i];
    }
    cout << findminans(arr, 0, totalsum, n - 1) << '\n';
}