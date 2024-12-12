#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 8;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> res;
    for (int run = 0; run < 25; run++) {
        res.clear();
        n = (int)a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                res.push_back(1);
            } else if (to_string(a[i]).size() & 1) {
                assert(a[i] < (int)1e15 + 5e14);
                res.push_back(a[i] * 2024);
            } else {
                string cur = to_string(a[i]);
                string f = cur.substr(0, cur.size() / 2),
                       s = cur.substr(cur.size() / 2);
                int x = 0, y = 0;
                for (auto digit : f) {
                    x *= 10;
                    x += digit - '0';
                }
                for (auto digit : s) {
                    y *= 10;
                    y += digit - '0';
                }
                res.push_back(x);
                res.push_back(y);
            }
        }
        a = res;
    }
    printf("%lld\n", (int)res.size());
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
