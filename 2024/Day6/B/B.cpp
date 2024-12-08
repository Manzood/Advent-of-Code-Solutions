#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int N = 130;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

pair<int, int> getNext(pair<int, int> cur, int ind) {
    return {cur.first + dirs[ind].first, cur.second + dirs[ind].second};
}

bool hasLoop(int x, int y, int ind, vector<string>& a) {
    int n = (int)a.size(), m = (int)a[0].size();
    vector<vector<vector<bool>>> vis(
        n, vector<vector<bool>>(m, vector<bool>(4, false)));
    while (ok(x, y, n, m)) {
        if (vis[x][y][ind]) return true;
        vis[x][y][ind] = true;
        pair<int, int> nxt = getNext({x, y}, ind);
        while (ok(nxt.first, nxt.second, n, m) &&
               a[nxt.first][nxt.second] == '#') {
            ind = (ind + 1) % 4;
            nxt = getNext({x, y}, ind);
        }
        x = nxt.first, y = nxt.second;
    }
    return false;
}

void solve([[maybe_unused]] int test) {
    vector<string> a(N);
    pair<int, int> cur;
    int M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        M = (int)a[i].size();
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '^') cur = {i, j};
        }
    }
    int ind = 0;
    vector<vector<int>> marked(N, vector<int>(M, false));
    while (ok(cur.first, cur.second, N, M)) {
        int x = getNext(cur, ind).first, y = getNext(cur, ind).second;
        if (ok(x, y, N, M) && a[x][y] != '#') {
            int nextInd = (ind + 1) % 4;
            pair<int, int> nxt = getNext(cur, nextInd);
            if (ok(nxt.first, nxt.second, N, M)) {
                // a[nxt.first][nxt.second] != '#') {
                char prev = a[x][y];
                a[x][y] = '#';
                if (hasLoop(cur.first, cur.second, nextInd, a)) {
                    marked[x][y] = true;
                }
                a[x][y] = prev;
            }
        }
        while (ok(x, y, N, M) && a[x][y] == '#') {
            ind = (ind + 1) % 4;
            x = getNext(cur, ind).first, y = getNext(cur, ind).second;
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
