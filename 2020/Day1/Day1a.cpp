#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    int x;
    set <int> nums;
    int ans = 1;
    while (cin >> x) {
        if (nums.count(2020 - x)) {
            ans *= x;
            ans *= (2020 - x);
        }
        nums.insert(x);
    }
    printf("%d\n", ans);
}
