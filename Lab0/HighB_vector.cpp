#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto &x : heights)
    {
        cin >> x;
    }
    int i = 0, j = i + 1;
    int idx = 0;
    if (n == 1)
    {
        cout << idx + 1 << '\n';
    }
    else if (n == 0)
    {
        cout << idx << '\n';
    }
    else
    {
        while (j < n)
        {
            if (heights[i] < heights[j])
            {
                idx = j;
                i++;
                j = i + 1;
            }
            else
            {
                j++;
            }
        }
    }
    delete heights;
    cout << idx + 1 << '\n';
}