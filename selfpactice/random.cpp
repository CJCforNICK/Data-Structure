#include <iostream>
#include <time.h>
#include <random>
using namespace std;
int main()
{
    int i;
    unsigned seed;
    srand(time(NULL)); // ���o�ɶ��ǦC
    if (rand() % 2 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}