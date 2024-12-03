#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MX = 197;

void solve([[maybe_unused]] int test) {
    int ans = 0;
    map<int, int> card_copies;
    for (int i = 1; i <= MX; i++) {
        card_copies[i] = 1;
    }
    for (int i = 0; i < MX; i++) {
        int card_num;
        scanf("\nCard %lld", &card_num);
        printf("%lld: ", card_num);
        set<int> winning;
        int cur = 0;
        for (int j = 0; j < 10; j++) {
            int card;
            if (j == 0) scanf(": ");
            scanf("%lld", &card);
            printf("%lld ", card);
            winning.insert(card);
        }
        for (int j = 0; j < 25; j++) {
            int card;
            if (j == 0) scanf(" | ");
            scanf("%lld", &card);
            printf("%lld ", card);
            if (winning.count(card)) cur++;
        }
        printf("\n");
        for (int j = card_num + 1; j < card_num + cur + 1; j++) {
            card_copies[j] += card_copies[i + 1];
        }
    }
    for (int i = 1; i <= MX; i++) {
        ans += card_copies[i];
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
