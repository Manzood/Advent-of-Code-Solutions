#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 100;

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,
         vector<int>& sorted) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto u : adj[node]) {
        dfs(u, adj, visited, sorted);
    }
    sorted.push_back(node);
}

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
        if (!valid) {
            vector<vector<int>> subGraph(N);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    if (adj[update[i]].count(update[j])) {
                        subGraph[update[i]].push_back(update[j]);
                    }
                }
            }
            vector<int> visited(N, 0), sorted;
            for (int i = 0; i < n; i++) {
                dfs(update[i], subGraph, visited, sorted);
            }
            reverse(sorted.begin(), sorted.end());
            ans += sorted[n / 2];
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
