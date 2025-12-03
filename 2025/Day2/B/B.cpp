#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int get(int l, int r) {
    int ret = 0;
    for (int cur = l; cur <= r; cur++) {
        string s = to_string(cur);
        for (int len = 1; len <= (int)s.size() / 2; len++) {
            string tmp = s.substr(0, len);
            string cpy = tmp;
            while (tmp.size() < s.size()) tmp += cpy;
            if (tmp == s) {
                ret += stoll(s);
                break;
            }
        }
    }
    return ret;
}

void solve([[maybe_unused]] int test) {
    int a, b;
    char c;
    int ans = 0;
    cin >> a >> c >> b;
    vector<pair<int, int>> inp;
    ans += get(a, b);
    inp.push_back({a, b});
    while (cin >> c) {
        cin >> a >> c >> b;
        ans += get(a, b);
        inp.push_back({a, b});
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
