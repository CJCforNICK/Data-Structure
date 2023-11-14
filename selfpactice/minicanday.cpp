#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, i, sum = 0;
    cin >> N;
    vector<int> arr(N);
    for (auto &x : arr)
    {
        cin >> x;
    }
    vector<int> ans(N);
    for (auto &y : ans)
    {
        y = 1;
    }
    for (i = 0; i < N; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            ans[i + 1] = ans[i] + 1;
        }
    }
    for (i = N - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && ans[i] <= ans[i + 1])
        {
            ans[i] = ans[i + 1] + 1;
        }
        sum += ans[i];
    }
    sum += ans[N - 1];
    for (i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n'
         << sum << " ";
}
