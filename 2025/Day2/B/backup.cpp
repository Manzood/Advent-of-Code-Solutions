#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int concatnum(int num, int other) {
    int mult = 1;
    int cpy = other;
    while (cpy) {
        mult *= 10;
        cpy /= 10;
    }
    return mult * num + other;
}

set<int> counted;
int get(int l, int r) {
    int cur = 1;
    int sum = 0;
    while (true) {
        if (concatnum(cur, cur) > r) break;
        int tmp = cur;
        while (tmp < l) {
            tmp = concatnum(tmp, cur);
        }
        while (tmp <= r) {
            if (!counted.count(tmp) && tmp > 1) {
                sum += tmp;
            }
            counted.insert(tmp);
            tmp = concatnum(tmp, cur);
        }
        cur++;
    }
    return sum;
}

void solve([[maybe_unused]] int test) {
    int a, b;
    char c;
    int ans = 0;
    cin >> a >> c >> b;
    vector<pair<int, int>> inp;
    ans += get(a, b);
    inp.push_back({a, b});
    while (cin >> c) {
        cin >> a >> c >> b;
        ans += get(a, b);
        inp.push_back({a, b});
    }

    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
