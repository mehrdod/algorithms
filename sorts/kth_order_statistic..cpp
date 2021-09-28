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
int TEST_NUM = 100;


using namespace std;

void printNums(vector<int> &nums) {
    for (auto num : nums) {
        cout<< num<<' ';
    }
    cout<< endl;
}

int partition(vector<int> &nums, int left, int right) {
    int randIndex = rand() % (right - left + 1) + left;
    swap(nums[right], nums[randIndex]);
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot || (nums[j] == pivot && rand() % 2 == 0)) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

int getKth(vector<int> &nums, int left, int right, int k) {
    if (right == left) {
        return nums[left];
    }

    int pivotIndex = partition(nums, left, right);
    if (pivotIndex - left == k) {
        return nums[pivotIndex];
    }
    if (pivotIndex - left > k) {
        return getKth(nums, left, pivotIndex - 1, k);
    } else {
        return getKth(nums, pivotIndex + 1, right, k - (pivotIndex - left + 1));
    }
}

void solve() {
    int n = rand() % 100 + 100000;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++) nums[i] = rand();

    //printNums(nums);
    int k = rand() % nums.size();
    int k1 = getKth(nums, 0, nums.size() - 1, k);
    sort(nums.begin(), nums.end());
    if (k1 != nums[k]) {
        cout<< k1<<' '<< nums[k]<< endl;
        //printNums(nums);
    }


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    while (TEST_NUM--){
        solve();
    }
    return 0;
}