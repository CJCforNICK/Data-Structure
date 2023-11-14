#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int Bsearch(vector<ll> &arr, ll val)
{
    int l = 0, r = arr.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == val)
            return mid;
        else if (arr[mid] > val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    while (m--)
    {
        ll q;
        cin >> q;
        if (Bsearch(arr, q) == -1)
            cout << 'n';
        else
            cout << 'y';
        cout << ' ';
    }
    return 0;
}