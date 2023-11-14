#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int singlecount(vector<int> &arr, int idx, int n)
{
    int less = 0, more = 0;
    for (int i = 0; i < idx; i++)
    {
        if (arr[i] < arr[idx])
        {
            less++;
        }
    }
    for (int i = idx + 1; i < n; i++)
    {
        if (arr[i] > arr[idx])
        {
            more++;
        }
    }
    return less * more;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    ll cnt = 0;
    cin >> n;
    vector<int> oriv(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        oriv[i] = x;
    }
    for (int i = 1; i < n - 1; i++)
    {
        cnt += singlecount(oriv, i, n);
    }
    cout << cnt;
}