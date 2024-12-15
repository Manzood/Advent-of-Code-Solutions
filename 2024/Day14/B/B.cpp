#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

// should've chosen to represent this as (y, x), not (x, y)
struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    Point() : x(0), y(0) {}
};

constexpr int RUNS = 10000;
constexpr int PRINTING = 30;

constexpr int N = 103;
constexpr int M = 101;

void print_grid(vector<vector<int>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", grid[i][j] == 0 ? '.' : '#');
        }
        printf("\n");
    }
}

int calculate_score(vector<Point> final_pos) {
    int n = (int)final_pos.size();
    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int xVal = abs(final_pos[i].x - final_pos[j].x);
            int yVal = abs(final_pos[i].y - final_pos[j].y);
            score += xVal * xVal + yVal * yVal;
        }
    }
    return score;
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
    vector<vector<int>> grid(N, vector<int>(M, 0));
    vector<pair<int, int>> run_scores;
    for (int run = 0; run <= RUNS; run++) {
        debug(run);
        grid = vector<vector<int>>(N, vector<int>(M, 0));
        vector<Point> final_pos(n);
        for (int i = 0; i < n; i++) {
            Point pos = Point(a[i].x + run * v[i].x, a[i].y + run * v[i].y);
            pos.y = ((pos.y % N) + N) % N;
            pos.x = ((pos.x % M) + M) % M;
            assert(pos.x >= 0 && pos.y >= 0);
            final_pos[i] = pos;
        }
        for (int i = 0; i < n; i++) {
            grid[final_pos[i].y][final_pos[i].x]++;
        }
        run_scores.push_back({calculate_score(final_pos), run});
    }
    sort(run_scores.begin(), run_scores.end());
    for (int print_run = 0; print_run < PRINTING; print_run++) {
        int run = run_scores[print_run].second;
        grid = vector<vector<int>>(N, vector<int>(M, 0));
        vector<Point> final_pos(n);
        for (int i = 0; i < n; i++) {
            Point pos = Point(a[i].x + run * v[i].x, a[i].y + run * v[i].y);
            pos.y = ((pos.y % N) + N) % N;
            pos.x = ((pos.x % M) + M) % M;
            assert(pos.x >= 0 && pos.y >= 0);
            final_pos[i] = pos;
        }
        for (int i = 0; i < n; i++) {
            grid[final_pos[i].y][final_pos[i].x]++;
        }
        printf("RUN: %lld\n\n", run);
        print_grid(grid);
        printf("\n\n\n\n\n");
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
