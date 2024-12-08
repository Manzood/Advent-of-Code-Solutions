#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void dfs(int ind, vector<int>& values, vector<int>& results, int res,
         int target) {
    if (res > target) return;
    int n = (int)values.size();
    if (ind >= n) {
        results.push_back(res);
        return;
    }
    dfs(ind + 1, values, results, res * values[ind], target);
    dfs(ind + 1, values, results, res + values[ind], target);
    string a = to_string(res);
    string b = to_string(values[ind]);
    a = a + b;
    dfs(ind + 1, values, results, stol(a), target);
}

void solve([[maybe_unused]] int test) {
    string s;
    int ans = 0;
    while (getline(cin, s)) {
        if ((int)s.size() == 0) continue;
        string cur = s.substr(0, s.find(':'));
        int target = stol(cur);
        s = s.substr(s.find(':') + 2);
        vector<int> values;
        while (s.find(' ') != s.npos) {
            values.push_back(stol(s.substr(0, s.find(' '))));
            s = s.substr(s.find(' ') + 1);
        }
        values.push_back(stol(s));
        vector<int> results;
        dfs(0, values, results, 0, target);
        bool found = false;
        for (auto x : results) {
            found |= x == target;
        }
        if (found) ans += target;
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
