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

class minHeap {
public:
    vector<int> tree;
    minHeap() {}
    minHeap(vector<int> &nums) {
        tree.assign(nums.begin(), nums.end());
        for (int i = 0; i < tree.size(); i++) siftUp(i);
    }
    void siftUp(int i) {
        while (i > 0 && tree[i] < tree[(i - 1) / 2]) {
            swap(tree[i], tree[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void siftDown(int i) {
        int tSize = tree.size();
        int minIdx = i;
        do {
            i = minIdx;
            int left = 2 * i + 1, right = 2 * i + 2;
            if (left < tSize && tree[minIdx] > tree[left]) minIdx = left;
            if (right < tSize && tree[minIdx] > tree[right]) minIdx = right;
            if (minIdx != i) {
                swap(tree[i], tree[minIdx]);
            }
        } while (minIdx != i);
    }
    int popMin() {
        int min = tree[0];
        swap(tree.front(), tree.back());
        tree.pop_back();
        siftDown(0);
        return min;
    }
};

void solve() {
    int n;
    cin>> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin>> nums[i];

    auto heap = minHeap(nums);

    for (int i = 0; i < n; i++) {
        cout<< heap.popMin() <<' ';
    }
    cout<< endl;
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