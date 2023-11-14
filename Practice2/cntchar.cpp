#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
    int n = 1000;
    char s[n];
    cin >> s;
    vector<int> cnt(26, 0);
    vector<int> cnt1(27, 0);
    for (int i = 0; i < strlen(s); i++)
    {
        cnt[s[i] - 97]++;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        int letter_int = s[i] - 'a'; // ±N¦r¥À¨Ìa ~ z¶¶§ÇÂà´«¬°1 ~ 26
        cnt1[letter_int]++;
    }
    for (auto &x : cnt)
    {
        cout << x << " ";
    }
    cout << "\n";
    for (auto &x : cnt1)
    {
        cout << x << " ";
    }
}