#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Merge(vector<int> &arr, int L, int R, int M)
{
    vector<int> tmp;
    int i = L, j = M + 1;
    while (i <= M && j <= R)
    {
        if (arr[i] > arr[j])
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

void MergeSort(vector<int> &arr, int L, int R)
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
    int n, m;
    cin >> n >> m;
    vector<int> arrofCandy(n);
    vector<int> arrofPpl(m);
    for (auto &x : arrofCandy)
        cin >> x;
    for (auto &x : arrofPpl)
        arrofPpl[x] = 0;
    MergeSort(arrofCandy, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        arrofPpl[i] = arrofCandy[i];
    }
    for (int i = 0; i < m - n; i++)
    {
        if (arrofPpl[i] % 2 == 1)
        {
            arrofPpl[n + i] = (arrofPpl[i] / 2) + 1;
            arrofPpl[i] = arrofPpl[i] / 2;
        }
        else
        {
            arrofPpl[n + i] = (arrofPpl[i] / 2);
            arrofPpl[i] = arrofPpl[i] / 2;
        }
    }
    int max = *max_element(arrofPpl.begin(), arrofPpl.end());
    cout << max << '\n';
}