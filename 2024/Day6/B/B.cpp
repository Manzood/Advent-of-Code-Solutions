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
    vector<vector<vector<bool>>> marked(
        N, vector<vector<bool>>(M, vector<bool>(4, false)));
    vector<vector<bool>> obstructions(N, vector<bool>(M, false));
    int ans = 0;
    while (ok(cur.first, cur.second, N, M)) {
        int x = cur.first + dirs[ind].first, y = cur.second + dirs[ind].second;
        if (ok(x, y, N, M) && a[x][y] != '#') {
            int nxt = (ind + 1) % 4;
            pair<int, int> tmp = {cur.first, cur.second};
            bool shouldTurn = false;
            pair<int, int> startPoint = tmp;
            vector<vector<vector<bool>>> tmpMarked(
                N, vector<vector<bool>>(M, vector<bool>(4, false)));
            while (ok(tmp.first, tmp.second, N, M) && !shouldTurn) {
                if (marked[tmp.first][tmp.second][nxt]) shouldTurn = true;
                int v = tmp.first + dirs[nxt].first,
                    w = tmp.second + dirs[nxt].second;
                while (ok(v, w, N, M) && a[v][w] == '#') {
                    nxt = (nxt + 1) % 4;
                    v = tmp.first + dirs[nxt].first,
                    w = tmp.second + dirs[nxt].second;
                }
                tmp = {v, w};
                if (tmp == startPoint) shouldTurn = true;
            }
            if (shouldTurn) {
                bool blocksPreviousPath = false;
                for (int i = 0; i < 4; i++) {
                    if (marked[x][y][i] == true) blocksPreviousPath = true;
                }
                if (!blocksPreviousPath) ans++;
            }
        }
        marked[cur.first][cur.second][ind] = true;
        while (ok(x, y, N, M) && a[x][y] == '#') {
            ind = (ind + 1) % 4;
            x = cur.first + dirs[ind].first, y = cur.second + dirs[ind].second;
        }
        cur = {x, y};
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
