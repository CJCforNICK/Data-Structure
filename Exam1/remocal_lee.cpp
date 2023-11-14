#include <iostream>
#include <vector>
using namespace std;
const long long int MAX = 1e100;

string strS, strT;

bool find(vector<int> &indices, int end, int m)
{
    vector<bool> del(m + 1, false);
    // cout << "remove indices from 0 to " << end << endl;
    for (int i = 0; i <= end; i++)
        del[indices[i] - 1] = true;
    del[m] = true;
    // for(int i = 0; i < m; i++){
    //     if(del[i]) cout << "_ ";
    //     else cout << strT[i] << " ";
    // }
    //  cout << endl;
    int cur = 0;

    for (int i = 0; i < strS.length(); i++)
    {
        while (del[cur])
        {
            cur++;
            if (cur == m)
                return true;
        }
        if (strT[cur] == strS[i])
            cur++; // find matched char
        if (cur == m)
            return true;
    }
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cin >> strS;
    cin >> strT;
    vector<int> indices(m + 1);
    for (int i = 0; i < m; i++)
        cin >> indices[i];
    int left = 0, right = m - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        // cout << "left=" << left << " mid="  << mid << " right=" << right << endl;
        if (find(indices, mid, m))
        {
            // cout << "**find seq" << endl;
            right = mid;
        }
        else
            left = mid + 1;
    }
    cout << left + 1 << endl;
}