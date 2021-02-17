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

class StringHash {
    long long M = 1e9 + 9;
    int P = 31;

    int add(int a, int b) {
        return (ll(a) + b) % M;
    }

    int mul(int a, int b) {
        return ll(a) * b % M;
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


public:
    string str;
    vector<long long> hashs;
    vector<long long> pows;
    vector<long long> invs;

    StringHash() {};
    StringHash(string s) : str(s) {
        hashs.resize(s.size());
        powsCalculate(N);
        invsCalculate(N);
        hashCalculate();
    }
    void powsCalculate(int n) {
        pows.resize(max((int) str.size(), n));
        pows[0] = 1;
        for (int i=1; i<pows.size(); i++) {
            pows[i] = (pows[i-1] * P) % M;
        }
    }
    void invsCalculate(int n) {
        invs.resize(max((int) str.size(), n));
        invs[invs.size() - 1] = binpow(pows[invs.size() - 1], M - 2);
        for (int i=invs.size() - 2; i >= 0; i--) {
            invs[i]  = (invs[i+1] * P) % M;
        }
    }
    void hashCalculate() {
        hashs[0] = (str[0] - 'a' + 1) * pows[0];
        for (int i=1; i<str.size(); i++) {
            hashs[i] = (hashs[i-1] + (str[i] - 'a' + 1) * pows[i]) % M;
        }
    }
    int subHash(int i, int j) {
        if (i != 0)
            return ((hashs[j] - hashs[i-1] + M) * invs[i]) % M;
        return hashs[j];
    }
};

void solve() {
    string s, mask;
    int dp[2000];
    int k;
    cin>> s>> mask>> k;
    dp[0] = (mask[s[0] -'a'] == '0');
    for (int i=1; i<s.size(); i++) {
        dp[i] = dp[i-1] + (mask[s[i] -'a'] == '0');
    }
    StringHash h(s);
    set<int> unq;
    int ans = 0;
    for (int i=0; i<h.str.size(); i++) {
        for (int j=i; j<h.str.size(); j++) {
            int sz = unq.size();
            unq.insert(h.subHash(i, j));
            int bads = dp[j] - dp[i] + (mask[s[i] -'a'] == '0');
            if (sz != unq.size() && bads <= k) {
                // cout<< s.substr(i, j+1)<< endl;
                ans++;
            }
        }
    }
    cout<< ans<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    TEST_NUM = 1;
    while (TEST_NUM--){
        solve();
    }
    return 0;
}