#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n = 8;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<int> res;
    for (int run = 0; run < 40; run++) {
        res.clear();
        n = (int)a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                res.push_back(1);
            } else if (to_string(a[i]).size() & 1) {
                assert(a[i] < (int)1e9);
                res.push_back(a[i] * 2024);
            } else {
                string cur = to_string(a[i]);
                string f = cur.substr(0, cur.size() / 2),
                       s = cur.substr(cur.size() / 2);
                int x = 0, y = 0;
                for (auto digit : f) {
                    x *= 10;
                    x += digit - '0';
                }
                for (auto digit : s) {
                    y *= 10;
                    y += digit - '0';
                }
                res.push_back(x);
                res.push_back(y);
            }
        }
        a = res;
    }
    printf("%lld\n", (int)res.size());
    set<int> unique_nums;
    for (auto r : res) unique_nums.insert(r);
    debug(unique_nums.size());
    vector<int> f1, f2;
    map<int, int> mp;
    int cnt = 0;
    for (auto val : unique_nums) {
        cnt++;
        debug(cnt);
        f1 = {val};
        for (int run = 0; run < 35; run++) {
            f2.clear();
            n = (int)f1.size();
            for (int i = 0; i < n; i++) {
                if (f1[i] == 0) {
                    f2.push_back(1);
                } else if (to_string(f1[i]).size() & 1) {
                    f2.push_back(f1[i] * 2024);
                } else {
                    string cur = to_string(f1[i]);
                    string f = cur.substr(0, cur.size() / 2),
                           s = cur.substr(cur.size() / 2);
                    int x = 0, y = 0;
                    for (auto digit : f) {
                        x *= 10;
                        x += digit - '0';
                    }
                    for (auto digit : s) {
                        y *= 10;
                        y += digit - '0';
                    }
                    f2.push_back(x);
                    f2.push_back(y);
                }
            }
            f1 = f2;
        }
        mp[val] = (int)f2.size();
    }
    int ans = 0;
    for (auto r : res) {
        ans += mp[r];
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
