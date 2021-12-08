#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

struct board {
    vector <vector <int>> grid;
    vector <int> rowsum;
    vector <int> colsum;
    vector <vector <bool>> marked;

    void init() {
        grid.resize(5, vector <int> (5));
        rowsum.resize(5, 0);
        colsum.resize(5, 0);
        marked.resize(5, vector <bool> (5, false));
    }
};

int32_t main () {
    int c;
    int n;
    scanf("%lld", &n);
    vector <int> moves;
    vector <board> a;

    while ((c = getchar()) == ',') {
        moves.push_back(n);
        scanf("%lld", &n);
    }
    moves.push_back(n);

    string s;
    while (getline (cin, s)) {
        board temp;
        temp.init();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%lld", &temp.grid[i][j]);
            }
        }

        a.push_back (temp);
    }
    a.pop_back();

    int board_picked = -1;
    int winning_move = -1;
    bool searching = true;
    vector <bool> won ((int) a.size(), false);
    for (auto x: moves) {
        for (int k = 0; k < (int) a.size() && searching; k++) {
            if (won[k]) continue;
            for (int i = 0; i < 5 && searching; i++) {
                for (int j = 0; j < 5 && searching; j++){
                    if (a[k].grid[i][j] == x) {
                        if (!a[k].marked[i][j]) {
                            a[k].marked[i][j] = true;
                            a[k].rowsum[i]++;
                            a[k].colsum[j]++;

                            if (a[k].rowsum[i] == 5 || a[k].colsum[j] == 5) {
                                board_picked = k;
                                winning_move = x;
                                won[k] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!a[board_picked].marked[i][j]) {
                sum += a[board_picked].grid[i][j];
            }
        }
    }

    debug (sum, winning_move);
    int ans = sum * winning_move;

    printf("%lld\n", ans);
}
