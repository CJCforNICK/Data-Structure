#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        stack<char> stk;
        string s;
        cin >> s;
        for (char c : s)
        {
            if (c == '(')
            {
                stk.push(c);
            }
            else if (c == '[')
            {
                stk.push(c);
            }
            else if (c == ')')
            {
                if (!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (!stk.empty() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    break;
                }
            }
        }
        if (stk.empty())
            cout << "Y\n";
        else
            cout << "N\n";
    }
}