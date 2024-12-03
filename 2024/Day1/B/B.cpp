#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    vector<int> a;
    map<int, int> b;
    while (cin >> n) {
        cin >> m;
        a.push_back(n);
        b[m]++;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        ans += a[i] * b[a[i]];
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
