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


typedef long long ll;

const int N = 2e7 + 5;
int TEST_NUM = 1;


using namespace std;

class node {
public:
    ll maxSum, pref, suf, sum;
    node() {}
    node (ll maxSum, ll pref, ll suf, ll sum) : maxSum(maxSum), pref(pref), suf(suf), sum(sum) {}
};

class segTree{
public:
    int size;
    vector<node> tree;
    segTree() {}
    segTree(vector<int> &a) {
        size = 1;
        while (size < a.size()) size *= 2;
        tree.assign(2 * size - 1, node(0, 0, 0, 0));
        for (int i = 0; i < a.size(); i++) {
            set(i, a[i]);
        }
    }
    void set (int i, int val) {
        set(i, val, 0, 0, size);
    }
    void set(int i, int val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = node(val, val, val, val);
            return;
        }
        int m = (lx + rx) / 2;
        int leftCh = 2 * x + 1;
        int rightCh = 2 * x + 2;
        if (i < m) {
            set(i, val, leftCh, lx, m);
        } else {
            set(i, val, rightCh, m, rx);
        }
        tree[x] = join(tree[leftCh], tree[rightCh]);
    }

    ll subMax(int l, int r) {
        return subMax(l, r, 0, 0, size).maxSum;
    }
    node subMax(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return node(0, 0 , 0 , 0);
        }
        if (l <= lx && rx <= r) {
            return tree[x];
        }
        int m = (lx + rx) / 2;

        return join(subMax(l, r, 2 * x + 1, lx, m), subMax(l, r, 2 * x + 2, m, rx));
    }
    node join(const node &a, const node &b) {
        node res;
        res.maxSum = max(a.maxSum, b.maxSum);
        res.maxSum = max(res.maxSum, a.suf + b.pref);
        res.pref = max(a.pref, a.sum + b.pref);
        res.suf = max(b.suf, b.sum + a.suf);
        res.sum = a.sum + b.sum;
        return res;
    }
};

void solve() {
    int n, m;
    cin>> n>> m;
    vector<int> a(n);
    for (int &val: a) cin>> val;

    segTree sT = segTree(a);

    cout<< sT.subMax(0, a.size())<< endl;

    for (int i = 0; i < m; i++) {
        int j, v;
        cin>> j>> v;
        sT.set(j, v);
        cout<< sT.subMax(0, a.size())<< endl;
    }
}

int main(){
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