#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
#define ll long long

void Merge(vector<ll> &arr, int L, int R, int M)
{
    vector<ll> tmp;
    int i = L, j = M + 1;
    while (i <= M && j <= R)
    {
        if (arr[i] < arr[j])
        {
            tmp.emplace_back(arr[i]);
            i++;
        }
        else
        {
            tmp.emplace_back(arr[j]);
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

void MergeSort(vector<ll> &arr, int L, int R)
{
    if (L == R)
        return;
    int M = (L + R) / 2;
    MergeSort(arr, L, M);
    MergeSort(arr, M + 1, R);
    Merge(arr, L, R, M);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    MergeSort(arr, 0, n - 1);
    for (auto x : arr)
        cout << x << ' ';
}
