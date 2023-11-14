#include <iostream>
#include <vector>
using namespace std;
#define ll long long
struct dataSet
{
    int num, small = 0, large = 0;
};
void Merge(vector<dataSet> &arr, int L, int R, int M)
{
    vector<int> tmp;
    tmp.clear();
    int i = L, j = M + 1;
    while (i <= M && j <= R)
    {
        if (arr[i].num < arr[j].num)
        {
            tmp.emplace_back(arr[i].num);
            arr[i].large += (R - j + 1);
            cout << "A" << i << " " << j << " " << arr[i].num << " " << arr[i].large << " " << arr[i].small << '\n';
            i++;
        }
        else
        {
            tmp.emplace_back(arr[j].num);
            arr[j].small += (i - L);
            cout << "B" << i << " " << j << " " << arr[j].num << " " << arr[j].large << " " << arr[j].small << '\n';
            j++;
        }
    }
    while (i <= M)
    {
        tmp.emplace_back(arr[i].num);
        cout << i << " " << j << " " << arr[i].num << " " << arr[i].large << " " << arr[i].small << '\n';
        i++;
    }
    while (j <= R)
    {
        tmp.emplace_back(arr[j].num);
        arr[j].small += (M - L + 1);
        cout << i << " " << j << " " << arr[j].num << " " << arr[j].large << " " << arr[j].small << '\n';
        j++;
    }
    for (int i = 0; i < tmp.size(); i++)
        arr[L + i].num = tmp[i];
}

void MergeSort(vector<dataSet> &arr, int L, int R)
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
    int n, x;
    ll cnt;
    cin >> n;
    vector<dataSet> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i].num = x;
    }
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].num << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].num << " " << arr[i].small << " " << arr[i].large << "\n";
    }
}
