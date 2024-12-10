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
    bool mult = true;
    while (getline(cin, s)) {
        regex r(R"((do\(\))|(don't\(\))|mul\((\d{1,3}),(\d{1,3})\))");
        smatch match;

        string::const_iterator searchStart(s.cbegin());
        while (regex_search(searchStart, s.cend(), match, r)) {
            // debug(match[0], match[1], match[2], match[3], match[4]);
            if (match[0] == "do()")
                mult = true;
            else if (match[0] == "don\'t()")
                mult = false;
            else if (mult)
                ans += stoi(match[3]) * stoi(match[4]);
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
