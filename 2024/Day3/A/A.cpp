#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// abcmul(1,3)

void solve([[maybe_unused]] int test) {
    string s;
    int ans = 0;
    bool multiplying = true;
    while (getline(cin, s)) {
        int n = (int)s.size();
        for (int i = 0; i < n - 7; i++) {
            if (s.substr(i, 4) == "mul(") {
                int ind = i + 4;
                bool found_comma = false;
                while (ind < n && ind < i + 8) {
                    if (s[ind] == ',') {
                        found_comma = true;
                        break;
                    } else if (s[ind] > '9' || s[ind] < '0') {
                        break;
                    }
                    ind++;
                }
                if (ind == i + 4) continue;
                if (!found_comma) continue;
                string numStr = s.substr(i + 4, ind - i + 3);
                int a = stoi(numStr);
                int ind2 = ind + 1;
                bool found_bracket = false;
                while (ind2 < n && ind2 < ind + 5) {
                    if (s[ind2] == ')') {
                        found_bracket = true;
                        break;
                    } else if (s[ind2] > '9' || s[ind2] < '0') {
                        break;
                    }
                    ind2++;
                }
                if (ind2 == ind + 1) continue;
                if (!found_bracket) continue;
                numStr = s.substr(ind + 1, ind2 - ind);
                int b = stoi(numStr);
                if (multiplying) ans += a * b;
            } else if (s.substr(i, 4) == "do()") {
                multiplying = true;
            } else if (s.substr(i, 7) == "don't()") {
                multiplying = false;
            }
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
