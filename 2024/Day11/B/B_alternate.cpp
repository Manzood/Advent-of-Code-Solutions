#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int STEP_SIZE = 5;
map<int, int> mp, new_mp;

void simulate(int num, int runs) {
    vector<int> a = {num}, res;
    for (int run = 0; run < runs; run++) {
        res.clear();
        int n = (int)a.size();
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
    for (auto r : res) {
        if (mp[num] != 0)
            new_mp[r] += mp[num];
        else
            new_mp[r]++;
    }
}

void solve([[maybe_unused]] int test) {
    int n = 8;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        mp[a[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < 75 / STEP_SIZE; i++) {
        debug(++cnt);
        for (auto val : mp) {
            simulate(val.first, STEP_SIZE);
        }
        mp = new_mp;
        new_mp.clear();
        debug(mp.size());
    }
    int ans = 0;
    for (auto val : mp) {
        debug(val);
        ans += val.second;
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
