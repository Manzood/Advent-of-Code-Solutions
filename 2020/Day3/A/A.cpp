#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;

int main() {
    vector <string> grid;
    string s;
    while (getline (cin, s)) {
        grid.push_back(s);
    }
    int width = grid[0].size();
    int height = grid.size();
    int current = 0;
    int ans = 0;
    for (int i = 0; i < height; i++) {
        if (grid[i][current] == '#') {
            ans++;
        }
        current = (current + 3) % width;
    }
    printf("%d\n", ans);
}
