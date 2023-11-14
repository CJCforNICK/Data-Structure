#include <iostream>
using namespace std;
void pluss(int &count)
{
    count++;
}
int main()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        pluss(count);
    }
    cout << "count:" << count << endl;
}