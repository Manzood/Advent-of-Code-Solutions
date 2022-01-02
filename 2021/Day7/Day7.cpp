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
    sort (horizontalPosition.begin(), horizontalPosition.end());

    vector <int> ans(SIZE + 1, 0);
    for (int i = 0; i < SIZE + 1; i++) {
        for (int j = 0; j < n; j++) {
            int dist = abs (i - horizontalPosition[j]);
            ans[i] += (dist * (dist + 1)) / 2;
        }
    }

    int answer = (int) 1e9 + 7;
    for (auto x: ans) {
        answer = min (answer, x);
    }

    printf("%lld\n", answer);
}
