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

const int N = 1e3 + 5;
int TEST_NUM = 1;


using namespace std;

template<typename T1>
class segTree {
public:
    vector<T1> tree;
    int size;
    segTree() {}
    segTree(const vector<T1> &v) {
        size = 1;
        while (size < v.size()) size *= 2;
        tree.assign(2 * size - 1, 0);

        for (int i=0; i<v.size(); i++) set(i, v[i]);
    }
    void set(int i, T1 val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, val, 2 * x + 1, lx,  m);
        } else {
            set(i, val, 2 * x + 2, m, rx);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(int i, T1 val) {
        set(i, val, 0, 0, size);
    }
    T1 sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
    T1 sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        T1 s1 = sum(l, r, 2 * x + 1, lx, m);
        T1 s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }
};

void solve() {
    int n, m;
    cin>> n>> m;
    vector<ll> a(n);
    for (ll &val : a) cin>> val;

    segTree<ll> sT = segTree(a);

    for (int i=0; i<m; i++) {
        int cmd;
        cin>> cmd;
        if (cmd  == 2) {
            int l, r;
            cin>> l>> r;
            cout<< sT.sum(l, r) << endl;
        } else {
            int i, v;
            cin>> i>> v;
            sT.set(i, v);
        }
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