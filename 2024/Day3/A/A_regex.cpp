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
    int ans = 0;
    while (getline(cin, s)) {
        regex r(R"(mul\((\d{1,3}),(\d{1,3})\))");
        smatch match;

        string::const_iterator searchStart(s.cbegin());
        while (regex_search(searchStart, s.cend(), match, r)) {
            ans += stoi(match[1]) * stoi(match[2]);
            searchStart = match.suffix().first;
        }
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
