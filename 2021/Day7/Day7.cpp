#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int num;
    scanf("%lld", &num);
    vector <int> horizontalPosition;
    horizontalPosition.push_back(num);
    while (scanf(",%lld", &num)) {
        horizontalPosition.push_back(num);
    }
    int n = horizontalPosition.size();

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += horizontalPosition[i];
    }

    printf("%lld", sum);
}
