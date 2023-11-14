#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;
string shuntingyard(string inorder)
{ // switch inorder to postorder, thus return postorder(string)
    map<char, int> priority{
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    stack<char> operationstk;
    string postorder;
    postorder.clear();
    for (auto &i : inorder)
    {
        if (i >= 'A' && i <= 'Z')
        {
            postorder.push_back(i);
        }
        else if (i == '+' || i == '-' || i == '*' || i == '/')
        {
            // cout << "check1";
            while (operationstk.size() && priority[operationstk.top()] >= priority[i] && operationstk.top() != '(') // operationstk.top() != '(' is for ( has no priority
            {
                postorder.push_back(operationstk.top());
                operationstk.pop();
            }
            operationstk.push(i);
        }
        else if (i == '(')
        {
            // cout << "check2";
            operationstk.push(i);
        }
        else if (i == ')')
        {
            // cout << "check3";
            while (operationstk.top() != '(')
            {
                postorder.push_back(operationstk.top());
                operationstk.pop();
            }
            operationstk.pop(); // pop '('
        }
    }
    while (operationstk.size())
    {
        postorder.push_back(operationstk.top());
        operationstk.pop();
    }
    return postorder;
}
int solve(string post)
{
    vector<int> num(5);
    int index;
    num.clear();
    stack<int> newstk; // new stk with number
    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }
    for (auto &i : post)
    {
        if (i >= 'A' && i <= 'Z')
        {
            newstk.push(num[i - 'A']);
        }
        else // the time we see +-*/, we have to calculate, and before calculate we need to store the top two number first
        {
            int b = newstk.top();
            newstk.pop();
            int a = newstk.top();
            newstk.pop();
            if (i == '+')
            {
                newstk.push(a + b);
            }
            else if (i == '-')
            {
                newstk.push(a - b);
            }
            else if (i == '*')
            {
                newstk.push(a * b);
            }
            else
            {
                newstk.push(a / b);
            }
        }
    }
    return newstk.top();
}
int main()
{
    string s;
    int t;
    cin >> s;
    string post = shuntingyard(s);
    cin >> t;
    while (t--)
    {
        cout << solve(post) << "\n";
    }
}