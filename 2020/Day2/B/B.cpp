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
        i++; char x = s[i++]; i++;
        int cnt = 0;
        // bool printing = false;
        // if (lower == 9 && higher == 11 && x == 'c') {
            // printing = true;
            // cout << s << endl;
        // }
        while (s[++i]) {
            lower--; higher--;
            if (lower == 0) {
                if (s[i] == x) {
                    cnt++;
                    // if (printing) cout << "i = " << i << " " << "s[i] = " << s[i] << endl;
                }
            }
            if (higher == 0) {
                if (s[i] == x) {
                    cnt++;
                    // if (printing) cout << "i = " << i << " " << "s[i] = " << s[i] << endl;
                }   
            }
        }
        if (cnt == 1) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

