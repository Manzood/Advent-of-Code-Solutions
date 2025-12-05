#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(int num) {
    int val = 1;
    for (int i = 0; i < num; i++) val *= 10;
    return val;
}

const int MX = 13;

void solve([[maybe_unused]] int test) {
    string s;
    int ans = 0;
    while (getline(cin, s)) {
        string out = "0";
        int n = (int)s.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(MX, 0)));
        dp[0][0][1] = (long long)s[0] - '0';
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            dp[i][i][1] = max(dp[i][i][1], (long long)s[i] - '0');
            for (int j = i - 1; j >= 0; j--) {
                dp[i][j][1] = max(dp[i][j][1], (long long)s[i] - '0');
                for (int x = 2; x < MX; x++) {
                    if (j > 0) {
                        dp[i][j][x] =
                            max(dp[i][j][x], get(x) * dp[j - 1][0][MX - x] +
                                                 10 * dp[i - 1][j][x - 1] +
                                                 s[i] - '0');
                    } else {
                        dp[i][j][x] = max(
                            dp[i][j][x], 10 * dp[i - 1][j][x - 1] + s[i] - '0');
                    }
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < MX; i++) mx = max(mx, dp[n - 1][0][i]);
        ans += mx;
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
