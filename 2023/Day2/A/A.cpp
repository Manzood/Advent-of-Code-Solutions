#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int getnum(string s) {
    int num = 0;
    for (auto x : s) num = num * 10 + (x - '0');
    return num;
}

void solve([[maybe_unused]] int test) {
    string s;
    int game = 1, ans = 0;
    while (getline(cin, s)) {
        bool found = false;
        int pos = 0;
        while (true) {
            int find_index = s.find(";", pos) == (size_t)-1 ? (int)s.size()
                                                            : s.find(";", pos);
            string t = s.substr(pos, find_index - pos);
            if (pos == 0) t = t.substr(t.find(":") + 1);
            pos = s.find(";", pos) + 1;
            int ind = 0;
            while (true) {
                int t_index = t.find(",", ind) == (size_t)-1 ? (int)t.size()
                                                             : t.find(",", ind);
                string x = t.substr(ind, t_index - ind);
                ind = t.find(",", ind) + 1;
                for (int len = 3; len <= 5; len++) {
                    string temp;
                    for (int i = 0; i < len; i++)
                        temp += x[(int)x.size() - len + i];
                    if (temp == "red") {
                        found |=
                            getnum(x.substr(1, (int)x.size() - len - 2)) > 12;
                        // if (game == 3)
                        // debug(getnum(x.substr(1, (int)x.size() - len - 2)));
                    } else if (temp == "green") {
                        found |=
                            getnum(x.substr(1, (int)x.size() - len - 2)) > 13;
                    } else if (temp == "blue") {
                        found |=
                            getnum(x.substr(1, (int)x.size() - len - 2)) > 14;
                    }
                }
                if (t_index == (int)t.size()) break;
            }
            if (find_index == (int)s.size()) break;
        }
        if (!found) ans += game;
        game++;
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
