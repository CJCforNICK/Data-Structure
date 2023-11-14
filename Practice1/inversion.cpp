#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void Merge(vector<ll> &arr, int L, int R, int M, ll &ivsn)
{
    vector<ll> tmp;
    int i = L, j = M + 1;
    while (i <= M && j <= R)
    {
        if (arr[i] <= arr[j])
        {
            tmp.emplace_back(arr[i]);
            i++;
        }
        else
        {
            tmp.emplace_back(arr[j]);
            ivsn = ivsn + M - i + 1;
            // cout << "temp ivsn:" << ivsn << " i: " << i << " j: " << j << endl;
            j++;
        }
    }
    while (i <= M)
        tmp.emplace_back(arr[i++]);
    while (j <= R)
        tmp.emplace_back(arr[j++]);
    for (int i = 0; i < tmp.size(); i++)
        arr[L + i] = tmp[i];
}

void MergeSort(vector<ll> &arr, int L, int R, ll &ivsn)
{
    if (L == R)
        return;
    int M = (L + R) / 2;
    MergeSort(arr, L, M, ivsn);
    MergeSort(arr, M + 1, R, ivsn);
    // cout << "!!" << L << " " << M << " " << R << " ";
    Merge(arr, L, R, M, ivsn);
    // cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll ivsn = 0;
    for (auto &x : arr)
        cin >> x;
    MergeSort(arr, 0, n - 1, ivsn);
    // for (auto x : arr)
    //     cout << x << ' ';
    cout << ivsn << endl;
}