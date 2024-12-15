#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int N = 16;

void solve([[maybe_unused]] int test) {
    string s;
    vector<pair<int, int>> a, b, target;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        if (i % 4 == 0) {
            s = s.substr(s.find('+') + 1);
            int x = stol(s.substr(0, s.find(',')));
            s = s.substr(s.find('+') + 1);
            int y = stol(s);
            a.push_back({x, y});
        } else if (i % 4 == 1) {
            s = s.substr(s.find('+') + 1);
            int x = stol(s.substr(0, s.find(',')));
            s = s.substr(s.find('+') + 1);
            int y = stol(s);
            b.push_back({x, y});
        } else if (i % 4 == 2) {
            s = s.substr(s.find('=') + 1);
            int x = stol(s.substr(0, s.find(',')));
            s = s.substr(s.find('=') + 1);
            int y = stol(s);
            // x += (int)1e13, y += (int)1e13;
            target.push_back({x, y});
        }
    }
    int n = (int)a.size();
    assert((int)b.size() == n);
    assert((int)target.size() == n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = (int)1e18;
        debug(i, a[i], b[i], target[i]);
        // for a
        for (int j = 0; j < 1000000000; j++) {
            int xVal = b[i].first * j, yVal = b[i].second * j;
            int remX = target[i].first - xVal, remY = target[i].second - yVal;
            if (remX < 0 || remY < 0) {
                debug(remX, remY, i, j);
                break;
            }
            debug(j, xVal, yVal, remX, remY, remX % a[i].second,
                  remY % a[i].first);
            if (remX % a[i].first != 0 || remY % a[i].second != 0) continue;
            if (remX / a[i].first != remY / a[i].second) continue;
            debug(i, j);
            cur = min(cur, j + 3 * (remX / a[i].first));
        }
        for (int j = 0; j < 1000000000; j++) {
            int xVal = a[i].first * j, yVal = a[i].second * j;
            // debug(xVal, yVal);
            int remX = target[i].first - xVal, remY = target[i].second - yVal;
            if (remX < 0 || remY < 0) {
                debug(remX, remY, i, j);
                break;
            }
            if (remX % b[i].first != 0 || remY % b[i].second != 0) continue;
            if (remX / b[i].first != remY / b[i].second) continue;
            debug(i, j);
            cur = min(cur, 3 * j + (remX / b[i].first));
        }
        if (cur < (int)1e18) ans += cur;
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

