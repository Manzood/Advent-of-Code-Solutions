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
    while (cin >> s) {
        int a = -1, b = -1;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                if (a == -1) a = s[i] - '0';
                b = s[i] - '0';
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
