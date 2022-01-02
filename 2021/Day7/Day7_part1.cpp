#include "bits/stdc++.h"
#ifdef local
#include "custom/debugger.h"
#else
#define debug(x) 42;
#endif
using namespace std;
#define int long long
const int SIZE = 2000;

int32_t main() {
    int num;
    scanf("%lld", &num);
    vector<int> horizontalPosition;
    horizontalPosition.push_back(num);
    while (scanf(",%lld", &num)) {
        horizontalPosition.push_back(num);
    }
    int n = horizontalPosition.size();
    sort(horizontalPosition.begin(), horizontalPosition.end());
    vector<int> lcnt(SIZE + 1, 0), rcnt(SIZE + 1, 0);
    int ind = 0;
    // debug (n);

    for (int i = 0; i <= SIZE; i++) {
        lcnt[i] = ind;
        while (ind < n && i == horizontalPosition[ind]) {
            ind++;
        }
    }
    // for (int i = 0; i < 17; i++) {
    //     printf("%lld ", lcnt[i]);
    // }
    // printf("\n");

    ind = n - 1;
    debug (horizontalPosition[ind]);
    for (int i = SIZE; i >= 0; i--) {
        rcnt[i] = n - 1 - ind;
        while (ind >= 0 && i == horizontalPosition[ind]) {
            ind--;
        }
    }
    for (int i = 0; i < 17; i++) {
        printf("%lld ", rcnt[i]);
    }
    printf("\n");

    vector<int> ans(SIZE + 1, 0);
    vector<int> lsum(SIZE + 1, 0);
    vector<int> rsum(SIZE + 1, 0);
    int answer = (int)1e9 + 7;

    for (int i = 0; i < SIZE + 1; i++) {
        lsum[i] += lcnt[i];
        if (i > 0) lsum[i] += lsum[i - 1];
    }
    for (int i = SIZE; i >= 0; i--) {
        // debug (i, rcnt[i]);
        rsum[i] += rcnt[i];
        if (i < SIZE) rsum[i] += rsum[i + 1];
    }
    debug (n);
    for (int i = 0; i <= SIZE; i++) {
        ans[i] += lsum[i];
        ans[i] += rsum[i];
        // if (ans[i] < answer) {
        //     debug (i, ans[i]);
        // }
        answer = min(ans[i], answer);
    }

    printf("%lld\n", answer);
}
