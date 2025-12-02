#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    string s;
    int cur = 50;
    int ans = 0;
    while (getline(cin, s)) {
        int dir = s[0];
        string rest = s.substr(1);
        int num = stoi(rest);
        num %= 100;
        if (dir == 'L') {
            cur -= num;
            if (cur < 0) cur += 100;
        } else {
            cur += num;
            cur %= 100;
        }
        if (cur == 0) ans++;
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
