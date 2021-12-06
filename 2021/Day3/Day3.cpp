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
    vector <string> a;
    while (cin >> s) {
        a.push_back (s);
    }

    int n = a.size();
    int len = a[0].size();
    vector <int> cnt (len, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++) {
            cnt[j] += a[i][j] - '0';
        }
    }

    vector <int> eps (len, 0), gamma (len, 0);
    for (int i = 0; i < len; i++) {
        if (cnt[i] > n / 2) {
            gamma[i] = 1;
            eps[i] = 0;
        } else {
            gamma[i] = 0;
            eps[i] = 1;
        }
    }

    reverse (eps.begin(), eps.end());
    reverse (gamma.begin(), gamma.end());

    int e = 0, g = 0;
    for (int i = 0; i < len; i++) {
        int val = (1LL << i);
        if (gamma[i] == 1) g += val;
        if (eps[i] == 1) e += val;
    }

    printf("%lld\n", e * g);
}
