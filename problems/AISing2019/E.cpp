//
// Created by 永徳泰明 on 2019-01-12.
//

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
#define dump(x)  cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define fill(x, y) memset(x,y,sizeof(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 2000000000;

void readFromInputFile() {
#ifdef LOCAL
    static std::ifstream in("/Users/hoo/CLionProjects/for_atcoder/input");
    std::cin.rdbuf(in.rdbuf());
#endif
}

// 辺を表す構造体 (行き先、容量、逆辺)
struct edge {
    int to, rev;
    long cap;
};

vector<edge> G[5001 * 2];
bool used[5001 * 2] = {};

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) {to, cap, G[to].size()});
    G[to].push_back((edge) {from, 0, G[from].size() - 1});
}

// 増加パスをDFSで探す
long dfs(int v, int t, long f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            long d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流を求める
long max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof(used));
        long f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> av;
    rep(i, N) {
        int t;
        cin >> t;
        av.push_back(t);
        if (t > 0) {
            add_edge(i, i + 5000, t);
        } else {
            add_edge(i + 5000, i, t);
        }
    }
    rep(i, N) {
        int tu, tv;
        cin >> tu >> tv;
        add_edge(tu, tv, INF);
        add_edge(tv, tu, INF);
    }

    max_flow(0, N - 1);


    return 0;
}
