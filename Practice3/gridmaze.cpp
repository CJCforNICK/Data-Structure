#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
vector<vector<char>> maze;
vector<vector<int>> dis;
int n, m;
struct path
{
    int row;
    int column;
    path(int row, int column)
        : row(row), column(column){};
};
queue<path> q;
stack<char> stk;
int bfs(int row, int column, int b_i, int b_j)
{
    dis[row][column] = 0;
    // cout << dis[1][2] << "1";
    q.push(path{row, column});
    while (q.size())
    {
        int u_i = q.front().row;
        int u_j = q.front().column;
        q.pop();
        if ((u_i - 1) >= 0) // up
        {
            if (dis[u_i - 1][u_j] == -1)
            {
                if (maze[u_i - 1][u_j] == 'B')
                {
                    return dis[u_i][u_j] + 1;
                }
                else if (maze[u_i - 1][u_j] == '.')
                {
                    dis[u_i - 1][u_j] = dis[u_i][u_j] + 1;
                    // cout << u_i - 1 << " " << u_j << ",";
                    q.push(path{u_i - 1, u_j});
                }
            }
        }
        if ((u_j - 1) >= 0) // left
        {
            if (dis[u_i][u_j - 1] == -1)
            {
                if (maze[u_i][u_j - 1] == 'B')
                {
                    return dis[u_i][u_j] + 1;
                }
                else if (maze[u_i][u_j - 1] == '.')
                {
                    dis[u_i][u_j - 1] = dis[u_i][u_j] + 1;
                    // cout << u_i << " " << u_j - 1 << ",";
                    q.push(path{u_i, u_j - 1});
                }
            }
        }
        if ((u_i + 1) < n) // down
        {
            if (dis[u_i + 1][u_j] == -1)
            {
                if (maze[u_i + 1][u_j] == 'B')
                {
                    return dis[u_i][u_j] + 1;
                }
                else if (maze[u_i + 1][u_j] == '.')
                {
                    dis[u_i + 1][u_j] = dis[u_i][u_j] + 1;
                    // cout << u_i + 1 << " " << u_j << ",";
                    q.push(path{u_i + 1, u_j});
                }
            }
        }
        if ((u_j + 1) < m) // right
        {
            if (dis[u_i][u_j + 1] == -1)
            {
                if (maze[u_i][u_j + 1] == 'B')
                {
                    return dis[u_i][u_j] + 1;
                }
                else if (maze[u_i][u_j + 1] == '.')
                {
                    dis[u_i][u_j + 1] = dis[u_i][u_j] + 1;
                    // cout << u_i << " " << u_j - 1 << "\n";
                    q.push(path{u_i, u_j + 1});
                }
            }
        }
    }
    return -1;
}
void findthepath(int b_i, int b_j, int min)
{
    if (dis[b_i][b_j] != 0)
    {
        if ((b_i - 1) >= 0)
        {
            if (dis[b_i - 1][b_j] == (min - 1)) // for b is up, store down
            {
                stk.push('D');
                min -= 1;
                // cout << min;
                findthepath(b_i - 1, b_j, min);
                return;
            }
        }
        if (b_i + 1 < n)
        {
            if (dis[b_i + 1][b_j] == (min - 1)) // for b is down, store up
            {
                stk.push('U');
                min -= 1;
                // cout << min;
                findthepath(b_i + 1, b_j, min);
                return;
            }
        }
        if (b_j - 1 >= 0)
        {
            if (dis[b_i][b_j - 1] == (min - 1)) // for b is left, store right
            {
                stk.push('R');
                min -= 1;
                // cout << min;
                findthepath(b_i, b_j - 1, min);
                return;
            }
        }
        if (b_j + 1 < m)
        {
            if (dis[b_i][b_j + 1] == (min - 1)) // for b is right, store left
            {
                stk.push('L');
                min -= 1;
                // cout << min;
                findthepath(b_i, b_j + 1, min);
                return;
            }
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a_i, a_j, b_i, b_j;
    char x;
    cin >> n >> m;
    dis.resize(n, vector<int>(m, -1)); // initialize the 2-D maze to store distance
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dis[i][j];
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < n; i++) // build the 2-D maze
    {
        vector<char> temp;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            temp.emplace_back(x);
            if (x == 'A')
            {
                a_i = i;
                a_j = j;
            }
            if (x == 'B')
            {
                b_i = i;
                b_j = j;
            }
        }
        maze.push_back(temp);
        temp.clear();
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << maze[i][j];
    //     }
    //     cout << '\n';
    // }
    int mindis = bfs(a_i, a_j, b_i, b_j);
    if (mindis == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n"
             << mindis << "\n";
        findthepath(b_i, b_j, mindis);
        // cout << stk.size() << "\n";
        while (!stk.empty())
        {
            cout << stk.top();
            stk.pop();
            // cout << stk.size() << "\n";
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
}