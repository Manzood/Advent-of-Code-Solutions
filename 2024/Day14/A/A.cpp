#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    Point() : x(0), y(0) {}
};

const int RUNS = 100;

constexpr int N = 103;
constexpr int M = 101;

void print_grid(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", grid[i][j] == '0' ? '.' : (char)grid[i][1] + '0');
        }
        printf("\n");
    }
}

void solve([[maybe_unused]] int test) {
    string s;
    vector<Point> a, v;
    while (getline(cin, s)) {
        if (s.empty()) break;
        int x, y;
        s = s.substr(s.find('=') + 1);
        x = stoll(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
        y = stoll(s.substr(0, s.find(' ')));
        a.push_back(Point(x, y));
        s = s.substr(s.find('=') + 1);
        x = stoll(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
        y = stoll(s);
        v.push_back(Point(x, y));
    }
    int n = (int)a.size();
    vector<Point> final_pos(n);
    for (int i = 0; i < n; i++) {
        Point pos = Point(a[i].x + RUNS * v[i].x, a[i].y + RUNS * v[i].y);
        pos.x = ((pos.x % M) + M) % M;
        pos.y = ((pos.y % N) + N) % N;
        assert(pos.x >= 0 && pos.y >= 0);
        final_pos[i] = pos;
    }
    vector<vector<int>> grid(N, vector<int>(M, 0));
    for (int i = 0; i < n; i++) {
        grid[final_pos[i].y][final_pos[i].x]++;
    }
    vector<int> quadrant(4, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == N / 2 || j == M / 2) continue;
            if (i < N / 2 && j < M / 2) {
                quadrant[0] += grid[i][j];
            } else if (i < N / 2 && j > M / 2) {
                quadrant[1] += grid[i][j];
            } else if (i > N / 2 && j < M / 2) {
                quadrant[2] += grid[i][j];
            } else {
                quadrant[3] += grid[i][j];
            }
        }
    }
    printf("%lld\n", quadrant[0] * quadrant[1] * quadrant[2] * quadrant[3]);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
