#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    string s;
    int ans = 0;
    while (getline(cin, s)) {
        int lower = 0;
        int i = 0;
        while (s[i] != '-') {
            lower *= 10;
            lower += s[i] - '0';
            i++;
        }
        i++;
        int higher = 0;
        while (s[i] != ' ') {
            higher *= 10;
            higher += s[i] - '0';
            i++;
        }
        i++; char x = s[i++];
        int cnt = 0;
        while (s[++i]) {
            if (s[i] == x) cnt++;
        }
        if (cnt >= lower && cnt <= higher) ans++;
    }
    printf("%d\n", ans);
}
