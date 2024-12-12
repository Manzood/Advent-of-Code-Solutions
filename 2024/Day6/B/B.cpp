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

bool hasCycle(pair<int, int> cur, int M, vector<string>& a) {
    int ind = 0;
    // vector<vector<vector<bool>>> marked(
    // N, vector<vector<bool>>(M, vector<bool>(4, false)));
    vector<bool> marked(N * M * 4, false);
    while (ok(cur.first, cur.second, N, M)) {
        // if (marked[cur.first][cur.second][ind]) return true;
        // marked[cur.first][cur.second][ind] = true;
        if (marked[(cur.first * M + cur.second) * 4 + ind]) return true;
        marked[(cur.first * M + cur.second) * 4 + ind] = true;
        int x = cur.first + dirs[ind].first, y = cur.second + dirs[ind].second;
        while (ok(x, y, N, M) && a[x][y] == '#') {
            ind++;
            if (ind == 4) ind = 0;
            x = cur.first + dirs[ind].first, y = cur.second + dirs[ind].second;
        }
        cur = {x, y};
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
    int ans = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if ((row == cur.first && col == cur.second) || (a[row][col] == '#'))
                continue;
            a[row][col] = '#';
            if (hasCycle(cur, M, a)) ans++;
            a[row][col] = '.';
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
