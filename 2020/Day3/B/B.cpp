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
    int final = 1;
    int ans = 0;
    for (int i = 0; i < height; i++) {
        if (grid[i][current] == '#') {
            ans++;
        }
        current = (current + 3) % width;
    }
    final *= ans;
    current = 0;
    ans = 0;
    for (int i = 0; i < height; i++) {
        if (grid[i][current] == '#') {
            ans++;
        }
        current = (current + 5) % width;
    }
    final *= ans;
    current = 0;
    ans = 0;
    for (int i = 0; i < height; i++) {
        if (grid[i][current] == '#') {
            ans++;
        }
        current = (current + 1) % width;
    }
    final *= ans;
    current = 0;
    ans = 0;
    for (int i = 0; i < height; i++) {
        if (grid[i][current] == '#') {
            ans++;
        }
        current = (current + 7) % width;
    }
    final *= ans;
    current = 0;
    ans = 0;
    for (int i = 0; i < height; i += 2) {
        if (grid[i][current] == '#') {
            ans++;
        }
        current = (current + 1) % width;
    }
    final *= ans;
    printf("%d\n", final);
}
