#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool ok(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

vector <int> get_vector(string s) {
    vector <int> retval;
    for (auto c: s) {
        int x = c - '0';
        retval.push_back (x);
    }
    return retval;
}

int32_t main () {
    string s;
    vector <vector <int>> grid;
    vector <vector <bool>> marked;
    while (getline (cin, s)) {
        vector <int> temp = get_vector (s);
        grid.push_back (temp);
        vector <bool> m;
        m.resize((int)temp.size(), false);
        marked.push_back(m);
    }

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool is_lower = true;
            for (auto p: dirs) {
                int x = p.first;
                int y = p.second;
                if (ok (i + x, j + y, n, m)) {
                    if (grid[i+x][j+y] <= grid[i][j]) {
                        is_lower = false;
                    }
                }
            }
            if (is_lower) {
                marked[i][j] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (marked[i][j]) {
                answer += grid[i][j] + 1;
            }
        }
    }

    // debug (grid);

    printf("%lld\n", answer);
}
