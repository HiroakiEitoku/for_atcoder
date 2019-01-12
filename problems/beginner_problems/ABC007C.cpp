//////////////////////////////////
// Created by 永徳泰明 on 2019-01-12.
// https://atcoder.jp/contests/abc007/tasks/abc007_3
//////////////////////////////////
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
#define dump(x)  cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define fill(x, y) memset(x,y,sizeof(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 999999999;

typedef tuple<int, int, int> t3;
int R, C;

void readFromInputfile() {
#ifdef LOCAL
    static std::ifstream in("/Users/hoo/CLionProjects/for_atcoder/input");
    std::cin.rdbuf(in.rdbuf());
#endif
}

void bfs(priority_queue<t3, std::vector<t3>, greater<> > &queue, t3 t, int m[][51]) {
    queue.pop();
    int x = get<1>(t);
    int y = get<2>(t);
    if (x < 0 || x >= C || y < 0 || y >= R || m[y][x] >= 0) {
        return;
    }
    int cost = get<0>(t);
    m[y][x] = cost;
    rep(i, 4) {
        queue.push(make_tuple(cost + 1, x + dx[i], y + dy[i]));
    }
}

int main() {
    readFromInputfile();

    int sy, sx, gy, gx;
    cin >> R >> C;
    cin >> sy >> sx >> gy >> gx;
    int m[51][51] = {};
    fill(m, -1);
    rep(i, R) {
        rep(j, C) {
            char t;
            cin >> t;
            if (t == '#') {
                m[i][j] = INF;
            }
        }
    }
    priority_queue<t3, std::vector<t3>, greater<> > queue;
    queue.push(make_tuple(0, sx - 1, sy - 1));

    while (!queue.empty()) {
        bfs(queue, queue.top(), m);
    }

//    rep(i, R) {
//        rep(j, C) {
//            if (m[i][j] != INF) {
//                cout << m[i][j];
//            } else {
//                cout << '#';
//            }
//        }
//        cout << endl;
//    }

    cout << m[gy - 1][gx - 1] << endl;

    return 0;
}
