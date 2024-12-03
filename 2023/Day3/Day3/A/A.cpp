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

bool is_number(char c) { return c <= '9' && c >= '0'; }

int get_number(string s) {
    int num = 0;
    for (int i = 0; i < (int)s.size(); i++) num = num * 10 + (s[i] - '0');
    return num;
}

void solve([[maybe_unused]] int test) {
    vector<string> grid;
    vector<vector<bool>> marked;
    string s;
    while (getline(cin, s)) {
        grid.push_back(s);
        vector<bool> temp(s.size(), false);
        marked.push_back(temp);
    }
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.' && !is_number(grid[i][j])) {
                for (auto d : dirs) {
                    if (ok(i + d.first, j + d.second, n, m)) {
                        if (is_number(grid[i + d.first][j + d.second])) {
                            marked[i + d.first][j + d.second] = true;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (marked[i][j - 1] && is_number(grid[i][j])) marked[i][j] = true;
        }
        for (int j = (int)grid.size() - 2; j >= 0; j--) {
            if (marked[i][j + 1] && is_number(grid[i][j])) marked[i][j] = true;
        }
    }
    int ans = 0;
    vector<vector<int>> val(n, vector<int>(m, 0));
    vector<vector<int>> gear_val(n, vector<int>(m, 0));
    vector<vector<int>> final_val(n, vector<int>(m, 0));
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        vector<bool> used(m, false);
        for (int j = 0; j < m; j++) {
            if (!used[j] && marked[i][j]) {
                int x = j;
                string temp;
                while (x < m && marked[i][x]) {
                    used[x] = true;
                    temp += grid[i][x];
                    val[i][x] = cnt;
                    x++;
                }
                cnt++;
            }
        }
    }
    int gear_cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                set<int> cur;
                for (auto d : dirs) {
                    if (ok(i + d.first, j + d.second, n, m)) {
                        if (val[i + d.first][j + d.second] > 0) {
                            cur.insert(val[i + d.first][j + d.second]);
                        }
                    }
                }
                if ((int)cur.size() == 2) {
                    gear_val[i][j] = gear_cnt++;
                    for (auto d : dirs) {
                        if (ok(i + d.first, j + d.second, n, m)) {
                            if (val[i + d.first][j + d.second] > 0) {
                                final_val[i + d.first][j + d.second] =
                                    gear_val[i][j];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (final_val[i][j - 1] > 0 && is_number(grid[i][j]))
                final_val[i][j] = final_val[i][j - 1];
        }
        for (int j = n - 2; j >= 0; j--) {
            if (final_val[i][j + 1] > 0 && is_number(grid[i][j]))
                final_val[i][j] = final_val[i][j + 1];
        }
    }
    vector<int> prod((int)1e7, 1);
    for (int i = 0; i < n; i++) {
        vector<bool> used(m, false);
        for (int j = 0; j < m; j++) {
            if (!used[j] && final_val[i][j] > 0) {
                int x = j;
                string temp;
                while (x < m && final_val[i][x] > 0) {
                    used[x] = true;
                    temp += grid[i][x];
                    x++;
                }
                int num = get_number(temp);
                prod[final_val[i][j]] *= num;
            }
        }
    }
    for (int i = 0; i < (int)1e7; i++)
        if (prod[i] > 1) ans += prod[i];
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
