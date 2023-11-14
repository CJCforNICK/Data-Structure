#include <iostream>
#include <vector>
using namespace std;
vector<int> candyqty;
bool traversal(int ppl, int x)
{ // x , ppl is m
    int needofmen = 0;
    for (auto &y : candyqty)
    {
        if (y % x == 0)
        {
            needofmen = needofmen + (y / x);
        }
        else
        {
            needofmen = needofmen + (y / x + 1);
        }
    }
    if (needofmen > ppl)
        return false;
    else
        return true;
}
int bSearch(int ppl, int candymax)
{
    int l = 1, mid, r = candymax;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (traversal(ppl, mid)) // mid is x
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    return r;
}
int main()
{
    int n, m, least;
    cin >> n >> m;
    int candymax = 0;
    for (int i = 0; i < n; i++)
    { // build the candyqty vector
        int candynum = 0;
        cin >> candynum;
        if (candynum > candymax)
            candymax = candynum;
        candyqty.push_back(candynum);
    }
    least = bSearch(m, candymax);
    cout << least << "\n";
}