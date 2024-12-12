#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 140;

vector<vector<int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector<vector<pair<int, int>>> vertical, horizontal;
int dfs(int i, int j, vector<string>& a, vector<vector<bool>>& vis) {
    int ret = 0;
    int M = (int)a[0].size();
    if (vis[i][j] || !ok(i, j, N, M)) return ret;
    vis[i][j] = true;
    for (auto d : dirs) {
        int x = i + d[0], y = j + d[1];
        if (ok(x, y, N, M) && a[x][y] == a[i][j]) {
            ret += dfs(x, y, a, vis);
        }
    }
    for (int ind = 0; ind < 4; ind++) {
        int x = i + dirs[ind][0], y = j + dirs[ind][1];
        if (!ok(x, y, N, M) || a[x][y] != a[i][j]) {
            if (ind == 0 || ind == 2) {
                vector<pair<int, int>> line = {{x, y}, {x, y + 1}, {0, 0}};
                if (ind == 2) line = {{i, j}, {i, j + 1}, {1, 1}};
                horizontal.push_back(line);
            } else {
                vector<pair<int, int>> line = {{x, y}, {x + 1, y}, {1, 1}};
                if (ind == 1) line = {{i, j}, {i + 1, j}, {0, 0}};
                vertical.push_back(line);
            }
        }
    }
    return 1 + ret;
}

int process() {
    int lines = (int)vertical.size();
    sort(vertical.begin(), vertical.end(),
         [](const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
             if (a[0].second == b[0].second && a[0].first != b[0].first) {
                 return a[0].first < b[0].first;
             } else {
                 return a[0].second < b[0].second;
             }
         });
    int sides = 1;
    for (int i = 1; i < lines; i++) {
        if (vertical[i][0] == vertical[i - 1][1] &&
            vertical[i][2] == vertical[i - 1][2])
            continue;
        else
            sides++;
    }
    lines = (int)horizontal.size();
    sort(horizontal.begin(), horizontal.end());
    sides++;
    for (int i = 1; i < lines; i++) {
        if (horizontal[i][0] == horizontal[i - 1][1] &&
            horizontal[i][2] == horizontal[i - 1][2])
            continue;
        else
            sides++;
    }
    return sides;
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
                vertical.clear();
                horizontal.clear();
                int ret = dfs(i, j, a, vis);
                int sides = process();
                ans += ret * sides;
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
