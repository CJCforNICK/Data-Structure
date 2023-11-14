#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <set>
using namespace std;

#define pll pair<long long, long long>

int main()
{
    long long N = 0, K = 0;
    cin >> N >> K;
    vector<long long> startTime(N + 1);                    // only for recording
    multiset<long long, greater<long long>> studentLog;    // all K students ending time log
    priority_queue<pll, vector<pll>, greater<pll>> period; // course <end, start> time table, from early end to last end

    for (int id = 1; id <= K; id++)
        studentLog.insert(-1); //  student<last end time, student id>

    for (long long i = 0; i < N; i++)
        cin >> startTime[i];
    for (long long i = 0; i < N; i++)
    {
        long long finish = 0;
        cin >> finish;
        period.push(make_pair(finish, startTime[i]));
    }

    long long cnt = 0; // count for max course

    while (!period.empty())
    {
        long long nxtStart = period.top().second; // next start course with earliest ending time
                                                  // printf("%d~%d\n",period.top().second,period.top().first);
        for (auto &it : studentLog)
        {
            if (it < nxtStart)
            {
                // printf("student with old end time = %d get the course, and new start time is %d",it,nxtStart);
                studentLog.erase(studentLog.find(it));
                studentLog.insert(period.top().first);
                cnt++;
                // printf(", renew the end time to %d\n",period.top().first);
                break;
            }
        }
        period.pop();
    }
    cout << cnt << endl;

    return 0;
}