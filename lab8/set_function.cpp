#include <set>
#include <iostream>
using namespace std;
int main()
{
    set<int> s;
    multiset<int> s1;
    for (int i = 0; i <= 5; i++)
    {
        s1.insert(i * 2);
        s1.insert(i * 3);
        s.insert(i * 2);
    }
    for (auto x : s1)
    {
        cout << x << " ";
    }
    for (int i = 0; i <= s.size(); i++)
    {
        if (s.count(i) == 1) // cuz is set each number occurence found is 1, unfound 0
        {
            cout << i << " yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    for (int j = 0; j <= s.size(); j++)
    {
        if (s.find(j) != s.end())
        {
            cout << j << " yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    for (int i = 0; i <= s.size(); i++)
    {
        if (s1.count(i) == 2) // cuz is set each number occurence found is 1, unfound 0
        {
            cout << i << " yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}