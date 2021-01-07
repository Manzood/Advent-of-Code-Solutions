#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    string s;
    int printval = 0;
    vector <bool> present (1278, false);
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
        int ans = row * 10 + col;
        // printf("%d\n", ans);
        present[ans] = true;
    }
    for (int i = 0; i < (int) present.size(); i++) {
        if (i > 7 && i < 1270) {
            if (present[i] == false && present[i-1] == true && present[i+1] == true) {
                printval = i;
            }
        }
    }
    printf("%d\n", printval);
    printf("%d\n", 64 * 8 + 5);
}
