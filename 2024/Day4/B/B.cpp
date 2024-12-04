#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void solve([[maybe_unused]] int test) {
    vector<string> a;
    string s;
    while (getline(cin, s)) {
        a.push_back(s);
    }
    int n = (int)a.size(), m = (int)a[0].size();
    string sam = "SAM", mas = "MAS";
    vector<vector<string>> targets;
    for (int i = 0; i < 4; i++) {
        string x = sam, y = mas;
        if (i & 1) reverse(x.begin(), x.end());
        if (i & 2) reverse(y.begin(), y.end());
        vector<string> cur;
        for (int j = 0; j < 3; j++) {
            string tmp;
            for (int k = 0; k < 3; k++) {
                if (j == k) {
                    tmp += x[j];
                } else if (j + k == 2) {
                    tmp += y[j];
                } else {
                    tmp += '.';
                }
            }
            cur.push_back(tmp);
        }
        targets.push_back(cur);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool found = false;
            for (auto target : targets) {
                bool cur = true;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (!ok(i + x, j + y, n, m)) {
                            cur = false;
                            break;
                        }
                        if (target[x][y] == '.') continue;
                        if (a[i + x][j + y] != target[x][y]) {
                            cur = false;
                        }
                    }
                }
                if (cur) {
                    found = true;
                    break;
                }
            }
            ans += found;
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
