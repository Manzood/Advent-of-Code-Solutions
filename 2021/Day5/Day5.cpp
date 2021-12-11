#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

struct point {
    int x;
    int y;
};

int32_t main () {
    // consider 45 degree lines as well
    point a, b;
    vector <vector <int>> grid (1000, vector <int> (1000, 0));

    while (scanf("%lld,%lld -> %lld,%lld\n", &a.x, &a.y, &b.x, &b.y) == 4) {
        if (a.x == b.x) {
            // printf("%lld %lld -> %lld %lld\n", a.x, a.y, b.x, b.y);
            int mi = min (a.y, b.y);
            int mx = max (a.y, b.y);
            for (int i = mi; i <= mx; i++) {
                grid[a.x][i]++;
            }
        } else if (a.y == b.y) {
            int mi = min (a.x, b.x);
            int mx = max (a.x, b.x);
            for (int i = mi; i <= mx; i++) {
                grid[i][a.y]++;
            }
        } else {
            // 45 degree line
            int xdir = b.x > a.x ? 1 : -1;
            int ydir = b.y > a.y ? 1 : -1;
            int x = a.x, y = a.y;
            while (x != b.x) {
                grid[x][y]++;
                x += xdir;
                y += ydir;
            }
            grid[x][y]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            // printf("%lld ", grid[i][j]);
            if (grid[i][j] >= 2) {
                ans++;
            }
        }
        // printf("\n");
    }

    printf("%lld\n", ans);
}
