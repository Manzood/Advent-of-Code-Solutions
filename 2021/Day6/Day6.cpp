#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

void iteratefish(vector <int>& days) {
    vector <int> old;
    old = days;
    for (int i = 7; i >= 0; i--) {
        days[i] = old[i+1];
    }
    days[8] = old[0];
    days[6] += old[0];
}

int32_t main () {
    // code was efficient enough to get both gold stars in one go :)
    int n;
    scanf("%lld", &n);
    vector <int> fish;
    fish.push_back (n);
    vector <int> days(9, 0);
    while (scanf(",%lld", &n)) {
        fish.push_back (n);
    }

    for (int i = 0; i < (int)fish.size(); i++) {
        days[fish[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        iteratefish(days);
    }

    int s = 0;
    for (int i = 0; i < 9; i++) {
        s += days[i];
    }

    printf("%lld\n", s);
}
