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

int main() {
    readFromInputFile();
    int N, A, B;
    cin >> N >> A >> B;
    int x = 0, y = 0, z = 0;
    rep(i, N) {
        int t;
        cin >> t;
        if (t <= A) {
            x++;
        } else if (t > A && t <= B) {
            y++;
        } else {
            z++;
        }
    }

    cout << min(min(x, y), z) << endl;

    return 0;
}
