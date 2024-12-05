#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 100;

void solve([[maybe_unused]] int test) {
    vector<set<int>> adj(N);
    vector<vector<int>> updates;
    string s;
    bool reading_updates = false;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            reading_updates = true;
            continue;
        }
        if (!reading_updates) {
            string x = s.substr(0, 2), y = s.substr(3, 2);
            int v = stoi(x), w = stoi(y);
            adj[w].insert(v);
        } else {
            vector<int> update;
            for (int i = 0; i < (int)s.size(); i += 3) {
                string x = s.substr(i, 2);
                update.push_back(stoi(x));
            }
            updates.push_back(update);
        }
    }
    int ans = 0;
    for (auto update : updates) {
        int n = (int)update.size();
        bool valid = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (adj[update[i]].count(update[j])) valid = false;
            }
        }
        if (valid) ans += update[n / 2];
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
