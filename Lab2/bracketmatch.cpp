#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        vector<char> stack;
        bool iscorrect = true;
        for (char c : s)
        {
            if (c == '(')
            {
                stack.push_back(c);
            }
            else if (c == '[')
            {
                stack.push_back(c);
            }
            else if (c == '{')
            {
                stack.push_back(c);
            }
            else if (c == ')')
            {
                if (stack.empty() || stack.back() != '(')
                {
                    iscorrect = false;
                    break; // break the for loop
                }
                stack.pop_back();
            }
            else if (c == ']')
            {
                if (stack.empty() || stack.back() != '[')
                {
                    iscorrect = false;
                    break; // break the for loop
                }
                stack.pop_back();
            }
            else
            {
                if (stack.empty() || stack.back() != '{')
                {
                    iscorrect = false;
                    break; // break the for loop
                }
                stack.pop_back();
            }
        }
        if (!stack.empty())
            iscorrect = false;
        cout << (iscorrect ? "Y" : "N") << endl;
    }
    return 0;
}