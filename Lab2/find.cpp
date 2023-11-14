#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int N;
    cin >> N;
    vector<int>::iterator it = std::find(v.begin(), v.end(), N); // find 10
    if (it != v.end())
        cout << "found " << *it << ", index: " << std::distance(v.begin(), it) + 1 << "\n";
    else
        cout << "not find\n";

    return 0;
}