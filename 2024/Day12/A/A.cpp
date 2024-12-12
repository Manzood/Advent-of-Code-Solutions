#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 140;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

pair<int, int> dfs(int i, int j, vector<string>& a, vector<vector<bool>>& vis) {
    pair<int, int> ret = {0, 0};
    int M = (int)a[0].size();
    if (vis[i][j] || !ok(i, j, N, M)) return ret;
    vis[i][j] = true;
    ret.first += 1;
    for (auto d : dirs) {
        int x = i + d[0], y = j + d[1];
        if (!ok(x, y, N, M) || a[x][y] != a[i][j]) {
            ret.second++;
        } else if (ok(x, y, N, M)) {
            pair<int, int> val = dfs(x, y, a, vis);
            ret.first += val.first, ret.second += val.second;
        }
    }
    return ret;
}

void solve([[maybe_unused]] int test) {
    vector<string> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int M = (int)a[0].size();
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j]) {
                pair<int, int> ret = dfs(i, j, a, vis);
                ans += ret.first * ret.second;
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
