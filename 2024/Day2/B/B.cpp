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
        bool found = false;
        for (int j = 0; j < (int)a[i].size(); j++) {
            vector<int> x;
            for (int k = 0; k < (int)a[i].size(); k++) {
                if (k == j) continue;
                x.push_back(a[i][k]);
            }
            bool cur = true;
            for (int k = 1; k < (int)x.size(); k++) {
                if (x[k] - x[k - 1] > 3 || x[k] - x[k - 1] < 1) cur = false;
            }
            found |= cur;
        }
        ans += found;
    }
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < (int)a[i].size(); j++) {
            vector<int> x;
            for (int k = 0; k < (int)a[i].size(); k++) {
                if (k == j) continue;
                x.push_back(a[i][k]);
            }
            bool cur = true;
            for (int k = 1; k < (int)x.size(); k++) {
                if (x[k - 1] - x[k] > 3 || x[k - 1] - x[k] < 1) cur = false;
            }
            found |= cur;
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
