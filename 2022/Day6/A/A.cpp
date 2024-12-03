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
    cin >> s;
    int ans = (int)s.size();
    for (int i = 13; i < (int)s.size(); i++) {
        set<char> st;
        for (int j = 0; j < 14; j++) {
            st.insert(s[i - j]);
        }
        if ((int)st.size() == 14) {
            ans = min(ans, i + 1);
        }
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
