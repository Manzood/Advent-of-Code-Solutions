#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    string s;
    vector <bool> check(26, false);
    vector <bool> master(26, false);
    int ans = 0;
    int line = -1;
    while (getline(cin, s)) {
        line++;
        for (int i = 0; i < 26; i++) {
            check[i] = false;
        }
        if (s.size() == 0) {
            for (int i = 0; i < 26; i++) {
                if (master[i] == true) ans++;
                master[i] = false;
            }
            line = -1;
            continue;
        }
        for (int i = 0; i < (int) s.size(); i++) {
            check[s[i] - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (line == 0) master[i] = check[i];
            if (master[i] != check[i]) {
                if (check[i] == false) master[i] = false;
            }
        }
    }
    printf("%d\n", ans);
}
