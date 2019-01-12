//
// Created by 永徳泰明 on 2019-01-12.
// https://atc001.contest.atcoder.jp/tasks/dfs_a
//

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


char m[502][502] = {};
int H, W;

bool dfs(int x, int y) {
    if (x >= W || x < 0 || y >= H || y < 0) {
        return false;
    }
    if (m[y][x] == '#') {
        return false;
    }
    if (m[y][x] == 'g') {
        return true;
    }

    m[y][x] = '#';
    rep(i, 4) {
        if (dfs(x + dx[i], y + dy[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    int sx = 0, sy = 0;
    cin >> H >> W;
    rep(i, H) {
        rep(j, W) {
            char t;
            cin >> t;
            m[i][j] = t;
            if (t == 's') {
                sx = j;
                sy = i;
            }
        }
    }
    cout << (dfs(sx, sy) ? "Yes" : "No") << endl;

    return 0;
}


