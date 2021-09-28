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

int partition(vector<int> &nums, int left, int right) {
    int randIndex = rand() % (right - left + 1) + left;
    swap(nums[right], nums[randIndex]);
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot || (nums[j] == pivot && j % 2 == 0)) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

void mySort(vector<int> &nums, int left, int right) {
    if (left >= right) return;

    int pivotIndex = partition(nums, left, right);
    mySort(nums, left, pivotIndex - 1);
    mySort(nums, pivotIndex + 1, right);
}

void solve() {
    srand(time(NULL));
    int n;
    cin>> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin>> nums[i];
    }

    mySort(nums, 0, n - 1);

    for (int i = 0; i < n; i++) {
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