#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
#define dump(x)  cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define fill(x, y) memset(x,y,sizeof(x))

void readFromInputfile() {
    ifstream in("/Users/hoo/CLionProjects/for_atcoder/input");
    cin.rdbuf(in.rdbuf());
}

void readFromString() {
    string input = R"#(
            "Hello, World(1)"
)#";

    stringstream ss;
    ss << input;
    cin.rdbuf(ss.rdbuf());
}

int main() {

    return 0;
}
