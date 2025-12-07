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
    int n = (int)a.size();
    int m = (int)a[0].size();
    vector<vector<int>> deg(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') {
                for (auto d : dirs) {
                    if (ok(i + d.first, j + d.second, n, m) &&
                        a[i + d.first][j + d.second] == '@') {
                        deg[i][j]++;
                    }
                }
            }
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@' && deg[i][j] < 4) q.push({i, j});
        }
    }
    int ans = 0;
    while (!q.empty()) {
        ans++;
        pair<int, int> cur = q.front();
        q.pop();
        for (auto d : dirs) {
            if (ok(cur.first + d.first, cur.second + d.second, n, m) &&
                a[cur.first + d.first][cur.second + d.second] == '@') {
                deg[cur.first + d.first][cur.second + d.second]--;
                if (deg[cur.first + d.first][cur.second + d.second] == 3) {
                    q.push({cur.first + d.first, cur.second + d.second});
                }
            }
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
