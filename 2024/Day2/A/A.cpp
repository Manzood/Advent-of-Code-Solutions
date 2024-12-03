#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 1000;

void solve([[maybe_unused]] int test) {
    vector<vector<int>> a(N);
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        int num = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == ' ') {
                a[i].push_back(num);
                num = 0;
            } else {
                int val = s[j] - '0';
                num *= 10;
                num += val;
            }
        }
        a[i].push_back(num);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool found = true;
        for (int j = 1; j < (int)a[i].size(); j++) {
            if (a[i][j] - a[i][j - 1] > 3 || a[i][j] - a[i][j - 1] < 1)
                found = false;
        }
        ans += found;
    }
    for (int i = 0; i < N; i++) {
        bool found = true;
        for (int j = 1; j < (int)a[i].size(); j++) {
            if (a[i][j - 1] - a[i][j] > 3 || a[i][j - 1] - a[i][j] < 1)
                found = false;
        }
        ans += found;
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
