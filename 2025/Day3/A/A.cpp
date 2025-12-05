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
    while (getline(cin, s)) {
        string out = "00";
        for (int i = 0; i < (int)s.size() - 1; i++) {
            for (int j = i + 1; j < (int)s.size(); j++) {
                string cur;
                cur += s[i];
                cur += s[j];
                if (cur > out) {
                    out = cur;
                }
            }
        }
        ans += stoi(out);
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
