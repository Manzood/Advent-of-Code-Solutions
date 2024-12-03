#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int c;
    bool newline = true;
    int ans = 0, sum = 0, val = 0;
    vector<int> s;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (newline) {
                s.push_back(sum);
                sum = 0;
            } else {
                sum += val;
            }
            val = 0;
            newline = true;
        } else {
            newline = false;
            val *= 10;
            val += c - '0';
        }
    }
    sort(s.begin(), s.end(), greater<int>());
    ans = s[0];
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
