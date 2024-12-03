#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    int ans = 0;
    map<string, int> mp = {{"one", 1},   {"two", 2},   {"three", 3},
                           {"four", 4},  {"five", 5},  {"six", 6},
                           {"seven", 7}, {"eight", 8}, {"nine", 9}};
    while (cin >> s) {
        int a = -1, b = -1;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                if (a == -1) a = s[i] - '0';
                b = s[i] - '0';
            } else {
                for (auto x : mp) {
                    string cur;
                    for (int j = i; j >= 0 && i - j < (int)x.first.size();
                         j--) {
                        cur += s[j];
                    }
                    reverse(cur.begin(), cur.end());
                    if (cur == x.first) {
                        if (a == -1) a = x.second;
                        b = x.second;
                    }
                }
            }
        }
        ans += 10 * a + b;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
