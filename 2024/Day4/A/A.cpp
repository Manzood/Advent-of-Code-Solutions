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
    string xmas = "XMAS", samx = "SAMX";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto d : dirs) {
                string cur;
                int x = i, y = j;
                for (int k = 0; k < 4; k++) {
                    if (ok(x, y, n, m)) {
                        cur += a[x][y];
                    }
                    x += d.first, y += d.second;
                }
                if (cur == xmas || cur == samx) {
                    ans++;
                }
            }
        }
    }
    if (ans & 1) printf("Odd\n");
    printf("%lld\n", ans / 2);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
