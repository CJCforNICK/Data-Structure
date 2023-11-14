#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define ll long long
#define pii pair<int, int>
using namespace std;
priority_queue<int> attackable;
// struct loli
// {
//     // int rank;
//     int strength;
//     int courage;
//     loli(int strength, int courage)
//         : strength(strength), courage(courage) {}
// };
priority_queue<pii> nonattack;
int main()
{
    int n, M, min;
    cin >> n >> M;
    ll totalstrength = 0;
    min = 0;
    for (int i = 0; i < n; i++)
    {
        int mi, ci;
        cin >> mi >> ci;
        if (ci >= M) // original attackable
        {
            attackable.push(mi);
        }
        else
        {
            nonattack.push({ci, mi});
        }
        totalstrength += mi;
    }
    cout << "attackable:";
    while (!attackable.empty())
    {
        cout << attackable.top() << " ";
        attackable.pop();
    }
    cout << "\nnonattack:";
    while (!nonattack.empty())
    {
        pii top = nonattack.top();
        cout << top.first << " " << top.second << ", ";
        nonattack.pop();
    }
    cout << "\n";
    if (totalstrength < M)
    {
        cout << "-1\n";
        return 0;
    }
    while (M > 0)
    {
        if (attackable.empty())
        {
            cout << "-1\n";
            return 0;
        }
        else
        {
            int u = attackable.top();
            attackable.pop();
            min++;
            M = M - u;
            while (!nonattack.empty() && nonattack.top().first >= M)
            {
                cout << "push" << nonattack.top().second;
                attackable.push(nonattack.top().second);
                nonattack.pop();
            }
        }
    }
    if (M <= 0)
    {
        cout << min << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}