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
    if (right <= left)
        return;
    int mid = (left + right) / 2;
    mySort(nums, left, mid);
    mySort(nums, mid + 1, right);
    vector<int> unite(right - left + 1);
    int uniteLen = 0, i = left, j = mid + 1;
    while (uniteLen < right - left + 1) {
        if (j > right) {
            unite[uniteLen] = nums[i];
            i++;
            uniteLen++;
            continue;
        }
        if (i > mid) {
            unite[uniteLen] = nums[j];
            j++;
            uniteLen++;
            continue;
        }
        if (nums[i] < nums[j]) {
            unite[uniteLen] = nums[i];
            i++;
        } else {
            unite[uniteLen] = nums[j];
            j++;
        }
        uniteLen++;
    }
    for (int i = 0; i < unite.size(); i++) {
        nums[i + left] = unite[i];
    }
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