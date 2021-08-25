#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define bug(x) cerr << #x << " = " << x << endl
#define bugf(x) cerr << x << " "
#define bugl() cerr << endl
#define couts(x) cout << x << " "
#define coutl(x) cout << x << "\n"
#define endl '\n'
#define int long long


typedef long long ll;

const int N = 1e3 + 5;
int TEST_NUM = 1;

using namespace std;

void mySort(vector<int> &nums, int left, int right) {
    int pivot = nums[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (nums[i] < pivot) i++;
        while (nums[j] > pivot) j--;
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    if (i < right) mySort(nums, i, right);
    if (left < j) mySort(nums, left, j);
}

void solve() {
    int n;
    cin>> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>> nums[i];
    }
    mySort(nums, 0, nums.size() - 1);
    for (int i =0 ; i < n; i++) {
        cout<< nums[i]<<' ';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    while (TEST_NUM--){
        solve();
    }
    return 0;
}