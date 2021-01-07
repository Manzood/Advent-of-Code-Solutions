#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    string s;
    vector <string> tags = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    int count = 0;
    int ans = 0;
    int passportcount = 0;
    while (getline (cin, s)) {
        if (s.size() == 0) {
            if (count >= 7) ans++;
            passportcount++;
            debug(count);
            count = 0;
        }
        bool tag = true;
        string cur = "";
        string val = "";
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == ':') {
                if (cur == "byr" || cur == "iyr" || cur == "eyr") {
                    // convert to year, then validate individual criteria
                }
                if (cur == "hgt") {
                    // check for cm or in, then check value
                }
                if (cur == "hcl") {

                }
                if (cur == "ecl") {
                    if (val == "amb" || val == "blu" || val == "brn" || val == "gry"  || val == "grn"  || val == "hzl" || val == "oth") {
                        count++;
                    }
                }
                if (cur == "pid") {
                    // converting to number, including lead zeroes
                }
                tag = false;
                cur = "";
            }
            if (s[i] == ' ') {
                tag = true;
                val = "";
                continue;
            }
            if (!tag) {
                val += s[i];
            }
            if (tag) {
                cur += s[i];
            }
        }
    }
    printf("%d\n", ans);
    printf("%d\n", passportcount + 1);
}
