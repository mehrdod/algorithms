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

template<typename T1, typename T2>
class two{
public:
    T1 x;
    T2 y;
    two() {};
    two(T1 x, T2 y) {
        this->x = x;
        this->y = y;
    }
    bool operator < (const two &tmp) const {
        if (x == tmp.x) {
            return y < tmp.y;
        }
        return x < tmp.x;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    two<int, int> t1(2, 3);
    auto t2 = two<int, int> (2, 3);

    cout<< t1.x<<' '<< t1.y<< endl;
    cout<< t2.x<<' '<< t2.y;

    return 0;
}