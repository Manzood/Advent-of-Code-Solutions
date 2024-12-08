#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void solve([[maybe_unused]] int test) {
    vector<string> a;
    string s;
    while (getline(cin, s)) {
        if ((int)s.size() > 0) a.push_back(s);
    }
    int n = (int)a.size(), m = (int)a[0].size();
    map<char, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '.') {
                if (mp.count(a[i][j])) {
                    mp[a[i][j]].push_back({i, j});
                } else {
                    mp[a[i][j]] = {{i, j}};
                }
            }
        }
    }
    vector<vector<bool>> marked(n, vector<bool>(m, false));
    for (auto v : mp) {
        int sz = (int)v.second.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                pair<int, int> diff = {v.second[i].first - v.second[j].first,
                                       v.second[i].second - v.second[j].second};
                pair<int, int> f = {v.second[i].first + diff.first,
                                    v.second[i].second + diff.second};
                pair<int, int> w = {v.second[j].first - diff.first,
                                    v.second[j].second - diff.second};
                if (ok(f.first, f.second, n, m))
                    marked[f.first][f.second] = true;
                if (ok(w.first, w.second, n, m))
                    marked[w.first][w.second] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (marked[i][j]) ans++;
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
