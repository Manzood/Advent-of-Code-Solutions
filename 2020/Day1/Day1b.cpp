#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    set <int> nums;
    vector <int> a;
    int x;
    while (cin >> x) {
        nums.insert(x);
        a.push_back(x);
    }
    int ans = 1;
    for (auto i : a) {
        for (auto j : a) {
            if (nums.count(2020 - i - j)) {
                ans = i;
                ans *= j;
                ans *= (2020 - i - j);
            }
        }
    }
    printf("%d\n", ans);
}
