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
    long long P = 37;
public:
    string str;
    vector<long long> hashs;
    vector<long long> pows;

    StringHash() {};
    StringHash(string s) : str(s) {
        hashs.resize(s.size());
        powsCalculate(N);
        hashCalculate();
    }
    void powsCalculate(int n) {
        pows.resize(max((int) str.size(), n));
        pows[0] = 1;
        for (int i=1; i<pows.size(); i++) {
            pows[i] = pows[i-1] * P;
        }
    }

    void hashCalculate() {
        hashs[0] = (str[0] - 'a' + 1) * pows[0];
        for (int i=1; i<str.size(); i++) {
            hashs[i] = (hashs[i-1] + (str[i] - 'a' + 1) * pows[i]);
        }
    }
    long long subHash(int i, int j) {
        if (i != 0)
            return ((hashs[j] - hashs[i-1]) * pows[str.size() - i]);
        return hashs[j] * pows[str.size() - i];
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

    set<long long> unq;
    int ans = 0;
    for (int i=0; i<h.str.size(); i++) {
        for (int j=i; j<h.str.size(); j++) {
            int sz = unq.size();
            unq.insert(h.subHash(i, j));
            int bads = dp[j] - dp[i] + (mask[s[i] -'a'] == '0');
            if (sz != unq.size() && bads <= k) {
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