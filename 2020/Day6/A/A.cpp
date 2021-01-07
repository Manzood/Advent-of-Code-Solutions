#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    string s;
    vector <bool> check(26, false);
    int ans = 0;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            for (int i = 0; i < 26; i++) {
                if (check[i] == true) ans++;
                check[i] = false;
            }
            continue;
        }
        for (int i = 0; i < (int) s.size(); i++) {
            check[s[i] - 'a'] = true;
        }
    }
    printf("%d\n", ans);
}
