#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 1280;

void solve([[maybe_unused]] int test) {
    string s;
    vector<pair<int, int>> a, b, target;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        if (i % 4 == 0) {
            s = s.substr(s.find('+') + 1);
            int x = stoi(s.substr(0, s.find(',')));
            s = s.substr(s.find('+') + 1);
            int y = stoi(s);
            a.push_back({x, y});
        } else if (i % 4 == 1) {
            s = s.substr(s.find('+') + 1);
            int x = stoi(s.substr(0, s.find(',')));
            s = s.substr(s.find('+') + 1);
            int y = stoi(s);
            b.push_back({x, y});
        } else if (i % 4 == 2) {
            s = s.substr(s.find('=') + 1);
            int x = stoi(s.substr(0, s.find(',')));
            s = s.substr(s.find('=') + 1);
            int y = stoi(s);
            target.push_back({x, y});
        }
    }
    int n = (int)a.size();
    assert((int)b.size() == n);
    assert((int)target.size() == n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = 1000;
        for (int j = 0; j < 100; j++) {
            int x = a[i].first * j;
            int y = a[i].second * j;
            if (x > target[i].first || y > target[i].second) break;
            int remX = target[i].first - x;
            int remY = target[i].second - y;
            if (remX % b[i].first != 0 || remY % b[i].second != 0) continue;
            if (remX / b[i].first != remY / b[i].second) continue;
            cur = min(cur, j * 3 + remX / b[i].first);
        }
        if (cur < 1000) ans += cur;
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
