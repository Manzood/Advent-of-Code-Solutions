#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    string s;
    int depth = 0, horizontalPosition = 0;
    int aim = 0;

    while (cin >> s) {
        int n; cin >> n;
        if (s == "forward") {
            horizontalPosition += n;
            depth += aim * n;
        } else if (s == "down") {
            aim += n;
            // depth += n;
        } else if (s == "up") {
            aim -= n;
            // depth -= n;
        }
    }

    printf("%lld\n", depth * horizontalPosition);
}
