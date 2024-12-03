#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s[3];
    int sum = 0;
    while (cin >> s[0]) {
        cin >> s[1];
        cin >> s[2];
        vector<vector<bool>> c(3, vector<bool>(200, false));
        for (int i = 0; i < 3; i++) {
            int n = s[i].size();
            for (int j = 0; j < n; j++) {
                c[i][s[i][j]] = true;
            }
        }
        char repeat = 'a';
        for (int i = 0; i < 200; i++) {
            if (c[0][i] && c[1][i] && c[2][i]) {
                repeat = (char)i;
            }
        }
        int ans = 0;
        if (islower(repeat)) {
            ans = 1 + repeat - 'a';
        } else {
            ans = 27 + repeat - 'A';
        }
        sum += ans;
    }
    printf("%lld\n", sum);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
