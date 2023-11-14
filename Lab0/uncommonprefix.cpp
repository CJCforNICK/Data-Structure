#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N, count = 0, idx1 = 0, idx2 = 0; // index1 is for the former char, index2 is the latter
    int i;
    cin >> N;
    char s[N];
    for (i = 0; i < N; i++) // i is used in for-loop
    {
        cin >> s[i];
    }
    i = 1; // i is for interval here
    idx2 = idx1 + i;
    for (int j = 0; j < N - 1; j++)
    {
        // cout << "j:" << j << ",i:" << i << endl;
        while (idx2 < N)
        {
            if (s[idx1] == s[idx2])
            {
                break;
            }
            else
            {
                count++;
                idx1 = idx1 + 1;
                idx2 = idx1 + i;
            }
        }
        cout << count << endl;
        i++;
        idx1 = 0;
        idx2 = idx1 + i;
        count = 0;
    }
    return 0;
}
