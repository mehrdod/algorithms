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

const ll N = 3e5 + 5, MOD = 998244353;
int TEST_NUM = 1;

using namespace std;

int a[N], fact[N], inv[N];


int add(int a, int b) {
    return (ll(a) + b) % MOD;
}

int mul(int a, int b) {
    return ll(a) * b % MOD;
}

int binpow(int a, int k) {
    int res = 1;
    while (k > 0) {
        if (k & 1) {
            k--;
            res = mul(res, a);
        } else {
            k >>= 1;
            a = mul(a, a);
        }
    }
    return res;
}

void precalc() {
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    inv[N - 1] = binpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 1; i--) {
        inv[i] = mul(inv[i + 1], i+1);
    }
}

int cnk(int n, int k) {
    return  mul(mul(fact[n], inv[n - k]), inv[k]);
}

void solve() {
    precalc();
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