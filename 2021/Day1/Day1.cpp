#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int n;
    int sum = 0;
    int ans = 0;
    queue <int> a;
    while (cin >> n) {
        a.push (n);
        if (a.size() > 3) {
            int f = a.front();
            sum -= f;
            if (sum + f < sum + n) {
                ans++;
            }
            a.pop();
        }
        sum += n;
    }
    printf("%lld\n", ans);
}
