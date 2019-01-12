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
const int INF = 999999999;

void readFromInputFile() {
#ifdef LOCAL
    static std::ifstream in("/Users/hoo/CLionProjects/for_atcoder/input");
    std::cin.rdbuf(in.rdbuf());
#endif
}

int N, W;

int dp(int index, int weight, int m[101][10001], vector<int> v, vector<int> w) {

    if (m[index][weight] != -1) {
        return m[index][weight];
    }

    int res;

    if (index >= N) {
        res = 0;
    } else if (weight < w[index]) {
        res = dp(index + 1, weight, m, v, w);
    } else {
        res = max(
            dp(index + 1, weight, m, v, w),
            dp(index + 1, weight - w[index], m, v, w) + v[index]);
        m[index][weight] = res;
    }

    return res;
}

int main() {
    readFromInputFile();
    int m[101][10001] = {};
    fill(m, -1);
    cin >> N >> W;
    vector<int> v, w;
    rep(i, N) {
        int tv, tw;
        cin >> tv >> tw;
        v.push_back(tv);
        w.push_back(tw);
    }

    cout << dp(0, W, m, v, w) << endl;


    return 0;
}
