#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct point
{
    int x, y;
} POINT;

typedef struct maze
{
    int color; // 0:white, 1:gray, 2:black
    int predecessor;
    int distance; // 0:start vertex, inf:untouchable
} MAZE;

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void trackBack(vector<vector<MAZE>> &maze, POINT step)
{
    int cnt = maze[step.x][step.y].distance;
    for (int i = 0; i < cnt; i++)
    {
        int dir = maze[step.x][step.y].predecessor;
        switch (dir)
        {
        case UP:
            cout << "U";
            step.x--;
            break;
        case DOWN:
            cout << "D";
            step.x++;
            break;
        case LEFT:
            cout << "L";
            step.y--;
            break;
        case RIGHT:
            cout << "R";
            step.y++;
            break;
        default:
            break;
        }
    }
    cout << endl;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    cout << n;
    vector<vector<MAZE>> maze;
    POINT cur, next, ter;
    bool END = false;
    for (int i = 0; i < n; i++)
    {
        vector<MAZE> temp;
        for (int j = 0; j < m; j++)
        {
            MAZE tmap;
            char x;
            cin >> x;
            if (x == 'B')
            {
                cur.x = i;
                cur.y = j;
                tmap.color = GRAY;
                tmap.distance = 0;
                tmap.predecessor = 0;
            }
            else if (x == '#')
            {
                tmap.color = BLACK;
                tmap.predecessor = 0;
            }
            else if (x == '.')
            {
                tmap.color = WHITE;
                tmap.predecessor = 0;
            }
            else if (x == 'A')
            {
                ter.x = i;
                ter.y = j;
                tmap.color = WHITE;
                tmap.predecessor = 0;
            }
            temp.emplace_back(tmap);
        }
        maze.emplace_back(temp);
        temp.clear();
    }

    queue<POINT> q;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        // cout << cur.x << cur.y << endl;
        q.pop();
        if (cur.x == ter.x && cur.y == ter.y)
        {
            END = true;
            break;
        }
        if (maze[cur.x - 1][cur.y].color == WHITE && cur.x - 1 > 0)
        { // goes up
            next.x = cur.x - 1;
            next.y = cur.y;
            maze[next.x][next.y].color = GRAY; // color gray
            maze[next.x][next.y].distance = maze[cur.x][cur.y].distance + 1;
            maze[next.x][next.y].predecessor = DOWN;
            q.push(next);
        }
        if (maze[cur.x + 1][cur.y].color == WHITE && cur.x + 1 < n)
        { // goes down
            next.x = cur.x + 1;
            next.y = cur.y;
            maze[next.x][next.y].color = GRAY; // color gray
            maze[next.x][next.y].distance = maze[cur.x][cur.y].distance + 1;
            maze[next.x][next.y].predecessor = UP;
            q.push(next);
        }
        if (maze[cur.x][cur.y - 1].color == WHITE && cur.y - 1 > 0)
        { // goes left
            next.x = cur.x;
            next.y = cur.y - 1;
            maze[next.x][next.y].color = GRAY; // color gray
            maze[next.x][next.y].distance = maze[cur.x][cur.y].distance + 1;
            maze[next.x][next.y].predecessor = RIGHT;
            q.push(next);
        }
        if (maze[cur.x][cur.y + 1].color == WHITE && cur.y + 1 < m)
        { // goes right
            next.x = cur.x;
            next.y = cur.y + 1;
            maze[next.x][next.y].color = GRAY; // color gray
            maze[next.x][next.y].distance = maze[cur.x][cur.y].distance + 1;
            maze[next.x][next.y].predecessor = LEFT;
            q.push(next);
        }
        maze[cur.x][cur.y].color = BLACK;
    }
    if (END)
    {
        cout << "YES" << endl;
        cout << maze[cur.x][cur.y].distance << endl;
        trackBack(maze, cur);
    }
    else
    {
        cout << "NO" << endl;
    }
}