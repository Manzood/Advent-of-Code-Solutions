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
    cin >> s;
    int n = (int)s.size();
    vector<int> a;
    int id = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        if (i & 1) {
            for (int j = 0; j < num; j++) {
                a.push_back(-1);
            }
        } else {
            for (int j = 0; j < num; j++) {
                a.push_back(id);
            }
            id++;
        }
    }
    n = (int)a.size();
    int ind = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == -1) continue;
        while (ind < i && a[ind] != -1) ind++;
        if (ind >= i) break;
        swap(a[ind++], a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i * (a[i] == -1 ? 0LL : a[i]);
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
