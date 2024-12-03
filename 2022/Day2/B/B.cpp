#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(char a, char b) {
    char val = a + 'X' - 'A';
    val += b - 'X' - 1;
    if (val < 'X') val = 'Z';
    if (val > 'Z') val = 'X';
    return val - 'X' + 1;
}

void solve([[maybe_unused]] int test) {
    string s;
    int tot = 0;
    while (getline(cin, s)) {
        int score = (s[2] - 'X') * 3;
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
