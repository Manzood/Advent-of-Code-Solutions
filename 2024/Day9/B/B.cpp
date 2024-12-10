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
    cin >> s;
    int n = (int)s.size();
    vector<int> a;
    int id = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        if (i & 1) {
            for (int j = 0; j < num; j++) a.push_back(-1);
        } else {
            for (int j = 0; j < num; j++) a.push_back(id);
            id++;
        }
    }
    n = (int)a.size();
    int i = n - 1;
    while (i >= 0) {
        if (a[i] == -1) {
            i--;
            continue;
        }
        int cur_size = 1;
        i--;
        while (i >= 0 && a[i] == a[i + 1]) {
            i--;
            cur_size++;
        }
        i++;
        bool found = false;
        int ind = 0;
        while (!found && ind < i) {
            while (ind < i && a[ind] != -1) ind++;
            int start = ind;
            while (a[ind] == a[start]) ind++;
            ind--;
            if (ind - start + 1 >= cur_size) {
                found = true;
                ind = start;
            } else {
                ind++;
            }
        }
        if (found) {
            int ptr = i;
            for (int j = 0; j < cur_size; j++) {
                swap(a[ptr++], a[ind++]);
            }
        }
        i--;
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
        ans += i * (a[i] == -1 ? 0LL : a[i]);
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
