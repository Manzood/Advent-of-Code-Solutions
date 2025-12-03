#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int concatnum(int num) {
    int mult = 1;
    int cpy = num;
    while (cpy) {
        mult *= 10;
        cpy /= 10;
    }
    return mult * num + num;
}

int get(int l, int r) {
    int cur = 1;
    int sum = 0;
    while (concatnum(cur) < l) cur *= 10;
    while (concatnum(cur - 1) >= l) cur--;
    while (concatnum(cur) <= r) {
        // debug(concatnum(cur));
        sum += concatnum(cur);
        cur++;
    }
    return sum;
}

void solve([[maybe_unused]] int test) {
    int a, b;
    char c;
    int ans = 0;
    cin >> a >> c >> b;
    ans += get(a, b);
    while (cin >> c) {
        cin >> a >> c >> b;
        ans += get(a, b);
    }
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
