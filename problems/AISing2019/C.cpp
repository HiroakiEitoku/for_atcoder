//
// Created by 永徳泰明 on 2019-01-12.
// 失敗原因:
//   1. intのオーバーフロー考慮のミス 途中で気づきsumの型を修正するも掛け算のときにオーバーフローしてることに気づかず
//   2. 再帰のスタックオーバーフロー考慮ミス(影響はなし) 最悪ケースで400*400=160000の深さになるためスタックで書くべき
//

#include "bits/stdc++.h"

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

char m[401][401] = {};
int r[401][401] = {};
int H, W;

ll wi = 0, bl = 0;

void dfs(int i1, int j1, int filln) {
    if (r[i1][j1] > 0) {
        return;
    }

    r[i1][j1] = filln;
    if (m[i1][j1] == '#') {
        bl++;
    } else {
        wi++;
    }
    rep(i, 4) {
        int ni = i1 + dy[i];
        int nj = j1 + dx[i];
        if (ni >= H || ni < 0 || nj >= W || nj < 0) {
            continue;
        }
        if (m[ni][nj] == m[i1][j1]) {
            continue;
        }

        dfs(ni, nj, filln);
    }
}

int main() {
    readFromInputFile();
    cin >> H >> W;
    rep(i, H) {
        string s;
        cin >> s;
        rep(j, W) {
            m[i][j] = s[j];
        }
    }

    fill(r, -1);
    int c = 1;
    ll sum = 0;

    rep(i, H) {
        rep(j, W) {
            wi = 0, bl = 0;
            dfs(i, j, ++c);
            sum += wi * bl;
        }
    }
//    rep(i, H) {
//        rep(j, W) {
//            if(r[i][j]==-1){
//                cout<<"#";
//            } else {
//                cout << r[i][j];
//            }
//        }
//        cout<<endl;
//    }


//    c=0;
//    rep(i, H) {
//        rep(j, W) {
//            sum += count(++c);
//        }
//    }
    cout << sum << endl;

    return 0;
}
