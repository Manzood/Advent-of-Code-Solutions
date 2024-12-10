#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 58;

vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int dfs(int i, int j, char val, vector<string>& a, vector<vector<bool>>& vis) {
    int M = (int)a[0].size();
    if (!ok(i, j, N, M) || vis[i][j]) return 0;
    char node = a[i][j];
    if (node != val) return 0;
    vis[i][j] = true;
    if (node == '9') {
        return 1;
    }
    int res = 0;
    for (auto d : dirs) {
        int x = i + d[0], y = j + d[1];
        res += dfs(x, y, node + 1, a, vis);
    }
    return res;
}

void solve([[maybe_unused]] int test) {
    vector<string> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int M = (int)a[0].size();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vector<vector<bool>> vis(N, vector<bool>(M, false));
            if (a[i][j] == '0') {
                ans += dfs(i, j, '0', a, vis);
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
