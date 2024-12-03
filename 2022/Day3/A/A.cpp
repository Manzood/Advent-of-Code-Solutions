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
    int sum = 0;
    while (cin >> s) {
        int n = s.size();
        set<int> c1, c2;
        char repeat = 'a';
        for (int i = 0; i < n / 2; i++) {
            c1.insert(s[i]);
        }
        for (int i = n / 2; i < n; i++) {
            if (c1.count(s[i])) repeat = s[i];
        }
        int ans = 0;
        if (islower(repeat)) {
            ans = 1 + repeat - 'a';
        } else {
            ans = 27 + repeat - 'A';
        }
        sum += ans;
    }
    printf("%lld\n", sum);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
