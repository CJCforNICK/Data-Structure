#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
struct loli
{
    // int rank;
    int strength;
    int courage;
};
bool compare2loli(loli a, loli b)
{
    if (a.courage != b.courage)
    {
        return (a.courage > b.courage);
    }
    return (a.strength > b.strength);
}
void computeRanks(vector<loli> &avocado)
{
    sort(avocado.begin(), avocado.end(), compare2loli);

    // assign rank after sortng
    // for (int i = 1; i <= n; i++)
    // {
    //     avocado[i].rank = i;
    // }
}
int main()
{
    int n, M, min;
    cin >> n >> M;
    ll totalstrength = 0;
    min = 0;
    vector<loli> avocado;
    avocado.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int mi, ci;
        cin >> mi >> ci;
        avocado[i].strength = mi;
        avocado[i].courage = ci;
        totalstrength += mi;
    }
    if (totalstrength < M)
    {
        cout << "-1\n";
        return 0;
    }
    computeRanks(avocado);
    // cout << "Rank ";
    // cout << "strength"
    //      << " "
    //      << "courage\n";
    // for (int i = 0; i < n; i++)
    // {
    //     // cout << avocado[i].rank << "    ";
    //     cout << avocado[i].strength << "     ";
    //     cout << avocado[i].courage << "\n";
    // }
    for (int i = 0; i < n; i++)
    {
        if (avocado[i].courage < M)
        {
            cout << "-1\n";
            break;
        }
        M -= avocado[i].strength;
        min++;
        // cout << "current M&min:" << M << " " << min << "\n";
        if (M <= 0)
        {
            cout << min << "\n";
            break;
        }
    }
}