#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void move_stack(int num, int src, int dest, vector<vector<char>>& st) {
    vector<char> cpy;
    int len = st[src].size();
    for (int i = len - 1; i >= len - num && i >= 0; i--) {
        cpy.push_back(st[src][i]);
        st[src].pop_back();
    }
    debug(cpy);
    for (auto x : cpy) {
        st[dest].push_back(x);
    }
}

void solve([[maybe_unused]] int test) {
    vector<vector<char>> st = {{'S', 'L', 'F', 'Z', 'D', 'B', 'R', 'H'},
                               {'R', 'Z', 'M', 'B', 'T'},
                               {'S', 'N', 'H', 'C', 'L', 'Z'},
                               {'J', 'F', 'C', 'S'},
                               {'B', 'Z', 'R', 'W', 'H', 'G', 'P'},
                               {'T', 'M', 'N', 'D', 'G', 'Z', 'J', 'V'},
                               {'Q', 'P', 'S', 'F', 'W', 'N', 'L', 'G'},
                               {'R', 'Z', 'M'},
                               {'T', 'R', 'V', 'G', 'L', 'C', 'M'}};
    // st = {{'N', 'Z'}, {'D', 'C', 'M'}, {'P'}};
    for (auto& x : st) {
        reverse(x.begin(), x.end());
    }
    string s, ans;
    for (int i = 0; i < 10; i++) {
        getline(cin, s);
    }
    while (cin >> s) {
        int num, src, dest;
        cin >> num >> s >> src >> s >> dest;
        move_stack(num, src - 1, dest - 1, st);
    }
    for (int i = 0; i < 9; i++) {
        if (st[i].size()) {
            ans += st[i].back();
        }
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
