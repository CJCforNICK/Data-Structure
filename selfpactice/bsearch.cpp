#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int bsearch(vector<ll> &arr, int idx)
{
    int l = 0, mid, r = arr.size() - 1;
    while (l <= r) // l<=r
    {
        mid = (l + r) / 2;
        if (arr[mid] == idx) // not mid & idx, is arr[mid]&idx
        {
            return mid;
        }
        else if (arr[mid] > idx)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, m, x, i;
    cin >> n >> m;
    vector<ll> arr1(n);
    for (auto &x : arr1)
        cin >> x;
    for (i = 0; i < m; i++)
    {
        ll q;
        cin >> q;
        if (bsearch(arr1, q) == -1)
        {
            cout << 'N';
        }
        else
            cout << 'Y';
        cout << " ";
    }
    return 0;
}