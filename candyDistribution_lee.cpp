#include<iostream>
#include<vector>
using namespace std;
vector<int>candy;


bool candyTraversal(int num,int people){
    int neededMan = 0;
    for(auto &y:candy){
        if(y % num == 0)
            neededMan += y / num;
        else
            neededMan += (y / num + 1);
    }
    if(neededMan > people) return false;
    else return true;
}

int binarySearch(int people,int CandyMax){
    int left = 1,right = CandyMax;           // lower bound
    while(left < right){
        int mid = (left + right)/2;
        if(candyTraversal(mid,people))  right = mid;
        else left = mid + 1;
    }
    return right;
}

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int CandyMax = 0;
    for (int j = 0; j < n; j++) {
        int num = 0;
        cin >> num;
        if(CandyMax < num) CandyMax = num;
        candy.push_back(num);
    }
    int ans = binarySearch(m,CandyMax);
    cout << ans << endl;
    return 0;
}