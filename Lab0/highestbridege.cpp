#include <iostream>
using namespace std;
#define ll long long
int main()
{
    int N, index, j;
    cin >> N;
    ll i = 0;
    int *array = new int[N];
    int temp;
    while (i < N)
    {
        cin >> array[i];
        i++;
    }
    i = 0;
    j = i + 1;
    if (N == 1 || N == 0)
    {
        index = i;
        // cout << "index:" << index + 1 << ",height:" << array[index] << endl;
        cout << index + 1 << endl;
    }
    else
    {
        while (j < N)
        {
            if (array[i] < array[j])
            {
                temp = array[j];
                index = j;
                i = j;
                j = i + 1;
            }
            else
                j++;
        }
        // cout << "index:" << index + 1 << ",height:" << array[index] << endl;
        cout << index + 1 << endl;
    }
    delete array;
    return 0;
}