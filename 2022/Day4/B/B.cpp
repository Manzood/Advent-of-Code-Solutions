#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a[2], b[2];
    int cnt = 0;
    while (cin >> a[0]) {
        char c;
        cin >> c >> a[1] >> c >> b[0] >> c >> b[1];
        if (a[0] > b[0]) swap(a, b);
        if (a[1] >= b[0]) cnt++;
    }
    printf("%lld\n", cnt);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
