#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    string s;
    int mx = 0;
    while (getline (cin, s)) {
        int start = 0;
        int end = 127;
        for (int i = 0; i < 7; i++) {
            int mid = (start + end) / 2;
            if (s[i] == 'F') {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        int row = (start + end) / 2;
        start = 0; end = 7;
        for (int i = 7; i < 10; i++) {
            int mid = (start + end) / 2;
            if (s[i] == 'R') {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        // row++;
        int col = (start + end) / 2;
        // col++;
        int ans = row * 8 + col;
        printf("%d\n", ans);
        mx = max(ans, mx);
    }
    printf("%d\n", mx);
}
