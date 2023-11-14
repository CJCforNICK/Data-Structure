#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> killed(n);
    int now = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 2;
        while (cnt)
        {
            now = (now + 1) % n;
            if (!killed[now])
                cnt--;
        }
        killed[now] = 1;
        cout << now + 1 << ' ';
    }
}