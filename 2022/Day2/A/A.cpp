#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(char a, char b) {
    int ret = 0;
    char val = a + 'X' - 'A';
    if (b == val) ret = 3;
    val++;
    if (val > 'Z') val = 'X';
    if (b == val) ret = 6;
    return ret;
}

void solve([[maybe_unused]] int test) {
    string s;
    int tot = 0;
    while (getline(cin, s)) {
        int score = s[2] - 'X' + 1;
        score += get(s[0], s[2]);
        tot += score;
    }
    printf("%lld\n", tot);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
