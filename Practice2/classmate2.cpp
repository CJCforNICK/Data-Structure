#include <iostream>
#include <vector>
#include <set>
using namespace std;
using LL = long long int;

LL get_hash_val(LL l, LL r, LL M, LL n, vector<LL> &pw, vector<LL> &hash)
{
    return (((hash[r] - hash[l - 1]) % M * pw[n - l + 1]) % M + M) % M;
}

bool is_permutation(const int cnt[])
{
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
            return false;
    }
    return true;
}

int main()
{
    string N, H;
    LL x = 37, M = 1e9 + 7, l, r, n;
    cin >> N; // find its permutations in H
    cin >> H;
    n = H.size();
    vector<LL> pw(200001, 1);
    vector<LL> hash(H.size(), 0);
    set<LL> allValue;
    int cnt[27] = {0};
    for (LL i = 1; i <= 200000; i++)
    { // 產生power
        pw[i] = pw[i - 1] * x % M;
    }

    for (LL i = 1; i <= H.size(); i++)
    {                                                   // 產生hash table of H string range
        hash[i] = (hash[i - 1] + H[i] * pw[i] % M) % M; // hash[i]=>H 0~i hash value
    }
    for (int i = 0; i < N.size(); i++)
    {
        int letter_int = N[i] - 'a' + 1; // 將字母依a ~ z順序轉換為1 ~ 26
        cnt[letter_int]++;
    }

    l = 0;
    r = N.size() - 1;
    for (LL k = l; k <= r; k++)
    {
        int temp = H[k] - 'a' + 1;
        cnt[temp]--;
    }

    while (r < H.size())
    {
        if (is_permutation(cnt))
        {
            allValue.emplace(get_hash_val(l + 1, r, M, n, pw, hash));
        }
        int temp_ = H[l] - 'a' + 1;
        cnt[temp_]++;
        l++;
        r++;
        if (r >= H.size())
            break;
        temp_ = H[r] - 'a' + 1;
        cnt[temp_]--;
    }
    cout << allValue.size();

    int ans = 1;
    if (allValue.size() > 0)
    {
        sort(allValue.begin(), allValue.end());

        for (int i = 1; i < allValue.size(); i++)
        {
            if (allValue[i] != allValue[i - 1])
            {
                ans++;
            }
        }
    }
    else
    {
        ans = 0;
    }

    cout << ans;
}