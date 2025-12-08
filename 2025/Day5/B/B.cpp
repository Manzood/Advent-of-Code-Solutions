#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    vector<pair<int, int>> ranges;
    string s;
    while (getline(cin, s)) {
        if (s.empty()) break;
        int a = stoll(s.substr(0, s.find('-')));
        int b = stoll(s.substr(s.find('-') + 1));
        ranges.push_back({a, b});
    }

    sort(ranges.begin(), ranges.end());
    int n = (int)ranges.size();
    vector<pair<int, int>> x;
    for (int i = 0; i < n; i++) {
        int f = ranges[i].first;
        int sec = ranges[i].second;
        while (!x.empty() && x.back().second >= ranges[i].first - 1) {
            f = x.back().first;
            sec = max(sec, x.back().second);
            x.pop_back();
        }
        x.push_back({f, sec});
    }
    int ans = 0;
    for (auto p : x) {
        ans += p.second - p.first + 1;
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
