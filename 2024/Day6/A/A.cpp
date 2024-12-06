#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int N = 130;

bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void solve([[maybe_unused]] int test) {
    vector<string> a(N);
    pair<int, int> cur;
    int M;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        M = (int)a[i].size();
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '^') cur = {i, j};
        }
    }
    int ind = 0;
    vector<vector<bool>> marked(N, vector<bool>(M, false));
    while (ok(cur.first, cur.second, N, M)) {
        marked[cur.first][cur.second] = true;
        int x = cur.first + dirs[ind].first, y = cur.second + dirs[ind].second;
        while (ok(x, y, N, M) && a[x][y] == '#') {
            ind++;
            if (ind == 4) ind = 0;
            x = cur.first + dirs[ind].first, y = cur.second + dirs[ind].second;
        }
        cur = {x, y};
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != '#' && marked[i][j]) ans++;
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
